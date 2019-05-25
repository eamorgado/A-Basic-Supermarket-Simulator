/*******************************************************************************
| Program: An Implementation of a Client                                       |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Client.h"

Client* newClient(int items,int checkin_time){
    Client* c=(Client*)malloc(sizeof(Client));
    if(!c){
        printf("Error creating client with %d items at time %d",items,checkin_time);
        exit(0);
    }
    ITEMS(c)=items;
    CHECKIN(c)=checkin_time;
    return c;
}