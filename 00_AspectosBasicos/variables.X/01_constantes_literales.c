/*
 * File:   03_constantes_literales.c
 * Author: dg_su
 *
 * Created on 4 de marzo de 2023, 05:52 PM
 */

//literales constants
int a = 0x5; //= 0x05;
int b = 0b111; //=0b00000111;
float x = 0.5; //
char s = 'a'; //formato ascii
char i = '\n'; //secuencia de escape new line (carater de control)

//Calificadores literales
long int x_valor = 10000 * 7; //dan 70000  singed max 32767, habra desbordamiento
long int y_valor = 10000L * 7L; //al usar calificadores literales permite reservar el espacio
                                //de memoria optimo para el resultado de la operacion
long int z_valor = 10000L * 7;  //solo es necesario que una de los numero tenga el calificador 
#include "xc.h"

int main(void) {
    while(1);
    return 0;
}
