/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 13 de marzo de 2023, 05:30 PM
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define QUEUE_LENGHT    5
uint8_t bufferQueue[QUEUE_LENGHT];

bool    isFull;     //la cola esta llena
bool    isEmpty;    //la cola esta vacia

uint8_t *head; //puntero de lectura
uint8_t *tail; //puntero de escritura

void buffer_add(uint8_t *buf, uint8_t data)
{
    if(isFull)  //Si el buffer esta lleno no agregamos nada
        return;
    
    isEmpty = false;
    *tail = data;
    
    if(tail != (buf + QUEUE_LENGHT - 1) && ((tail+1) != head))
    {
        tail++;
    }
    else if((tail == (buf + QUEUE_LENGHT-1)) && (head != buf))
    {
        tail = buf;
    }
    else
    {
        isFull = true;
    }
}

uint8_t buffer_read(uint8_t *buf)
{
    uint8_t data = 0;
    
    if(head == tail)
    {
        isEmpty = true;
        printf("Queue is empty\n");
        return;
    }
    data = *head;
    
    if(head == (buf + QUEUE_LENGHT-1))
    {
        head = buf;
    }
    else
    {
        head++;
        if(isFull)
        {
            isFull = false;
            tail = (tail== (buf + QUEUE_LENGHT-1)) ? buf : ++tail;
        }
    }
    return data;
}

int main(void) {
    
    //al inicio head y tail apuntan al primer elemento de la cola 
    head = bufferQueue; //al puntar a un arreglo siempre apunta a la primera direccion de memoria sin la necesidad de usa "&"
    tail = bufferQueue;
    
    isFull = false;
    isEmpty = true;
    
    printf("%d\n", buffer_read(&bufferQueue));
    buffer_add(&bufferQueue,3);
    buffer_add(&bufferQueue,4);
    buffer_add(&bufferQueue,6);
    buffer_add(&bufferQueue,7);
    buffer_add(&bufferQueue,8); //inteto fallido por que la cola esta llena
    printf("%d\n",buffer_read(&bufferQueue)); //al leer se libera un estacio de la cola
    buffer_add(&bufferQueue,8); //ahora si se puede asignar este valor a la cola
//    printf("%d\n",buffer_read(&bufferQueue));
//    printf("%d\n",buffer_read(&bufferQueue));
//    printf("%d\n",buffer_read(&bufferQueue));
    
    
    while(1);   
    return 0;
}
