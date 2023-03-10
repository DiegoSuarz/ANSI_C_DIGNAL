/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 8 de marzo de 2023, 03:47 PM
 */


#include "xc.h"
#include <stdio.h>
#include "perro.h"
#include "gato.h"


int main(void) {
    
    perro_guardadId(55);
    guardarTipoLadrido("agudo");
    
    gato_guardadId(56);
    guardarTipoMaullido("grave");
    
    printf("El id del perro es: %d", perro_obtenerId());
    printf("El tipo de ladrido es: %s\n",obtenerTipoLadrido());
    
     printf("El id del gato es: %d", gato_obtenerId());
    printf("El tipo de gato es: %s\n",obtenerTipoMaullido());
    
    while(1);
    
    return 0;
}
