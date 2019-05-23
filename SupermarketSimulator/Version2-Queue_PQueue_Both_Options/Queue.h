/*******************************************************************************
| Program: A Definition of a C Queue                                           |
| Last Updated: 15/5/2019                                                  FCUP|
********************************************************************************
|   Representation:                                                            |
*******************************************************************************/
#include "Client.h"
#ifndef QUEUE_H
#define QUEUE_H

/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define CLIENT(QE) ((QE)->client)
#define NEXT(QE) ((QE)->next)

#define FIRST(Q) ((Q)->first)
#define LAST(Q) ((Q)->last)
#define SIZE(Q) ((Q)->size)


/*------------------------------------------------------------------------------
|                           Queue Element                                      |
------------------------------------------------------------------------------*/
typedef struct queuelement{
    Client* client;
    struct queuelement* next;
}QueueElem;


/*------------------------------------------------------------------------------
|                           Queue Definition                                   |
------------------------------------------------------------------------------*/
typedef struct queue{
    QueueElem* first;
    QueueElem* last;
    int size;
}Queue;


/*------------------------------------------------------------------------------
|                           Queue Functions                                    |
------------------------------------------------------------------------------*/
Queue* createQueue();
int isQueueEmpty(Queue*);
Client* getFirst(Queue*);
Client* getLast(Queue*);
int size(Queue*);
void enqueue(Client*,Queue*);
Client* dequeue(Queue*);
void printQueue(Queue*);

/*------------------------------Free------------------------------------------*/
void freeQueue(Queue*);
void freeQueueElem(QueueElem*,QueueElem*);

#endif
