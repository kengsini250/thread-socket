#include "Server.h"
#include "Thread.h"

#define DEBUG

int main()
{
    Server *server = (Server *)malloc(sizeof(Server));
    setIpAndPort(server, AF_INET, 55555);
    BindAndListen(server, 5);
#ifdef DEBUG
    printf("-------------------start------------------\n");
#endif
    getData(server);
    close(server->server_socketfd);
}