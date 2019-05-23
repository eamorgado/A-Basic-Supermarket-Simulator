#include <stdio.h>
#include "SupermarketSimulator.h"

int main(){
    int affluence=0,appetite=0,n_cashiers=0,cycles=0,type=0;
    printf("Type of Cashier, 2 layer Priority Queue/Normal Queue (1/0):");
    scanf("%d",&type);

    printf("\nAffluence:");
    scanf("%d",&affluence);

    printf("\nAppetite:");
    scanf("%d",&appetite);

    printf("\nNumber Cashiers:");
    scanf("%d",&n_cashiers);

    printf("\nCycles:");
    scanf("%d",&cycles);
    
    simulateWorkingSupermarket(type,affluence,appetite,n_cashiers,cycles);
}