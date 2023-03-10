/*
 * File:   00_Field_Bits.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 08:28 PM
 */

#include "xc.h"

struct byteBits
{
    union
    {
        char registro;
        struct
        {
            unsigned a : 1;
            unsigned b : 1;
            unsigned c : 2;
            unsigned d : 1;
            unsigned e : 3;
        }bits;
    };
}reg;

int main(void) {
    
    //acceder bit a bit
    reg.bits.a = 1;
    reg.bits.b = 0;
    reg.bits.c = 0b10;
    reg.bits.d = 0x0;
    reg.bits.e = 7;
    
    reg.registro = 0x0A; //acceder a todo el registro
    
    while(1);
    return 0;
}
