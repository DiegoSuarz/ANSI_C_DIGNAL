/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 8 de marzo de 2023, 11:55 AM
 */


#include "xc.h"
#include "configuracion.h"
#include "led.h"
#include "buttons.h"


int main(void) {
    
    buttos_enable();
    leds_enable(); 
    
     
    while(1){
        if(PORTAbits.RA7 == 0 || PORTAbits.RA10)
        {
            //encender los 4 leds encendidos
            leds_on();
        }
        else //si no esta presionado ningun botos
        {
            //todos los led apagados
            leds_off();
        }
    }
    
    return 0;
}
