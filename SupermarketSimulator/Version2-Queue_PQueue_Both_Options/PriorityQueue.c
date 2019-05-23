#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Queue.h"
#include "PriorityQueue.h"

PriorityQueue* newPriorityQueue(){
    PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    URGENT(PQ) = createQueue();
    NORMAL(PQ) = createQueue();
    return PQ;
}
void addElem(Client* client,int priority,PriorityQueue* PQ){
    Queue* queue;
    if(priority==0)//Normal
        queue = NORMAL(PQ);
    else//Urgent
        queue = URGENT(PQ);
    enqueue(client,queue);    
}
void raiseUrgency(PriorityQueue* PQ){
    enqueue(dequeue(NORMAL(PQ)),URGENT(PQ));
}
int isPQueueEmpty(PriorityQueue* PQ){
    if(isQueueEmpty(URGENT(PQ))==1 && isQueueEmpty(NORMAL(PQ))==1)
        return 1;
    return 0;
}
Client* dequeuePQ(PriorityQueue* PQ){
    Queue* queue = URGENT(PQ);
    if(isQueueEmpty(URGENT(PQ)))
        queue = NORMAL(PQ);
    return dequeue(queue);
}
Client* serviceElement(PriorityQueue* PQ){
    Queue* queue;
    if(isQueueEmpty(URGENT(PQ)))
        queue = NORMAL(PQ);
    else
        queue = URGENT(PQ);
    return getFirst(queue);
}
void printPriorityQueue(PriorityQueue* PQ){
    //printf("Priority Queue:\n");
    printf("\n\tUrgent <");
    printQueue(URGENT(PQ));
    printf("\tNormal <");
    printQueue(NORMAL(PQ));
}
void freePQueue(PriorityQueue* PQ){
    freeQueue(NORMAL(PQ));
    freeQueue(URGENT(PQ));
    free(PQ);
}  