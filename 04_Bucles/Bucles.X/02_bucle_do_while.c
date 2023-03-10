/*
 * File:   02_bucle_do_while.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 04:36 PM
 */


#include "xc.h"
#include <stdio.h>

int main(void) {
    
    int i = 0;
    
    do
    {
        printf("El valor de i es: %d\n",i++);
    
    }while(i < 5);
    
    while(1);
    
    
    return 0;
}
