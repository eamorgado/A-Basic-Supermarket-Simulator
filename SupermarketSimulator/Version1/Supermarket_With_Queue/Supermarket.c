#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Client.h"
#include "Cashier.h"
#include "Supermarket.h"

Supermarket* openSupermarket(int n_cashiers){
    Supermarket* SM=(Supermarket*)malloc(sizeof(Supermarket));
    if(!SM){
        printf("Error creating supermarket\n");
        exit(0);
    }

    NCASHIERS(SM)=n_cashiers;
    
    CASHIERS(SM)=malloc(NCASHIERS(SM)*sizeof(CASHIERS(SM)));
    if(!CASHIERS(SM)){
        printf("Error opening %d cashiers for supermarket\n",n_cashiers);
        exit(0);
    }

    for(int i=0;i<=NCASHIERS(SM);i++)
        CASHIERS(SM)[i]=openCashier(i+1);

    return SM;
}
void printSupermarket(Supermarket* SM){
    for(int i=0;i<NCASHIERS(SM);i++)
        printCashier(CASHIERS(SM)[i]);
}
int isSupermarketInUse(Supermarket* SM){
    for(int i=0;i<NCASHIERS(SM);i++)
        if(isCashierEmpty(CASHIERS(SM)[i])==0)
            return 1;
    return 0;
}
void serviceClients(int step,Supermarket* SM){
    for(int i=0;i<NCASHIERS(SM);i++){
        if(isCashierEmpty(CASHIERS(SM)[i])==1)
            NEXT_SERVICE(CASHIERS(SM)[i])=step;
        else 
            serviceClient(step,CASHIERS(SM)[i]);
    }
}
void closingOfAccounts(Supermarket* SM){
    for(int i=0;i<NCASHIERS(SM);i++){
        Cashier* c=CASHIERS(SM)[i];
        int clients=CLIENTS(c);
        int products=PRODUCTS(c);
        double avg=(double)products/clients;
        printf("\nCashier %d (%d products scanned per cycle):\n",ID(c),SCAN_POWER(c));
        if(CLIENTS(c)!=0)
            printf(">>%d clients serviced, average %0.1f products/clients\n",clients,avg);
        else 
            printf(">>%d clients serviced\n",clients);
    }
}

void closeSupermarket(Supermarket* SM){
    for(int i=0;i<NCASHIERS(SM);i++)
        closeCashier(CASHIERS(SM)[i]);
    free(SM);
}