#include "Client.h"
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
void addElem(Client*,int,PriorityQueue*);
Client* dequeuePQ(PriorityQueue*);

int isPQueueEmpty(PriorityQueue*);
void raiseUrgency(PriorityQueue*);
Client* serviceElement(PriorityQueue*);
void printPriorityQueue(PriorityQueue*);
void freePQueue(PriorityQueue*);

#endif
