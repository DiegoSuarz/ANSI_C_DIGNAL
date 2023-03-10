
 
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef LEDS_H
#define	LEDS_H

typedef enum
{
    LED_NONE,
    RED_LED,
    YELLOW_LED,
    GREEN_LED,
    BLUE_LED
}LED;

void LED_On(LED led);
void LED_Off(LED led);
void LED_Enable(LED led);

#endif	/* XC_HEADER_TEMPLATE_H */

