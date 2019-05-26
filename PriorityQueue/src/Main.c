#include <stdio.h>
#include "PriorityQueue.h"

int main(){
    PriorityQueue* pq = newPriorityQueue();
    int val;
    printPriorityQueue(pq);
    printf("\n");
    addElem(10,0,pq);
    printPriorityQueue(pq);
    printf("\n");
    raiseUrgency(pq);
    printPriorityQueue(pq);
    printf("\n");
    val = serviceElement(pq);
    printPriorityQueue(pq);
    printf("\n");    
}