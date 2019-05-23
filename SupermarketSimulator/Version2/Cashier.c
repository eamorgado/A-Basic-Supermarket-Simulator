/*******************************************************************************
| Program: An Implementation of a Supermarket Cashier                          |
| Last Updated: 22/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Cashier.h"
#include "Queue.h"
#include "PriorityQueue.h"

Cashier* openCashier(int id,int tp){
    Cashier* C=(Cashier*)malloc(sizeof(Cashier));
    if(!C){
        printf("Error opening cashier %d",id);
        exit(0);
    }
    if(tp==0){
        TYPE(C)=QUEUE;
        Q(C) = createQueue();
    }
    else{
        TYPE(C)=PQUEUE;
        PQ(C) = newPriorityQueue();
    }
    
    ID(C)=id;
    CLIENTS(C)=PRODUCTS(C)=WAIT_TIME(C)=NEXT_SERVICE(C)=0;
    SCAN_POWER(C)=(rand()%(5-1+1))+1;
    return C;
}
void delayServiceTo(int available_at,Cashier* C){
    NEXT_SERVICE(C)=available_at;
}
void clientCheckin(Client* client,int priority,Cashier* C){
    if(TYPE(C)==PQUEUE)
        addElem(client,priority,PQ(C));
    else
        enqueue(client,Q(C));
}
void clientCheckout(Cashier* C){
    if(TYPE(C)==PQUEUE)
        dequeuePQ(PQ(C));
    //removes client and updates total_clients
    else
        dequeue(Q(C));
}
void processedProduct(int items,Cashier* C){
    PRODUCTS(C)+=items;
}
void timeIncrease(int time_for_service,Cashier* C){
    WAIT_TIME(C)+=time_for_service;
}
int isCashierEmpty(Cashier* C){
    if(TYPE(C)==PQUEUE)
        return isPQueueEmpty(PQ(C));
    return isQueueEmpty(Q(C));
}
void printCashier(Cashier* C){
    printf("Caixa %d: ",ID(C));
    if(TYPE(C)==QUEUE)
        printQueue(Q(C));
    else
        printPriorityQueue(PQ(C));
}

void serviceClient(int step,Cashier* cashier){
    /**
     * Verifies if the first client inn this cashier has been serviced, if so,
     *      updates its info, #clients, #products
     */

    Client* client = ((TYPE(cashier)==QUEUE)? getFirst(Q(cashier)) : serviceElement(PQ(cashier)));
    int wait = step - NEXT_SERVICE(cashier);
    int products_scanned = wait * SCAN_POWER(cashier);

    if(products_scanned >= ITEMS(client)){
        NEXT_SERVICE(cashier)= step+1;
        CLIENTS(cashier)++;
        PRODUCTS(cashier)+=ITEMS(client);
        WAIT_TIME(cashier)+= (step-CHECKIN(client));
        clientCheckout(cashier);
        printf("--->Client serviced in cashier %d\n",ID(cashier));
    }
}

void closeCashier(Cashier* C){
    if(TYPE(C)==QUEUE) freeQueue(Q(C));
    else freePQueue(PQ(C));
    free(C);
}