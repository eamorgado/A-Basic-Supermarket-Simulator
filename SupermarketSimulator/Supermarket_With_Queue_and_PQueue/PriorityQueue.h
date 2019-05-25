/*******************************************************************************
| Program: A Definition of a C Priority Queue                                  |
| Last Updated: 22/5/2019                                                  FCUP|
*******************************************************************************/
#include "Client.h"
#include "Queue.h"
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define URGENT(PQ) ((PQ)->urgent)
#define NORMAL(PQ) ((PQ)->normal)


/*------------------------------------------------------------------------------
|                           PQueue Definition                                  |
------------------------------------------------------------------------------*/
typedef struct priorityqueue{
    Queue* urgent;
    Queue* normal;
}PriorityQueue;


/*------------------------------------------------------------------------------
|                           PQueue Functions                                   |
------------------------------------------------------------------------------*/
PriorityQueue* newPriorityQueue();

void addElem(Client*,int,PriorityQueue*); //enqueue in queue of priority int
Client* dequeuePQ(PriorityQueue*); //Removes first element with highest priority
void raiseUrgency(PriorityQueue*);//Increases priority of first element in Normal
Client* serviceElement(PriorityQueue*); //Gets element with highest priority

int isPQueueEmpty(PriorityQueue*);

void printPriorityQueue(PriorityQueue*);

void freePQueue(PriorityQueue*);

#endif
