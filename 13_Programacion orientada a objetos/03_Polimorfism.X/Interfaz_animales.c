#include "animal.h"
#include "perro.h"
#include "gato.h"

const animal_t animal[] = 
{
    {
        .comer                  = perro_comer,
        .guardarId              = perro_guardadId,
        .obtenerId              = perro_obtenerId,
        .emitir_sonido.ladrar   = ladrar
    },
    {
        .comer      = gato_comer,
        .guardarId  = gato_guardadId,
        .obtenerId = gato_obtenerId,
        .emitir_sonido.maullar = maullar
    }
};