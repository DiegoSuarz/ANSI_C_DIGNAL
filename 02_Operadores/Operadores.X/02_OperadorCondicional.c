/*
 * File:   02_OperadorCondicional.c
 * Author: dg_su
 *
 * Created on 4 de marzo de 2023, 07:46 PM
 */


#include "xc.h"
#include <stdbool.h>
int main(void) {
    
    
    bool aprobado;
    char calificacion = 5;
    
//    if(calificacion >= 6)
//        aprobado = true;
//    else
//        aprobado = false;
    
    //operador condicional
    aprobado = (calificacion >= 6) ? true : false;
    
    while(1);
            
    return 0;
}
