#include "Cashier.h"

#ifndef SUPERMARKET_H
#define SUPERMARKET_H

/*------------------------------------------------------------------------------
|                           Macro Definition                                   |
------------------------------------------------------------------------------*/
#define CASHIERS(SM) ((SM)->cashiers_list)
#define NCASHIERS(SM) ((SM)->n_cashiers)


/*------------------------------------------------------------------------------
|                           Supermarket Definition                             |
------------------------------------------------------------------------------*/
typedef struct supermarket{
    Cashier** cashiers_list;
    int n_cashiers;
}Supermarket;


/*------------------------------------------------------------------------------
|                           Supermarket Functions                              |
------------------------------------------------------------------------------*/
Supermarket* openSupermarket(int);
void printSupermarket(Supermarket*);
int isSupermarketInUse(Supermarket*);
void serviceClients(int,Supermarket*);
void closingOfAccounts(Supermarket*);

void closeSupermarket(Supermarket*);

#endif