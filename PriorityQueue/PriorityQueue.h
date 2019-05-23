#include "Queue.h"
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define URGENT(PQ) ((PQ)->urgent)
#define NORMAL(PQ) ((PQ)->normal)


typedef struct priorityqueue{
    Queue* urgent;
    Queue* normal;
}PriorityQueue;

PriorityQueue* newPriorityQueue();
void addElem(int,int,PriorityQueue*);

void raiseUrgency(PriorityQueue*);
int serviceElement(PriorityQueue*);
void printPriorityQueue(PriorityQueue*);

#endif
