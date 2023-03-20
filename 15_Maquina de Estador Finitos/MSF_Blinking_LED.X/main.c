/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 10 de marzo de 2023, 05:12 PM
 */

#define _XTAL_FREQ 8000000UL
#define FCY (_XTAL_FREQ / 2)

#include "xc.h"
#include <stdint.h>
#include <libpic30.h>

#define LED LATAbits.LATA0
#define ON 1
#define OFF 0
typedef enum
{
    LED_OFF_STATE,
    LED_ON_STATE,
    IDLE_STATE
}LED_STATE_G;

LED_STATE_G led_state = LED_OFF_STATE;
uint8_t blink_ctr = 3;

void FSM_blinking_led()
{
    switch(led_state)
    {
        case LED_OFF_STATE:
            __delay_ms(1000);
            LED = OFF;
            led_state = LED_ON_STATE;
            break;
        
        case LED_ON_STATE:
            __delay_ms(1000);
            blink_ctr--;
            LED = ON;
            
            if(blink_ctr > 0)
                led_state = LED_OFF_STATE;
            else
                led_state = IDLE_STATE;
            break;
            
            //led_state = ((blink_ctr > 0) ? LED_OFF_STATE : IDLE_STATE);
    
        case IDLE_STATE:
            break;
            
        default:
            break;
    }
}


int main(void) {
    
    TRISAbits.TRISA0 = 1;
    LATAbits.LATA0 = 0;
    
    while(1)
    {
        FSM_blinking_led();
    }
    return 0;
}
