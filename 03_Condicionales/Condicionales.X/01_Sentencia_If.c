/*
 * File:   01_Sentencia_If.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 03:44 PM
 */


#include "xc.h"
#include <stdio.h>
int main(void) {
    
    int temperatura = 40;
    
    if(temperatura > 35)
    {
        printf("Alerta\n");
    }
    else
        printf("Temperatura estable\n");
    
    while(1);
        
    return 0;
}
