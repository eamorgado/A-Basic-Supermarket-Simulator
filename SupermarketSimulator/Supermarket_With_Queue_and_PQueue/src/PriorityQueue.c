/*******************************************************************************
| Program: An Implementation of a C Queue                                      |
| Last Updated: 22/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Queue.h"
#include "PriorityQueue.h"


PriorityQueue* newPriorityQueue(){
    //Initializer of PQ returns pointer to priority queue
    PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    URGENT(PQ) = createQueue();
    NORMAL(PQ) = createQueue();
    return PQ;
}

void addElem(Client* client,int priority,PriorityQueue* PQ){
    //Adds elements to queue of given priority
    Queue* queue;
    if(priority==0)//Normal
        queue = NORMAL(PQ);
    else//Urgent
        queue = URGENT(PQ);
    enqueue(client,queue);    
}
void raiseUrgency(PriorityQueue* PQ){
    //adds the first element in Normal to Urgent
    enqueue(dequeue(NORMAL(PQ)),URGENT(PQ));
}
Client* serviceElement(PriorityQueue* PQ){
    //Gets the first element with highest available priority
    Queue* queue;
    if(isQueueEmpty(URGENT(PQ)))
        queue = NORMAL(PQ);
    else
        queue = URGENT(PQ);
    return getFirst(queue);
}
Client* dequeuePQ(PriorityQueue* PQ){
    //Removes the first element with highest available priority
    Queue* queue = URGENT(PQ);
    if(isQueueEmpty(URGENT(PQ)))
        queue = NORMAL(PQ);
    return dequeue(queue);
}

int isPQueueEmpty(PriorityQueue* PQ){
    if(isQueueEmpty(URGENT(PQ))==1 && isQueueEmpty(NORMAL(PQ))==1)
        return 1;
    return 0;
}

void printPriorityQueue(PriorityQueue* PQ){
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