/*
 * File:   04_Estructuras_anidadas.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 08:18 PM
 */

#include "xc.h"

typedef struct
{
    struct
    {
        char _base;
        char altura;
    }triangulo;
    
    struct
    {
        char lado_a;
        char lado_b;
    }cuadrado;
    
    struct
    {
        char base_a;
        char base_b;
        char altura;
    }trapecio;
}figuras_t;

int main(void) {
    
    figuras_t fig;
    
    fig.cuadrado.lado_a = 1;
    fig.cuadrado.lado_b = 1;
    
    fig.trapecio.base_a = 2;
    fig.trapecio.base_b = 3;
    fig.trapecio.altura = 5;
    
    fig.triangulo._base = 3;
    fig.triangulo.altura =6;
    
    while(1);
    return 0;
}
