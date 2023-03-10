/*
 * File:   00_union.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 04:24 PM
 */


#include "xc.h"

/*la union es un tipo de dato que puede agrupar variables que ocupan la misma posicion
de memoria pero no al mismo tiempo (se reescriben), el tamaño reservado en RAM sera equivalente 
al tipo de dato de mayor tamaño de la union*/

typedef union
{
    char _base;
    char altura;
}triangulo_t;

int main(void) {
    triangulo_t t;
    
    t._base = 5;
    t.altura = 6;
    
    while(1);
    return 0;
}
