/*
 * File:   05_MQTT_CONNACK.c
 * Author: dg_su
 *
 * Created on 7 de marzo de 2023, 08:41 PM
 */


#include "xc.h"

typedef enum{
    CONN_ACCEPTED,
    CONN_REFUSED_PROTOCOL_VERSION,
    CONN_REFUSED_ID_REJECTED,
    CONN_REFUSED_SERVICE_UNAVA,
    CONN_REFUSED_USERNAME_PASS,
    CONN_REFUSED_NOT_AUTH
            
}returnCodes;


typedef union
{
    unsigned char all;
    
    struct
    {
        unsigned reservedBits       :4;
        unsigned controlPacketType  :4;
    };
}mqttHeaderFlags_t;


typedef struct
{
    //fixed header
    mqttHeaderFlags_t   fixedHeader;
    unsigned char       remainingLenght;
    
    //variable header
    struct
    {
        union
        {
            unsigned char all;
            struct
            {
                unsigned sp         :1;
                unsigned reserved   :7;
            }flagsBits;
        }ackFlags;
        returnCodes returnCode;
    }variableHeader;
    
    
}mqttConnackPacket_t;
    
void proccesConnack(mqttConnackPacket_t connackPkt)
{
    if(connackPkt.fixedHeader.controlPacketType == 2)
    {
        
    }
}
int main(void) {
    
    char codeRensponse;
    
    mqttConnackPacket_t mqttConnackpkt;
    
//    mqttConnackpkt.fixedHeader.controlPacketType = 0b0010;
//    mqttConnackpkt.fixedHeader.reservedBits      = 0b0000; 
    mqttConnackpkt.fixedHeader.all = 0b00100000;
    
    mqttConnackpkt.variableHeader.ackFlags.flagsBits.sp = 1;
    mqttConnackpkt.variableHeader.ackFlags.flagsBits.reserved = 0;
    
    if(codeRensponse = CONN_ACCEPTED)
    {
        //..
    }
    
    while(1);
    return 0;
}
