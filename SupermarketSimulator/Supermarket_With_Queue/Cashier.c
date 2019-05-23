/*******************************************************************************
| Program: An Implementation of a Supermarket Cashier                          |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Cashier.h"
#include "Queue.h"

Cashier* openCashier(int id){
    Cashier* C=(Cashier*)malloc(sizeof(Cashier));
    if(!C){
        printf("Error opening cashier %d",id);
        exit(0);
    }
    Queue* line = createQueue();
    ID(C)=id;
    LINE(C)=line;
    CLIENTS(C)=PRODUCTS(C)=WAIT_TIME(C)=NEXT_SERVICE(C)=0;
    SCAN_POWER(C)=(rand()%(5-1+1))+1;
    return C;
}
void delayServiceTo(int available_at,Cashier* C){
    NEXT_SERVICE(C)=available_at;
}
void clientCheckin(Client* client,Cashier* C){
    enqueue(client,LINE(C));
}
void clientCheckout(Cashier* C){
    //removes client and updates total_clients
    dequeue(LINE(C));
}
void processedProduct(int items,Cashier* C){
    PRODUCTS(C)+=items;
}
void timeIncrease(int time_for_service,Cashier* C){
    WAIT_TIME(C)+=time_for_service;
}
int isCashierEmpty(Cashier* C){
    return isQueueEmpty(LINE(C));
}
void printCashier(Cashier* C){
    printf("Caixa %d: ",ID(C));
    printQueue(LINE(C));
}

void serviceClient(int step,Cashier* cashier){
    /**
     * Verifies if the first client inn this cashier has been serviced, if so,
     *      updates its info, #clients, #products
     */
    Client* client = getFirst(LINE(cashier));
    int wait = step - NEXT_SERVICE(cashier);
    int products_scanned = wait * SCAN_POWER(cashier);

    if(products_scanned >= ITEMS(client)){
        NEXT_SERVICE(cashier)= ++step;
        CLIENTS(cashier)++;
        PRODUCTS(cashier)+=ITEMS(client);
        WAIT_TIME(cashier)+= (step-CHECKIN(client));
        clientCheckout(cashier);
        printf("--->Client serviced in cashier %d\n",ID(cashier));
    }
}

void closeCashier(Cashier* C){
    freeQueue(LINE(C));
    free(C);
}