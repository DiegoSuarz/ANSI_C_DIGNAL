/*
 * File:   00_Enumeraciones.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 08:56 PM
 */


#include "xc.h"
#include <stdio.h>

enum weekday{
    SUN = 1,
    MON,
    TUE,
    WED,
    THR,
    FRI,
    SAT
   
}DAYS_WEEK;



int main(void) {
    unsigned char dia = 2;
    if(dia == SUN){
        printf("el dia es Domingo");
    }
    
    else if(dia == MON){
        printf("el dia es lunes");
    }
    
    else if(dia == TUE){
        printf("el dia es martes");
    }
    
    else if(dia == WED){
        printf("el dia es miercoles");
    }
    
    else if(dia == THR){
        printf("el dia es jueves");
    }
    
    else if(dia == FRI){
        printf("el dia es viernes");
    }
    
    else if(dia == SAT){
        printf("el dia es sabado");
    }
    
    while(1);
    return 0;
}
