/*******************************************************************************
| Program: A Definition of a Supermarket                                       |
| Last Updated: 22/5/2019                                                  FCUP|
*******************************************************************************/
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
//A supermarket will contain the number of open cashiers and its list/array
typedef struct supermarket{
    Cashier** cashiers_list;
    int n_cashiers;
}Supermarket;


/*------------------------------------------------------------------------------
|                           Supermarket Functions                              |
------------------------------------------------------------------------------*/
Supermarket* openSupermarket(int,int,int);

int isSupermarketInUse(Supermarket*);
void printSupermarket(Supermarket*);

void serviceClients(int,Supermarket*); //Service clients in the cashiers
void closingOfAccounts(Supermarket*); //Calculates the usage of all the cashiers

void closeSupermarket(Supermarket*);

#endif