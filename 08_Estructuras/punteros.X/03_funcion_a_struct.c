/*
 * File:   03_funcion_a_struct.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 04:04 PM
 */


#include "xc.h"
#include <stdio.h>

typedef struct
{
    float re;   //parte real
    float im;   //parte imaginaria
}complex_t;

void display(complex_t x)
{
    printf("(%1.1f + j%1.1f\n",x.re, x.im);
}

int main(void) {
    
    complex_t a = {1.25, 2.50};
    complex_t b = {5.25, 1.50};
   
    display(a);
    display(b);
    
    while(1);
    return 0;
}

