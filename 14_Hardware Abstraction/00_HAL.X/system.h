

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef SYSTEM_H
#define	SYSTEM_H

#include "io_mapping.h"
#include "bsp/leds.h"
#include "bsp/buttons.h"

typedef enum
{
    SYSTEM_STATE_POLLING,
    SYSTEM_STATE_INTERRUPT
}SYSTEM_STATE;

void SYSTEM_Initialize(SYSTEM_STATE state);

#endif	/* XC_HEADER_TEMPLATE_H */

