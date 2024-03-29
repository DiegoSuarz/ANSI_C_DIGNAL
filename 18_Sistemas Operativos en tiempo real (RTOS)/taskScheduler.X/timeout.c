
#ifdef __XC
#include <xc.h>
#endif
#include <stdio.h>
#include "timeout.h"
#include "tmr1.h"


uint32_t dummyHandler(void *payload) {return 0;};
void startTimerAtHead(void);
INLINE void enqueueCallback(timerStruct_t* timer);
INLINE void setTimerDuration(uint32_t duration);
INLINE uint32_t makeAbsolute(uint32_t timeout);
INLINE uint32_t rebaseList(void);
INLINE void printList(void);

timerStruct_t *listHead = NULL;
timerStruct_t * volatile executeQueueHead = NULL;

timerStruct_t dummy;
timerStruct_t dummy_exec = {dummyHandler};
volatile uint32_t absoluteTimeofLastTimeout = 0;
volatile uint32_t lastTimerLoad = 0;
volatile bool  isRunning = false;

/**
\ingroup doc_driver_timeout_code
Call this function to check if there are any timers running or waiting to be called
@param none
\returns true if there are no more timers lined up
\returns false if there are still timers that are running or waiting to be called

*/
bool timeout_hasPendingTimeouts(void)
{
    return (listHead == NULL);
}

/**
\ingroup doc_driver_timeout_code
Call this function to check if there are events that are being executed or waiting to be executed
@param none
\returns true if there are no more events lined up
\returns false if there are still events that are running or waiting to be called
*/
bool timeout_hasPendingCallbacks(void)
{
    return (executeQueueHead == NULL);
}

/**
\ingroup doc_driver_timeout_code
This function disables all the timers without deleting them from the list. Timers can be restarted by calling startTimerAtHead
@param none
*/
void stopTimeouts(void)
{
    IEC0bits.T1IE = 0;
    absoluteTimeofLastTimeout = 0;
    lastTimerLoad = 0;
    isRunning = false;
}

/**
\ingroup doc_driver_timeout_code
This sets the number of ticks the timer will run for.
@param duration - number of timer ticks
*/
inline void setTimerDuration(uint32_t duration)
{
    lastTimerLoad = TMR1_Period16BitGet() - duration;

    TMR1_Counter16BitSet(0);

    IFS0bits.T1IF = 0;
    TMR1_Counter16BitSet(lastTimerLoad);
}

/**
\ingroup doc_driver_timeout_code
This function takes a number of ticks and returns the total number of timer ticks since the last timeout occurred or the timer module was started.
@param duration - number of timer ticks of a specific timer
\returns timeout - number of timer ticks since the last timeout occurred
*/ 
inline uint32_t makeAbsolute(uint32_t timeout)
{
    timeout += absoluteTimeofLastTimeout;
    if (isRunning) {
        uint32_t timerVal = TMR1_Counter16BitGet();
        if (timerVal < lastTimerLoad) // Timer has wrapped while we were busy
        {
            timerVal = TMR1_Period16BitGet();
        }
        timeout += timerVal - lastTimerLoad;
    }
    return timeout;
}

/**
\ingroup doc_driver_timeout_code
This function gets the number of ticks remaining before a specific timer runs out.
@param *timer - the specific timer in question
\returns number of ticks remaining before a specific timer runs out.
*/
uint32_t timeout_getTimeRemaining(timerStruct_t *timer)
{
    return timer->absoluteTime - makeAbsolute(0);
}

/**
\ingroup doc_driver_timeout_code
This function adjusts the time base so that the timer can never wrap
@param none
\returns number of timer ticks since the last timeout occurred
*/
inline uint32_t rebaseList(void)
{
    timerStruct_t *basePoint = listHead;
    uint32_t baseTime = makeAbsolute(0);
    while(basePoint != NULL)
    {
        basePoint->absoluteTime -= baseTime;
        basePoint = basePoint->next;
    }
    absoluteTimeofLastTimeout -= baseTime;
    return baseTime;
}

/**
\ingroup doc_driver_timeout_code
This function prints the times for each of the timer for each timer on the queue.
@param none
*/
inline void printList(void)
{
    timerStruct_t *basePoint = listHead;
    while(basePoint != NULL)
    {
        printf("%ld -> ", (uint32_t)basePoint->absoluteTime);
        basePoint = basePoint->next;
    }
    printf("NULL\n");
}

