#include <stdio.h>
#include "SupermarketSimulator.h"

int main(){
    int affluence=0,appetite=0,n_cashiers=0,cycles=0;
    scanf("%d %d %d %d",&affluence,&appetite,&n_cashiers,&cycles);
    simulateWorkingSupermarket(affluence,appetite,n_cashiers,cycles);
}