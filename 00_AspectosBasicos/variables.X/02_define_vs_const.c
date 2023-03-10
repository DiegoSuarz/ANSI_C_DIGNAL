/*
 * File:   01_define_vs_const.c
 * Author: dg_su
 *
 * Created on 4 de marzo de 2023, 05:51 PM
 */

/*exiten 2 tipos de constantes simbolicas: 
 *  Etiquetas de sustitución de texto
                #define ALPHA 5.35
 *  Variables constantes (evita que el valor de una varible cambie)
                const float alpha = 3.35
*/
#include "xc.h"

#define CONSTANTE1 10 //sustitucion de texto (no ocupa espacio en memoria)
const int CONSTANTE2 = 15;  //variable constante se almacena en memoria de programa (ocupa espacio en memoria)

int main(void) {

    int var1 = CONSTANTE1;
    int var2 = CONSTANTE2;
    while(1);
 
    return 0;
}
