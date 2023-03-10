/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef BUTTONS_H
#define	BUTTONS_H

#include <stdbool.h>

typedef enum
{
    BUTTON_NONE,
    BUTTON_SW0,
    BUTTON_SW1
}BUTTON;

bool BUTTON_IsPressed(BUTTON button);
void BUTTON_Enable(BUTTON button);
#endif	/* XC_HEADER_TEMPLATE_H */