/**
\ingroup doc_driver_timeout_code
This function figures out where the specific timer will be placed on the queue. 
@param timer - instance of a timer being inserted to the queue
\returns true if the inserted at the head of the queue
\returns false in not at the head of the queue
*/
bool sortedInsert(timerStruct_t *timer)
{    
    uint32_t timerAbsoluteTime = timer->absoluteTime;
    uint8_t  atHead = 1;    
    timerStruct_t *insertPoint = listHead;
    timerStruct_t *prevPoint = NULL;
    timer->next = NULL;

    if(timerAbsoluteTime < absoluteTimeofLastTimeout)
    {
        timerAbsoluteTime += TMR1_Period16BitGet() - rebaseList() + 1;
        timer->absoluteTime = timerAbsoluteTime;
    }
    
    while(insertPoint != NULL)
    {
        if(insertPoint->absoluteTime > timerAbsoluteTime)
        {
            break; // found the spot
        }
        prevPoint = insertPoint;
        insertPoint = insertPoint->next;
        atHead = 0;
    }
    
    if(atHead == 1) // the front of the list. Checking the uint8_t saves 7 instructions
    {
        setTimerDuration(TMR1_Period16BitGet());
        IFS0bits.T1IF = 0;

        timer->next = (listHead==&dummy)?dummy.next: listHead;
        listHead = timer;
        return true;
    }
    else // middle of the list
    {
        timer->next = prevPoint->next;
    }
    
    prevPoint->next = timer;
    return false;
}

/**
\ingroup doc_driver_timeout_code
This function starts the timer queue from the beginning.
@param none
*/
void startTimerAtHead(void)
{
    // NOTE: listHead must NOT equal NULL at this point.

    IEC0bits.T1IE = 0;

    if(listHead==NULL) // no timeouts left
    {
        stopTimeouts();
        return;
    }

    uint32_t period = listHead->absoluteTime - absoluteTimeofLastTimeout;

    // Timer is too far, insert dummy and schedule timer after the dummy
    if (period > TMR1_Period16BitGet())
    {
        dummy.absoluteTime = absoluteTimeofLastTimeout + TMR1_Period16BitGet();
        dummy.next = listHead;
        listHead = &dummy;
        period = TMR1_Period16BitGet();
    }

    setTimerDuration(period);

    IEC0bits.T1IE = 1;
    isRunning = true;
}

/**
\ingroup doc_driver_timeout_code
This function cancels and removes all timers in the queue
@param none
*/
void timeout_flushAll(void)
{
    stopTimeouts();

    while (listHead != NULL)
        timeout_delete(listHead);

    while (executeQueueHead != NULL)
        timeout_delete(executeQueueHead);

}

/**
\ingroup doc_driver_timeout_code
This function looks for a specific timer instance and removes it from the queue.
@param *list - the pointer that points to the timer instance at the head of the queue
@param *timer - timer instance to be removed 
\returns true if the timer was found and successfully removed from the list.
\returns false if the operation was not successful.
*/

bool __attribute__((optimize(0))) timeout_deleteHelper(timerStruct_t * volatile *list, timerStruct_t *timer)
{
    bool retVal = false; 
    if (*list == NULL)
        return retVal;

    // Guard in case we get interrupted, we cannot safely compare/search and get interrupted
    IEC0bits.T1IE = 0;

    // Special case, the head is the one we are deleting
    if (timer == *list)
    {
        *list = (*list)->next;       // Delete the head
        retVal = true;
        startTimerAtHead();        // Start the new timer at the head
    } else 
    {   // More than one timer in the list, search the list.  
        timerStruct_t *findTimer = *list;
        timerStruct_t *prevTimer = NULL;
        while(findTimer != NULL)
        {
            if(findTimer == timer)
            {
                prevTimer->next = findTimer->next;
                retVal = true;
                break;
            }
            prevTimer = findTimer;
            findTimer = findTimer->next;
        } 
        IEC0bits.T1IE = 1;
    }

    return retVal;
}

/**
\ingroup doc_driver_timeout_code
This function cancels and removes a running timer
@param *timer - timer instance to be removed
*/
void timeout_delete(timerStruct_t *timer)
{
    if (!timeout_deleteHelper(&listHead, timer))
    {
        timeout_deleteHelper(&executeQueueHead, timer);
    }

    timer->next = NULL;
}

