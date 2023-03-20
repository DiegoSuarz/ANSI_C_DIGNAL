/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 14 de marzo de 2023, 04:34 PM
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct node
{
    uint8_t data;
    struct node *next;
}node_t;

node_t  tmp[4];
uint8_t valuesToSort[4] = {10, 3, 5, 1};
node_t  *listHead = NULL;

void sortedInsert( node_t *node ) //insertar y ordenar en la lista
{
    uint8_t data = node->data;
    uint8_t atHead = 1;
    node_t *insertPoint = listHead;
    node_t *prevPoint   = NULL;
    node->next = NULL;
    
    while(insertPoint != NULL)
    {
        if(insertPoint->data > data) //¿dato de punto de entrada es mayor que dato que viene como parametro?
        {
            break;  //si, espacio encontrado
        }
        prevPoint   = insertPoint;   //punto previo ahora es el punto de entrada
        insertPoint = insertPoint->next; //punto de entrada ahora es el siguiente nodo
        atHead = 0;
    }
    if(atHead == 1)
    {
        node->next = listHead;
        listHead = node;
        return;
    }
    else
    {
        //el siguiente elemento del nodo ahora es el siguiente del punto previo
        node->next = prevPoint->next; 
    }
    prevPoint->next = node; //nodo se coloca despues del punto previo
}
int main() {
    
    int i;  
    for(i = 0; i < strlen(valuesToSort); i++)
    {
        tmp[i].data = valuesToSort[i];
        sortedInsert(&tmp[i]);
    }
    
    node_t *pToPrintTmp = listHead;
//    printf("%d\n",pToPrintTmp->data);
//    printf("%d\n",pToPrintTmp->next->data);
//    printf("%d\n",pToPrintTmp->next->next->data);
    
    
    while(pToPrintTmp != NULL)
    {
        printf("%d\n", pToPrintTmp->data);
        pToPrintTmp =  pToPrintTmp->next;
    }
    
    while(1);
    return 1;
}

