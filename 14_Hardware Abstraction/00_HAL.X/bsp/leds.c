#include "leds.h"
#include <xc.h>

#define RED_LED_LAT     LATBbits.LATB4
#define YELLOW_LED_LAT  LATCbits.LATC3
#define GREEN_LED_LAT   LATCbits.LATC4
#define BLUE_LED_LAT    LATCbits.LATC5

#define RED_LED_TRIS    TRISBbits.TRISB4
#define YELLOW_LED_TRIS TRISCbits.TRISC3
#define GREEN_LED_TRIS  TRISCbits.TRISC4
#define BLUE_LED_TRIS   TRISCbits.TRISC5

#define INPUT   1
#define OUTPUT  0

#define LED_ON  0  //enciende con 0v
#define LED_OFF 1   

void LED_Enable(LED led) //configurar el pin como salida digital
{
     switch(led)
    {
        case RED_LED:
            RED_LED_TRIS     = OUTPUT;
            break;
        case YELLOW_LED:
            YELLOW_LED_TRIS  = OUTPUT;
            break;
        case GREEN_LED:
            GREEN_LED_TRIS   = OUTPUT;
            break;
        case BLUE_LED:
            BLUE_LED_TRIS    = OUTPUT;
            break;
         case LED_NONE:
             break;
            
    }
}

void LED_On(LED led)
{
    switch(led)
    {
        case RED_LED:
            RED_LED_LAT     = LED_ON;
            break;
        case YELLOW_LED:
            YELLOW_LED_LAT  = LED_ON;
            break;
        case GREEN_LED:
            GREEN_LED_LAT   = LED_ON;
            break;
        case BLUE_LED:
            BLUE_LED_LAT    = LED_ON;
            break;
        case LED_NONE:
             break;
               
    }
}

void LED_Off(LED led)
{
    switch(led)
    {
        case RED_LED:
            RED_LED_LAT     = LED_OFF;
            break;
        case YELLOW_LED:
            YELLOW_LED_LAT  = LED_OFF;
            break;
        case GREEN_LED:
            GREEN_LED_LAT   = LED_OFF;
            break;
        case BLUE_LED:
            BLUE_LED_LAT    = LED_OFF;
            break;
        case LED_NONE:
             break;
               
    }
}
    