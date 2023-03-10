/*
 * File:   02_arreglo_a_struct.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 04:02 PM
 */


#include "xc.h"

typedef struct
{
    float re; //parte real
    float im; //parte imaginaria
}complex_t;

complex_t a[3] = {{1.2, 2.5},{3.9, 6.5}, {7.1, 8.4}}; //arreglos a estructuras


int main(void) {
    
       
    a[0].re = 1.25;
    a[0].im = 2.50;
    
    a[1].re = 5.59;
    a[1].im = 9.54;
    
    a[2].re = 7.25;
    a[2].im = 3.74;
    
    while(1);
    return 0;
}
