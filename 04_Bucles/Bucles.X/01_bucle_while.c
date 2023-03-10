/*
 * File:   01_bucle_while.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 04:31 PM
 */


#include "xc.h"
#include <stdio.h>

void ejemplo1(void);
void ejemplo2(void);
void ejemplo3(void);
void ejemplo4(void);

int main(void) {
    
//   ejemplo1(); 
//   ejemplo2();  //break
//   ejemplo3();  //contunue 1 
   ejemplo4();  //contunue 1 
   while(1);
    
    return 0;
}

void ejemplo1(void){
     int i= 0;
    while(i < 5)
    {
        printf("El valor de i es: %d\n",i++);
    }
}

void ejemplo2(void){
     int i= 0;
    while(i < 10)
    {
        i++;
        if(i==5) break;  //cuando llega a la iteraccion 5 rompe el bucle
        printf("El valor de i es: %d\n",i);
    }
}

void ejemplo3(void){
     int i= 0;
    while(i < 6)
    {
        i++;
        if(i==2) continue;   //la iteraccion 2 no se imprime, ya que regresa a evaluar la sentencia
        printf("El valor de i es: %d\n",i);
    }
}

void ejemplo4(void){
    
    unsigned char convertToACII[10]={0,1,2,3,4,5,6,7,8,9};
    unsigned char ASCII_char[10]={'0','1','2','3','4','5','6','7','8','9'};
    
    unsigned char numberToConvert=8;
    int i;
    for(i=0;0<10;i++){
        if(numberToConvert != convertToACII[i]) continue;
        printf("La representacion en texto de %u es %c\n",numberToConvert,ASCII_char[i]);
        break;
    }
}