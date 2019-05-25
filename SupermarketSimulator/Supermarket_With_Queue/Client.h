/*******************************************************************************
| Program: A Definition of a C Queue                                           |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#ifndef CLIENT_H
#define CLIENT_H

#define ITEMS(C) ((C)->items)
#define CHECKIN(C) ((C)->checkin_time)

//A client is defined by the number of items it buys and its time of arrival
typedef struct client{
    int items;
    int checkin_time;
}Client;

//Initializer
Client* newClient(int,int);


#endif