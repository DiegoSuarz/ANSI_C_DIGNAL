/*
 * File:   00_Estructuras.c
 * Author: dg_su
 *
 * Created on 6 de marzo de 2023, 07:10 PM
 */


#include "xc.h"

////forma sin typedef
//struct complex
//{
//    float re;
//    float im;
//};
//
//struct complex x;

/////////////////////////////////////////////////////
//forma con typedef
typedef struct
{
    float re;   //parte real
    float im;   //parte imaginaria
}complex;

int main(void) {
    
    complex x = {1.25, 2.50};
    
    x.re = 2.2;
    x.im = 1.1;
    
    while(1);
    return 0;
}
