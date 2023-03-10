/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 9 de marzo de 2023, 03:16 PM
 */


#include "system.h"
#include "app_led_switch.h"

/*La abstracción de hardware funciona como una interfaz entre el software y hardware; permite que las aplicaciones
sean independientes del hardware, es decir que no acceden directamente al hardware sino que lo hacen a una
capa abstracta.*/


int main(void) {
    
    SYSTEM_Initialize(SYSTEM_STATE_POLLING);
    while(1)
    {
        app_led_switch();
    }
    
    return 0;
}
