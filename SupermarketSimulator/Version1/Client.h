/*******************************************************************************
| Program: A Definition of a C Queue                                           |
| Last Updated: 15/5/2019                                                  FCUP|
*******************************************************************************/
#ifndef CLIENT_H
#define CLIENT_H

#define ITEMS(C) ((C)->items)
#define CHECKIN(C) ((C)->checkin_time)

typedef struct client{
    int items;
    int checkin_time;
}Client;

Client* newClient(int,int);

#endif