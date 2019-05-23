/*******************************************************************************
| Program: A Definition of a Supermarket Cashier  + the Supermarket Cashiers   |
| Last Updated: 15/5/2019                                                  FCUP|
********************************************************************************
|   Representation:                                                            |
|       -> A cashier will have its own id number                               |
|       -> Will store the total number of clients serviced                     |
|       -> Will store the total wainting time for clients to be serviced, the  |
|           number of cycles for clients to be serviced                        |
|       -> The total amount of products that were processed by the cashier,    |
|           when a new client is serviced its number of products will add to   |
|           the total amount of products that were processed by the cashier    |
|       -> The instant to which a client is serviced, meaning the time stamp   |
|            (cycle number) when a new client can be serviced                  |
|       -> The number of products processed by cycle, a random number between  |
|           1 and 5                                                            |
*******************************************************************************/
#include "Queue.h"
#include "Client.h"

#ifndef CASHIER_H
#define CASHIER_H

/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define ID(C) ((C)->cashier_id)
#define LINE(C) ((C)->cashier_line)
#define CLIENTS(C) ((C)->total_clients)
#define PRODUCTS(C) ((C)->total_products)
#define WAIT_TIME(C) ((C)->total_waiting_time)
#define NEXT_SERVICE(C) ((C)->servicing_available_time)
#define SCAN_POWER(C) ((C)->scanning_power)


/*------------------------------------------------------------------------------
|                           Cashier Definition                                 |
------------------------------------------------------------------------------*/
typedef struct cashier{
    Queue* cashier_line;
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
Cashier* openCashier(int);
void delayServiceTo(int,Cashier*);
void clientCheckin(Client*,Cashier*);
void clientCheckout(Cashier*); //removes client and updates total_clients
void processedProduct(int,Cashier*);
void timeIncrease(int,Cashier*);

int isCashierEmpty(Cashier*);
void printCashier(Cashier*);

void serviceClient(int,Cashier*);
/*------------------------------Free------------------------------------------*/
void closeCashier(Cashier*);


#endif