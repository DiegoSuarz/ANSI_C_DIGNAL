/*
 * File:   OperadoresAritmeticos.c
 * Author: dg_su
 *
 * Created on 4 de marzo de 2023, 06:56 PM
 */


#include "xc.h"
#include <stdio.h>

void ejemplo1(void);
void ejemplo2(void);

int main(void) {
//    ejemplo1();
////    ejemplo2();
    ejemplo3();
    while(1);
    
    return 0;
}

void ejemplo1(void){
    
    int _base = 10;
    int altura = 5;
    
    int area_triangulo = (_base * altura) / 2;
}

void ejemplo2(void){
    
#define PI 3.14159
    float perimetro, radio;
    radio = 1.0;
    perimetro = 2* PI * radio;
    printf("El perimetro es: %1.2f\n",perimetro);
}

void ejemplo3(void){
    
     int horas, minutos, segundos, total;
     horas = 2;
     minutos = 4;
     segundos = 25;
     
     total = horas * 3600 + minutos * 60 + segundos;
     printf("Han transcurrido: %u segundos\n",total);
}