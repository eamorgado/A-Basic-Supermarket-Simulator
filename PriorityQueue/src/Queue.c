/*******************************************************************************
| Program: An Implementation of a C Queue                                      |
| Last Updated: 17/5/2019                                                  FCUP|
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
int isQueueEmpty(Queue* Q){
    return (FIRST(Q)==NULL? 1 : 0);
}
int getFirst(Queue* Q){
    return DATA(FIRST(Q));
}
int getLast(Queue* Q){
    return DATA(LAST(Q));    
}
int size(Queue* Q){
    return SIZE(Q);
}
void enqueue(int data, Queue* Q){
    QueueElem* q_e=(QueueElem*)malloc(sizeof(QueueElem));
    if(!q_e){
        printf("Error enqueuing %d\n",data);
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
    DATA(q_e)=data;
    SIZE(Q)++;
}
int dequeue(Queue* Q){
    QueueElem* aux=FIRST(Q);
    int data = DATA(aux);
    FIRST(Q)=NEXT(FIRST(Q));
    free(aux);
    SIZE(Q)--;
    return data;
}
void printQueue(Queue* Q){
    if(isQueueEmpty(Q)==1){
        printf("<<\n");
        return;
    }
    QueueElem* curr=FIRST(Q);
    printf("<");
    while(NEXT(curr)!=NULL){
        printf("%d<",DATA(curr));
        curr=NEXT(curr); 
    }
    printf("%d<\n",DATA(curr));       
}

void freeQueue(Queue* Q){
    if(isQueueEmpty(Q)){
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

