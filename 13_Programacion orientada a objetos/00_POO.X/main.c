/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 8 de marzo de 2023, 12:57 PM
 */


#include "xc.h"
#include <stdio.h>
#include "perro.h"
#include "gato.h"

int main(void) {
    
    perro_t perro = {55, "firulais",5};
    gato_t gato = {56,"pelusa",6};
    
    ladrar();
    comer();
    
    maullar();
    gato_comer();
    
    printf("El id del perro es: %d\n",perro.id);
    printf("El nombre del perro es: %s\n",perro.nombre);
    printf("La edad del perro es: %d\n",perro.edad);
    
    printf("El id del gato es: %d\n",gato.id);
    printf("El nombre del gato es: %s\n",gato.nombre);
    printf("La edad del gato es: %d\n",gato.edad);
    while(1);
    return 0;
}
