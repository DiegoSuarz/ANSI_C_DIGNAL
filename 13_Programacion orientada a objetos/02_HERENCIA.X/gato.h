/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "animal.h"

static void maullar();
void gato_comer();
void gato_guardadId(int id);
int gato_obtenerId();
void guardarTipoMaullido(char *tipoMaullido);
char* obtenerTipoMaullido();
#endif	/* XC_HEADER_TEMPLATE_H */

