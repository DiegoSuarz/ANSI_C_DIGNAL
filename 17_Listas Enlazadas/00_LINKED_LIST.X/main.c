/*
 * File:   main.c
 * Author: dg_su
 *
 * Created on 14 de marzo de 2023, 03:57 PM
 */


#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node head;
struct node middle;
struct node last;

int main(void) {
    
    struct node *tmp = &head;
       
    head.data = 10;
    middle.data = 20;
    last.data = 30;
    
    head.next = &middle;
    middle.next = &last;
    last.next = NULL;
    
    while(tmp != NULL)
    {
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    
    //o sin utilizar el while se hace de la siguiente manera:
    printf("%d\n",tmp->data);
    printf("%d\n",tmp->next->data);
    printf("%d\n",tmp->next->next->data);
       
    while(1);
    return 0;
}
