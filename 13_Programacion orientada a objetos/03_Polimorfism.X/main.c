/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 8 de marzo de 2023, 05:55 PM
 */


#include "xc.h"
#include "animal.h"
#include "gato.h"
#include "perro.h"
#include <stdio.h>

int main(void) {
  
    //funciones polomorficas
    animal[PERRO].comer();
    animal[PERRO].guardarId(55);
    animal[PERRO].emitir_sonido.ladrar();
    
    animal[GATO].comer();
    animal[GATO].guardarId(56);
    animal[GATO].emitir_sonido.maullar();
    
    
    //funciones de cada subclase (herencia)
    guardarTipoLadrido("grave");
    guardarTipoMaullido("agudo");
    
    printf("\nEl id del perro es: %d\n", animal[PERRO].obtenerId());
    printf("El tipo de ladrido es: %s\n", obtenerTipoLadrido());
    
    printf("\nEl id del gato es: %d\n", animal[GATO].obtenerId());
    printf("El tipo de maullido es: %s\n", obtenerTipoMaullido());
    
    while(1);
    
    return 0;
}
