/*******************************************************************************
| Program: A Definition of a C Queue                                           |
| Last Updated: 17/5/2019                                                  FCUP|
********************************************************************************
|   Representation:                                                            |
*******************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define DATA(QE) ((QE)->data)
#define NEXT(QE) ((QE)->next)

#define FIRST(Q) ((Q)->first)
#define LAST(Q) ((Q)->last)
#define SIZE(Q) ((Q)->size)


/*------------------------------------------------------------------------------
|                           Queue Element                                      |
------------------------------------------------------------------------------*/
typedef struct queuelement{
    int data;
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
int getFirst(Queue*);
int getLast(Queue*);
int size(Queue*);
void enqueue(int,Queue*);
int dequeue(Queue*);
void printQueue(Queue*);

/*------------------------------Free------------------------------------------*/
void freeQueue(Queue*);
void freeQueueElem(QueueElem*,QueueElem*);

#endif