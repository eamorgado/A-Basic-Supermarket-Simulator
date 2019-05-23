#include <stdio.h>
#include <stdlib.h>
#include "Cashier.h"
#include "Client.h"
#include "Supermarket.h"

void simulateWorkingSupermarket(int type,int affluence,int appetite,int n_cashiers,int cycles){
    Supermarket* SM=openSupermarket(n_cashiers,type);

    for(int step=1;step<=cycles;step++){
        printf("\n==Cycle %d==\n",step);
        serviceClients(step,SM);

        double random = (double)rand()/RAND_MAX;
        double val = (double)affluence/100;
        
        if(random<=val){
            int products = (rand()%((3*appetite) -1+1))+1;


            Client* client=newClient(products,step);

            printf("\n--->New Client created at %d with %d products\n",step,products);

            int cashier_to_checkin = (rand()%(n_cashiers -1+1))+1;
            int priority = (rand() %(2));
            
            clientCheckin(client,priority,CASHIERS(SM)[cashier_to_checkin-1]);
        }
        printf("\n");
        printSupermarket(SM);
    }
    printf("\n\n=====Cashiers Closed=====\n");
    int step=cycles+1;
    printf("\n\n");
    while(isSupermarketInUse(SM)){
        printf("\n===Cycle %d===\n",step);
        serviceClients(step,SM);
        printSupermarket(SM);
        printf("\n");
        step++;
    }
    printf("\n==Closing Supermarket==\n");
    closingOfAccounts(SM);
    closeSupermarket(SM);
}
