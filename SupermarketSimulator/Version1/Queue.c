/*******************************************************************************
| Program: An Implementation of a C Queue                                      |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*------------------------------------------------------------------------------
|                           Functions Implementation                           |
------------------------------------------------------------------------------*/
Queue* createQueue(){
   /*
    * Allocate the space in memory for the queue, initializes pointers 
    * Returns the queue
    */
   Queue* Q=(Queue*)malloc(sizeof(Queue));
   if(!Q){
       printf("Error creating Queue\n");
       exit(0);
   }
   FIRST(Q)=NULL;
   LAST(Q)=NULL;
   SIZE(Q)=0;
   return Q;
}
int isEmpty(Queue* Q){
    return FIRST(Q)==NULL;
}
int getFirst(Queue* Q){
    return DATA(FIRST(Q));
}
int getLast(Queue* Q){
    return DATA(LAST(Q));    
}
void enqueue(int elem, Queue* Q){
    QueueElem* q_e=(QueueElem*)malloc(sizeof(QueueElem));
    if(!q_e){
        printf("Error enqueuing element %d\n",elem);
        freeQueue(Q);
        exit(0);
    }
    if(FIRST(Q)==NULL) //Queue is empty
        FIRST(Q)=LAST(Q)=q_e;
    else{
        NEXT(LAST(Q))=q_e;
        LAST(Q)=q_e;
    }
    NEXT(q_e)=NULL;
    DATA(q_e)=elem;
    SIZE(Q)++;
}
int dequeue(Queue* Q){
    int data=getFirst(Q);
    QueueElem* aux=FIRST(Q);
    FIRST(Q)=NEXT(FIRST(Q));
    free(aux);
    SIZE(Q)--;
    return data;
}
void printQueue(Queue* Q){
    if(isEmpty(Q)){
        printf("<<\n");
        return;
    }
    QueueElem* curr=FIRST(Q);
    int i=0;
    printf("<");
    while(NEXT(curr)!=NULL){
        printf("[%d:%d]<",i,DATA(curr));
        i++;
        curr=NEXT(curr); 
    }
    printf("[%d:%d]<\n",(++i),DATA(curr));
}
void freeQueue(Queue* Q){
    if(isEmpty(Q)){
        free(Q);
        return;
    }
    freeQueueElem(NULL,FIRST(Q));
    free(Q);
    return;
}
void freeQueueElem(QueueElem* prev,QueueElem*curr){
    if(NEXT(curr)==NULL){
        free(curr);
        NEXT(prev)=NULL;
        return;
    }
    freeQueueElem(curr,NEXT(curr));
}

