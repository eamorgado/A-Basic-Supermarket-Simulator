#include <stdio.h>
#include "SupermarketSimulator.h"

int main(){
    int affluence=0,appetite=0,n_cashiers=0,cycles=0,type=0;
    printf("Type of Cashier--Priority Queue with 2 priorities--or--Normal Queue?\n(1/0):");
    scanf("%d",&type);

    printf("Affluence:");
    scanf("%d",&affluence);

    printf("Appetite:");
    scanf("%d",&appetite);

    printf("Number Cashiers:");
    scanf("%d",&n_cashiers);

    printf("Cycles:");
    scanf("%d",&cycles);
    
    simulateWorkingSupermarket(type,affluence,appetite,n_cashiers,cycles);
}