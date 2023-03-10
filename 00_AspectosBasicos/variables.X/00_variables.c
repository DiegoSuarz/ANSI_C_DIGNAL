/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 3 de marzo de 2023, 06:12 PM
 */

#define _XTAL_FREQ 8000000UL
#define TCY (_XTAL_FREQ/2)
#include <xc.h>
#include <stdio.h>
#include <libpic30.h>



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

//constante simbolica (es una etiqueta que representa valores fijos que nunca cambian en el transcurso del programa)
#define DELAY_OFFSET    32
#define DELAY_VALUE     350

/*exiten 2 tipos de constantes simbolicas: 
 *  Etiquetas de sustitución de texto
                #define ALPHA 5.35
 *  Variables constantes (evita que el valor de una varible cambie)
                const float alpha = 3.35
*/


int main(void) {
    
//    char x=127;
//    signed char x=127;
    signed char x=-127;
    while(1){
        if(x_valor < DELAY_OFFSET){
        __delay_ms(DELAY_VALUE);
        }
    } 
    
    return 0;
} 
