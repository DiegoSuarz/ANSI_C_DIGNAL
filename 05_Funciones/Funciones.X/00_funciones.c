/*
 * File:   00_funciones.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 05:32 PM
 */


#include "xc.h"
#include <stdio.h>

//funcion sin parametro y sin retorno de valor
void maximum(void);
   
//funcion sin parametros con retorno de valor
int maximum2();

//funcion con parametros y sin retorno de valor
void maximum3(int x, int y);

//funcion con parametros y con retorno de valor
int maximum4(int , int );


int main(void) {
    
    //llamado a funcion sin parametros y sin retorno de valor
    maximum();
    
    //llamado a funcion sin parametros y con retorno de valor
    int a = maximum2();
    printf("El valor mas grande es: %d\n",a);
    
    //llamado a funcion con parametros y sin retorno de valor
    maximum3(4,8);
    
    //llamado a funcion sin parametros y con retorno de valor
    
    printf("El valor mas grande es: %d\n",maximum4(200,60));
    return 0;
}


void maximum(){
    int x = 5, y = 6;
    printf("El valor mas grande es: %d\n", (x > y) ? x : y);
}

//funcion sin parametros con retorno de valor
int maximum2(){
    int x = 2, y = 9;
    return ((x > y) ? x : y);
}

//funcion con parametros y sin retorno de valor
void maximum3(int x, int y){
    printf("El valor mas grande es: %d\n", (x > y) ? x : y);
}

//funcion con parametros y con retorno de valor
int maximum4(int x, int y){
    return (x > y) ? x : y;
}