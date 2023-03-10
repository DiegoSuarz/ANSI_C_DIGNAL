/*
 * File:   00_Variables_Automatic_Static.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 06:15 PM
 */


#include "xc.h"
#include <stdio.h>

//variables automaticas se almacenan en el stack y se eliminan cuando se dejan de usar, solo se aplica
//en variables locales
//El stack es una pila zona de memoria en RAM que se reserva donde entran datos temporales, no se queda
//en ram permaentemente


/*
 una variable estatica (static) las variables globales siempre son estaticas,  en las funciones locales
 estas variables siempre tienen un espacio de memoria reservada al salio o entrar de la funcion
 
 esta variable solo se genera una vez en todo el programa
 
 
 */

void foo(){
    
    int x = 0;
    static int sx = 0; //variable estatica
    
    x += 5;
    sx += 5;
    
    printf("x = %d, se = %d\n",x,sx);
}

int main(void) {
    
    int i;
    for (i=0; i<10; ++i)
        foo();
    
    while(1);
    return 0;
}



