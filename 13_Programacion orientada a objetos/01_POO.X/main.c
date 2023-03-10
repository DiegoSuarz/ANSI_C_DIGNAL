/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 8 de marzo de 2023, 03:16 PM
 */


#include "xc.h"
#include <stdio.h>
#include "perro.h"

int main(void) {
   ObtenerTipoDeLadrido();
    guardarId(55);
    printf("El id de perro es: %d\n",obtenerId());
    while(1);
    return 0;
}
