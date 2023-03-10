
/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef struct
{
    int id;
    unsigned char nombre[10];
    int edad;
}perro_t;

void ladrar();
void comer();

#endif	/* XC_HEADER_TEMPLATE_H */

