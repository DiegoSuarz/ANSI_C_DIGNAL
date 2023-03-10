/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

typedef enum
{
    PERRO,
    GATO
}TIPO_ANIMAL;

typedef union
{
    void(*ladrar) (void);
    void(*maullar)(void);
}emitir_sonido_t;

typedef struct //clase abstracta
{
    int id;
    unsigned char nombre[10];
    int edad;
    void (*comer)(void);
    void (*guardarId)(int id);
    int (*obtenerId)(void);
    emitir_sonido_t emitir_sonido;
}animal_t;

extern const animal_t animal[];

#endif	/* XC_HEADER_TEMPLATE_H */

