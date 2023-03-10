/*
 * File:   02_Sentencia_switch.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 03:49 PM
 */


#include "xc.h"
#include <stdio.h>

void ejemplo1(void);
void ejemplo2(void);

int main(void) {
    
//    ejemplo1();
    ejemplo2();
    
    while(1);
   
    return 0;
}

void ejemplo1(void){
     int dia = 3;
    
    switch(dia)
    {
        case 1: printf("Lunes\n"); break;
        case 2: printf("Martes\n"); break;
        case 3: printf("Miercoles\n");break;
        case 4: printf("Jueves\n");break;
        case 5: printf("Viernes\n");break;
        case 6: printf("Sabado\n");break;
        case 7: printf("Domingo\n");break;
        default: printf("Dian invalido\n");break;
    }
}

void ejemplo2(void){
     int ble_channel = 5;
    
    switch(ble_channel)
    {
        case 0 ... 36: printf("El canal %d es de datos\n",ble_channel); break;
        case 37 ... 39: printf("Martes\n"); break;
        default: printf("Canal incorrecto\n");break;
    }
}