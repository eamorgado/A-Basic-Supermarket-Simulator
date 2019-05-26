/*******************************************************************************
| Program: An Implementation of a Supermarket Cashier                          |
| Last Updated: 23/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Cashier.h"
#include "Queue.h"
#include "PriorityQueue.h"


Cashier* openCashier(int id,int tp,int scan_power){
    /**
     * Given an id number and the type of cashier, creates the cashier and
     *  initializes all its variables.
     * If int tp == 0 then the cashier will be represented by a queue, otherwise
     *  it will be represented by a priority queue with 2 priorities
     * Returns the cashier
    **/
    Cashier* C=(Cashier*)malloc(sizeof(Cashier));
    if(!C){
        printf("Error opening cashier %d",id);
        exit(0);
    }

    TYPE(C) = (tp==0 ? QUEUE : PQUEUE);
    if(TYPE(C)==QUEUE) Q(C) = createQueue();
    else PQ(C) = newPriorityQueue();
    
    ID(C)=id;
    CLIENTS(C)=PRODUCTS(C)=WAIT_TIME(C)=NEXT_SERVICE(C)=0;
    SCAN_POWER(C)=scan_power;
    return C;
}


void delayServiceTo(int available_at,Cashier* C){
    NEXT_SERVICE(C)=available_at;
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


void clientCheckin(Client* client,int priority,Cashier* C){
    if(TYPE(C)==PQUEUE)
        addElem(client,priority,PQ(C));
    else
        enqueue(client,Q(C));
}
void clientCheckout(Cashier* C){
    //removes client and updates total_clients serviced
    CLIENTS(C)++;        
    if(TYPE(C)==PQUEUE)
        dequeuePQ(PQ(C));
    else
        dequeue(Q(C));
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
        delayServiceTo(step+1,cashier);
        processedProduct(ITEMS(client),cashier);
        timeIncrease(step-CHECKIN(client),cashier);
        clientCheckout(cashier);
        printf("--->Client serviced in cashier %d\n",ID(cashier));
    }
}


void printCashier(Cashier* C){
    printf("Caixa %d: ",ID(C));
    if(TYPE(C)==QUEUE)
        printQueue(Q(C));
    else
        printPriorityQueue(PQ(C));
}

void closeCashier(Cashier* C){
    if(TYPE(C)==QUEUE) freeQueue(Q(C));
    else freePQueue(PQ(C));
}