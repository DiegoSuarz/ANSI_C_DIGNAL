
#include "perro.h"
#include <stdio.h>


typedef struct
{
    animal_t animal;
    char *tipoLadrido;
}perro_t;
  
perro_t perro;

static void ladrar()
{
    printf("El perro esta ladrando\n");
    
}

void perro_comer()
{
    printf("El perro esta comiendo\n");
}

void perro_guardadId(int id)
{
    perro.animal.id = id;
}

int perro_obtenerId()
{
    return perro.animal.id;
}

void guardarTipoLadrido(char *tipoLadrido)
{
    perro.tipoLadrido =  tipoLadrido;
}
char* obtenerTipoLadrido()
{
    ladrar();
    return perro.tipoLadrido;
}