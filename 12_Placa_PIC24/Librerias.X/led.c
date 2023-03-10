#include "led.h"
void leds_enable()
{
     /*configuracion de entradas y salidas digitales*/
    //salidas
    TRISBbits.TRISB4 = 0; //Red /error
    TRISCbits.TRISC3 = 0; //yellow /data 
    TRISCbits.TRISC4 = 0; //GreenI/Conn
    TRISCbits.TRISC5 = 0; //Blue /wifi

}

void leds_on()
{
    //encender los 4 leds encendidos
    LATBbits.LATB4 = 0;
    LATCbits.LATC3 = 0;
    LATCbits.LATC4 = 0;
    LATCbits.LATC5 = 0;
}

void leds_off()
{
    
    //todos los led apagados
    LATBbits.LATB4 = 1;
    LATCbits.LATC3 = 1;
    LATCbits.LATC4 = 1;
    LATCbits.LATC5 = 1;
}