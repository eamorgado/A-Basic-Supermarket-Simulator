/*******************************************************************************
| Program: An Implementation of a C Queue                                      |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
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
Client* getFirst(Queue* Q){
    return CLIENT(FIRST(Q));
}
Client* getLast(Queue* Q){
    return CLIENT(LAST(Q));    
}
int size(Queue* Q){
    return SIZE(Q);
}
void enqueue(Client* client, Queue* Q){
    QueueElem* q_e=(QueueElem*)malloc(sizeof(QueueElem));
    if(!q_e){
        printf("Error enqueuing client with %d items at time %d\n",ITEMS(client),CHECKIN(client));
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
    CLIENT(q_e)=client;
    SIZE(Q)++;
}
void dequeue(Queue* Q){
    QueueElem* aux=FIRST(Q);
    FIRST(Q)=NEXT(FIRST(Q));
    free(aux);
    SIZE(Q)--;
}
void printQueue(Queue* Q){
    if(isQueueEmpty(Q)==1){
        printf("<<\n");
        return;
    }
    QueueElem* curr=FIRST(Q);
    printf("<");
    while(NEXT(curr)!=NULL){
        printf("[%d:%d]<",ITEMS(CLIENT(curr)),CHECKIN(CLIENT(curr)));
        curr=NEXT(curr); 
    }
    printf("[%d:%d]<\n",ITEMS(CLIENT(curr)),CHECKIN(CLIENT(curr)));       
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
        free(CLIENT(curr));
        free(curr);
        NEXT(prev)=NULL;
        return;
    }
    freeQueueElem(curr,NEXT(curr));
}

