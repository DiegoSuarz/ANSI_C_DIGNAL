/*
 * File:   00_funcion_printf.c
 * Author: dg_su
 *
 * Created on 4 de marzo de 2023, 06:41 PM
 */


#include "xc.h"
#include <stdio.h>

int main(void) {
    
    int a = 10;
    int b = 20;
    
    printf("a = %u\nb = %u\n",a,b); //u: entero decimal sin signo
//    printf("a = %d\nb = %d\n",a,b); //d: entero decimal con signo
    
    printf("25 como decimal (d): %d\n",25);
    printf("'a' como caracter(c): %c\n",'a');
    printf("'a' como decimal (d): %d\n",'a');
    printf("2.55 como flotante (f): %1.2f\n",2.55);
    printf("6.02e23 como exponente (e): %e\n",6.02e23);
    printf("ANSI C como cadena de texto (s): %s\n","ANSI C");
    printf("0x05 como hexadecimal (x): 0x0%x",0x05);
    while(1); 
    return 0;
}
