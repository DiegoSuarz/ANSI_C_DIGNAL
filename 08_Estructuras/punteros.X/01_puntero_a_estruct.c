/*
 * File:   01_puntero_a_estruct.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 03:48 PM
 */

#include "xc.h"

typedef struct
{
    float re; //parte real
    float im; //parte imaginaria
}complex_t;

complex_t x;  
complex_t *p;  //puntero a estructura
complex_t a[3] = {{1.2, 2.5},{3.9, 6.5}, {7.1, 8.4}}; //arreglos a estructuras


int main(void) {
    
    p = &x; //p apunta a x
    p->re = 2;
    p->im = 5;
    
    a[0].re = 1.25;
    a[0].im = 2.50;
    
    while(1);
    return 0;
}