/**
\ingroup doc_driver_timeout_code
This function moves a specific timer from the active list to the list of timers which are expired and needs their callbacks called in callNextCallback
@param *timer - timer instance whose callback have to be called.
*/
inline void enqueueCallback(timerStruct_t* timer)
{
    timerStruct_t  *tmp;
    if( timer == &dummy )
    {
        timer = &dummy_exec;// keeping a separate copy for dummy in execution queue to avoid the modification of next from the timer list. 
    }
    timer->next = NULL;
    
    // Special case for empty list
    if (executeQueueHead == NULL)
    {
        executeQueueHead = timer;
        return;
    }    
    
    // Find the end of the list and insert the next expired timer at the back of the queue
    tmp = executeQueueHead;
    while(tmp->next != NULL)
        tmp = tmp->next;
    
    tmp->next = timer;
}

/**
\ingroup doc_driver_timeout_code
This function checks the list of expired timers and calls the first one in the 
list if the list is not empty. It also reschedules the timer if the callback
returned a value greater than 0.It is recommended this is called from the main superloop 
(while(1)) in your code but by design this can also be called from the timer ISR. If you 
wish callbacks to happen from the ISR context you can call this as the last action in 
timeout_isr instead. 
@param none
*/
inline void timeout_callNextCallback(void)
{
    if (executeQueueHead == NULL)
        return;

    bool tempIE = (IEC0bits.T1IE == 1?1:0);
    IEC0bits.T1IE = 0;

    timerStruct_t *callBackTimer = executeQueueHead;
    
    // Done, remove from list
    executeQueueHead = executeQueueHead->next;
    // Mark the timer as not in use
    callBackTimer->next = NULL;

    if(tempIE)
    {
        IEC0bits.T1IE = 1;
    }
    
    //uint32_t reschedule = callBackTimer->callbackPtr(callBackTimer->payload);
    uint32_t reschedule = callBackTimer->callbackPtr();
    // Do we have to reschedule it? If yes then add delta to absolute for reschedule
    if(reschedule)
    {
        timeout_create(callBackTimer, reschedule);
    } 
}

/**
\ingroup doc_driver_timeout_code
This function sets the timeout ISR handler as the the interrupt handler for the timer.
@param *timer - timer instance whose callback have to be called.
*/
void timeout_initialize(void)
{
    TMR1_SetInterruptHandler(timeout_isr);
}

/**
\ingroup doc_driver_timeout_code
This function adds to the queue and starts the timer. If the timer was already active/running it will be replaced by this 
and the old (active) timer will be removed/cancelled first.
@param *timer - timer instance to be created and added to the list
@param timeout - number of timer ticks before this timer expires.
*/
void timeout_create(timerStruct_t *timer, uint32_t timeout)
{
    // If this timer is already active, replace it
    timeout_delete(timer);

    IEC0bits.T1IE = 0;

    timer->absoluteTime = makeAbsolute(timeout);
    
    // We only have to start the timer at head if the insert was at the head
    if(sortedInsert(timer))
    {
        startTimerAtHead();
    } else {
        if (isRunning)
            IEC0bits.T1IE = 1;
    }
}

/**
\ingroup doc_driver_timeout_code
This function is the handler that is called whenever the Timer peripheral interrupts.
The handler counts the time elapsed and calls the next timer in the queue.
It assumes that the callback is completed before the next timer tick.
@param none
*/
void timeout_isr(void)
{
    
    timerStruct_t *next = listHead->next;
    absoluteTimeofLastTimeout = listHead->absoluteTime;
    lastTimerLoad = 0;
    
    if (listHead != &dummy) {
        enqueueCallback(listHead);
    }

    listHead = next;
    
    startTimerAtHead();    
}

/**
\ingroup doc_driver_timeout_code
This function is specifically used in Stopwatch/cycle counter mode. It will start
a timer with maximum timeout of up to the maximum range of the timer divided by 2. 
@param *timer - timer instance that will be used in stopwatch mode. 
*/
void timeout_startTimer(timerStruct_t *timer)
{
    uint32_t i = -1;
    timeout_create(timer, i>>1);
}

/**
\ingroup doc_driver_timeout_code
This function is specifically used in Stopwatch/cycle counter mode. It will stop
the running timer and return the number of ticks it counted. 
@param *timer - timer instance that is used in stopwatch mode. 
\returns number of ticks counted by the timer.
*/
uint32_t timeout_stopTimer(timerStruct_t *timer)
{
    uint32_t  now = makeAbsolute(0); // Do this as fast as possible for accuracy
    uint32_t i = -1;
    i>>=1;
    
    timeout_delete(timer);

    uint32_t  diff = timer->absoluteTime - now;
    
    // This calculates the (max range)/2 minus (remaining time) which = elapsed time
    return (i - diff);
}
