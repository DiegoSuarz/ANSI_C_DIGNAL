/*
 * File:   00_punteros.c
 * Author: dg_su
 *
 * Created on 6 de marzo de 2023, 06:35 PM
 */


#include "xc.h"
#include <stdio.h>

int x = 5;
int *p;

int main(void) {
 
    p = &x;
    printf("La varibale x esta ubicada en la direccion 0x%X\n",&x);
    printf("El valor de la variable x es: %d\n",x);
    printf("El puntero p esta ubicado en la direccion 0x%X\n",&p);
    printf("El valor que tiene la direccion apuntada por p es: %d\n",*p);
    
    *p = 10;
    printf("En nuevo valor de la variable x es: %d\n",x);
    
    while(1);
    return 0;
}
