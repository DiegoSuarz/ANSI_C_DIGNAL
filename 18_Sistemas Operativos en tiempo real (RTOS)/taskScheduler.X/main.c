#include "system.h"
#include "timeout.h"
#include <xc.h>

#define BLUE_LED_TASK_INTERVAL   timeout_mSecToTicks(800L)
#define YELLOW_LED_TASK_INTERVAL timeout_mSecToTicks(100L)
#define RED_LED_TASK_INTERVAL    timeout_mSecToTicks(200L)

uint32_t blueLed_task();
uint32_t redLed_task();
uint32_t yellowLed_task();

timerStruct_t blueLedTaskTimer   = {blueLed_task};
timerStruct_t redLedTaskTimer    = {redLed_task};
timerStruct_t yellowLedTaskTimer = {yellowLed_task};

int main() {
    SYSTEM_Initialize();
    INTCON2bits.GIE = 1;
    
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB7 = 0;
    
    timeout_create(&blueLedTaskTimer,  BLUE_LED_TASK_INTERVAL);
    timeout_create(&redLedTaskTimer,   RED_LED_TASK_INTERVAL);
    timeout_create(&yellowLedTaskTimer,YELLOW_LED_TASK_INTERVAL);
    
    while(1)
    {
        timeout_callNextCallback();
    }
    return 1;
}

uint32_t blueLed_task()
{
    LATBbits.LATB6 ^= 1;              //pin para el analizador
    LATCbits.LATC5 = !LATCbits.LATC5; //toggle led azul
    return BLUE_LED_TASK_INTERVAL;
}
uint32_t redLed_task()
{
    LATBbits.LATB7 ^= 1;                //pin para el analizador
    LATBbits.LATB4 = !LATBbits.LATB4;   //toggle led rojo
    return RED_LED_TASK_INTERVAL;
}
uint32_t yellowLed_task()
{
    LATBbits.LATB5 ^= 1;                //pin para el analizador
    LATCbits.LATC3 = !LATCbits.LATC3;   //toggle led amarillo
    return YELLOW_LED_TASK_INTERVAL;
}
