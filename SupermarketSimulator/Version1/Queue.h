/*******************************************************************************
| Program: An Definition of a C Queue                                          |
| Last Updated: 15/5/2019      FCUP                                            |
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
int isEmpty(Queue*);
int getFirst(Queue*);
int getLast(Queue*);
void enqueue(int,Queue*);
int dequeue(Queue*);
void printQueue(Queue*);

/*------------------------------Free------------------------------------------*/
void freeQueue(Queue*);
void freeQueueElem(QueueElem*,QueueElem*);

#endif
