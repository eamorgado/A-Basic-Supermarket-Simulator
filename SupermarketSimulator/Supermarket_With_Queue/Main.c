#include <stdio.h>
#include <string.h>
#include "SupermarketSimulator.h"

int main(int argc, char const *argv[]){
    int affluence=0,appetite=0,n_cashiers=0,cycles=0,test=0;
    printf("Affluence:");       scanf("%d",&affluence);
    printf("Appetite:");        scanf("%d",&appetite);
    printf("Number Cashiers:"); scanf("%d",&n_cashiers);
    printf("Cycles:");          scanf("%d",&cycles);

    if(argc == 2 && strcmp(argv[1],"-t")==0) test=1;
    simulateWorkingSupermarket(affluence,appetite,n_cashiers,cycles,test);
}