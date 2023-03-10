#include "buttons.h"

void buttos_enable(){
     /*configuracion de entradas y salidas digitales*/
    //entradas
    TRISAbits.TRISA7 = 1;
    TRISAbits.TRISA10 = 1;
    
    
    //habilitacion pull-up
    IOCPUAbits.IOCPUA7 = 1; //pull-up habilitado para RA7
    IOCPUAbits.IOCPUA10 = 1; //pull-up habilitado para RA10
}
