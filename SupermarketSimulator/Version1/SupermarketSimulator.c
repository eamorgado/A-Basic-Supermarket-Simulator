#include <stdio.h>
#include <stdlib.h>
#include "Cashier.h"
#include "Client.h"
#include "Supermarket.h"

void simulateWorkingSupermarket(int affluence,int appetite,int n_cashiers,int cycles){
    Supermarket* SM=openSupermarket(n_cashiers);

    for(int step=0;step<cycles;step++){
        serviceClients(step,SM);

        float random = (float)rand()/(float)(RAND_MAX);
        float val = (float)affluence/100;
        if(random<=val){
            int products = (rand()%((3*appetite) -1+1))+1;
            Client* client=newClient(products,step);

            printf("--->New Client created at %d with %d products",step,products);

            int cashier_to_checkin = (rand()%(n_cashiers -1+1))+1;
            clientCheckin(client,CASHIERS(SM)[cashier_to_checkin]);
        }
        printSupermarket(SM);
    }
    printf("==Cashiers Closed==\n");
    int step=cycles+1;

    while(isSupermarketInUse(SM)){
        printf("==Cycle %d==\n",step);
        serviceClients(step,SM);
        printSupermarket(SM);
        step++;
    }
    closingOfAccounts(SM);
    closeSupermarket(SM);
}
