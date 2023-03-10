/*
 * File:   01_Static_Sensor.c
 * Author: dg_su
 *
 * Created on 5 de marzo de 2023, 06:19 PM
 */


#include "xc.h"
#include <stdio.h>

void sendValue( char val)
{
    printf("Temperatura: %d\n",val);
}
/*Adquisicion de dato del sensor x*/
void sensorAdq()
{
    static char temperatura = 20;      //lectura del sensor y almacena en memoria ram el valor anterior
    temperatura++;              //simulacion de la variacion de temperatura
    sendValue(temperatura);
}
int main(void) {
    for (int i=0;i<5;++i)
        sensorAdq();
    return 0;
}
