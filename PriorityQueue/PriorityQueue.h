/*******************************************************************************
| Program: A Definition of a C Priority Queue of Integers                      |
| Last Updated: 17/5/2019                                                  FCUP|
*******************************************************************************/
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
void addElem(int,int,PriorityQueue*); //enqueue in queue of priority int

void raiseUrgency(PriorityQueue*); //Increases priority of first element in Normal
int serviceElement(PriorityQueue*); //Gets element with highest priority
void printPriorityQueue(PriorityQueue*);

#endif
