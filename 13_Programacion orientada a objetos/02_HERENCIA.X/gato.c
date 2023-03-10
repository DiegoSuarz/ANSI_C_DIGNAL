
#include "gato.h"
#include <stdio.h>


typedef struct
{
    animal_t animal;
    char *tipoMaullido;
}gato_t; // calse hija gato
gato_t gato;

static void maullar()
{
    printf("El gato esta maullando\n");
    
}

void gato_comer()
{
    printf("El gato esta comiendo\n");
}

void gato_guardadId(int id)
{
    gato.animal.id = id;
}

int gato_obtenerId()
{
    return gato.animal.id;
}

void guardarTipoMaullido(char *tipoMaullido)
{
    gato.tipoMaullido =  tipoMaullido;
}
char* obtenerTipoMaullido()
{
    maullar();
    return gato.tipoMaullido;
}
