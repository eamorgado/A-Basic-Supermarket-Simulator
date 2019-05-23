#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "PriorityQueue.h"

PriorityQueue* newPriorityQueue(){
    PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    URGENT(PQ) = createQueue();
    NORMAL(PQ) = createQueue();
    return PQ;
}
void addElem(int data,int priority,PriorityQueue* PQ){
    Queue* queue;
    if(priority==0)//Normal
        queue = NORMAL(PQ);
    else//Urgent
        queue = URGENT(PQ);
    enqueue(data,queue);    
}
void raiseUrgency(PriorityQueue* PQ){
    enqueue(dequeue(NORMAL(PQ)),URGENT(PQ));
}
int serviceElement(PriorityQueue* PQ){
    Queue* queue;
    if(isQueueEmpty(URGENT(PQ)))
        queue = NORMAL(PQ);
    else
        queue = URGENT(PQ);
    return dequeue(queue);
}
void printPriorityQueue(PriorityQueue* PQ){
    printf("Priority Queue:\n");
    printf(">Urgent---");
    printQueue(URGENT(PQ));
    printf(">Normal---");
    printQueue(NORMAL(PQ));
}