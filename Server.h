#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Thread.h"

typedef struct _Server
{
    int server_socketfd;
    int bindFlag;
    int listenFlag;
    struct sockaddr_in server;
} Server;

void setIpAndPort(Server *server, int ip_family, uint16_t port);
void BindAndListen(Server *server, int max);

void getData(Server *server);