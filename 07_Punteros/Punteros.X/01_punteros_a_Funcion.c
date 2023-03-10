/*
 * File:   01_punteros_a_Funcion.c
 * Author: dg_su
 *
 * Created on 6 de marzo de 2023, 06:56 PM
 */


#include "xc.h"
#include <stdio.h>

void (*ptrFn)(void); //declaracion del puntero a funcion

void funcion1(){
    printf("Esta es la funcion 1\n");
}

void funcion2(){
     printf("Esta es la funcion 2\n");
}

void funcion3(){
     printf("Esta es la funcion 3\n");
}
int main(void) {
    
    ptrFn = funcion1;
    ptrFn(); //llamado a la funcion a la que apunte ptrFn
    while(1);
    return 0;
}
