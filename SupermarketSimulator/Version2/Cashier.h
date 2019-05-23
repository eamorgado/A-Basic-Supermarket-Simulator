#include "Client.h"
#include "Queue.h"
#include "PriorityQueue.h"
#ifndef CASHIER_H
#define CASHIER_H


/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define TYPE(C) ((C)->type)
#define PQ(C) ((C)->line.cashier_pqueue)
#define Q(C) ((C)->line.cashier_queue)

#define LINE(C) (((TYPE(C)==QUEUE) ? Q(C) : PQ(C)))

#define ID(C) ((C)->cashier_id)
#define CLIENTS(C) ((C)->total_clients)
#define PRODUCTS(C) ((C)->total_products)
#define WAIT_TIME(C) ((C)->total_waiting_time)
#define NEXT_SERVICE(C) ((C)->servicing_available_time)
#define SCAN_POWER(C) ((C)->scanning_power)


/*------------------------------------------------------------------------------
|                          Cashier Type Definition                             |
------------------------------------------------------------------------------*/
typedef enum que_t{
    QUEUE,PQUEUE
}Type;



/*------------------------------------------------------------------------------
|                           Cashier Definition                                 |
------------------------------------------------------------------------------*/
typedef struct cashier{
    Type type;
    union{
        Queue* cashier_queue;
        PriorityQueue* cashier_pqueue;
    }line;
    int cashier_id;
    int total_clients;
    int total_products;
    int total_waiting_time;
    int servicing_available_time;
    int scanning_power;
}Cashier;


/*------------------------------------------------------------------------------
|                           Cashier Functions                                  |
------------------------------------------------------------------------------*/
Cashier* openCashier(int,int);//make cashier with Type and id
void delayServiceTo(int,Cashier*);
void clientCheckin(Client*,int,Cashier*);
void clientCheckout(Cashier*); //removes client and updates total_clients
void processedProduct(int,Cashier*);
void timeIncrease(int,Cashier*);

int isCashierEmpty(Cashier*);
void printCashier(Cashier*);

void serviceClient(int,Cashier*);
/*------------------------------Free------------------------------------------*/
void closeCashier(Cashier*);

#endif