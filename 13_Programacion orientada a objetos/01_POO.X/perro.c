
#include "perro.h"
#include <stdio.h>

typedef struct
{
    int id;
    unsigned char nombre[10];
    int edad;
}perro_t;

//el objeto perro solo se puede utilizar en este archivo .c
perro_t perro;

//funcion privada solo funciona en este archivo (funcion privada)
static void ladrar()
{
    printf("El perro esta ladrando\n");
}

void comer()
{
    printf("El perro esta ladrando\n");
}

void guardarId(int id)
{
    perro.id = id;
}

int obtenerId()
{
    return perro.id;
}


int ObtenerTipoDeLadrido()
{
    ladrar();
    return 1;
}