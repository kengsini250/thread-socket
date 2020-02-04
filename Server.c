#include "Server.h"
// #define DEBUG

void setIpAndPort(Server *server, int ip_family, uint16_t port)
{
    server->connecting = 0;

    server->server_socketfd = socket(ip_family, SOCK_STREAM, 0);
    if (-1 == server->server_socketfd)
    {
        perror("socket_id wrong");
        exit(1);
    }
    memset(&server->server, 0, sizeof(struct sockaddr_in));
    server->server.sin_family = ip_family;
    server->server.sin_port = htons(port);
    server->server.sin_addr.s_addr = htonl(INADDR_ANY);
}

void BindAndListen(Server *server, int max)
{
    server->bindFlag = bind(server->server_socketfd,
                            (struct sockaddr *)&server->server,
                            sizeof(struct sockaddr_in));
    if (-1 == server->bindFlag)
    {
        perror("bind wrong");
        exit(1);
    }

    server->listenFlag = listen(server->server_socketfd, max);
    if (-1 == server->listenFlag)
    {
        perror("lister wrong");
        exit(1);
    }
}

void getData(Server *server)
{
    struct sockaddr_in client;
    memset(&client, 0, sizeof(struct sockaddr_in));

    while (1)
    {
        socklen_t size = sizeof(client);
        int client_socketfd = accept(server->server_socketfd,
                                     (struct sockaddr *)&client, &size);

        // server->connecting++;
        // printf("connecting : %d\n", server->connecting);
        printf("main thread : %ld\n", pthread_self());
        newThread(client_socketfd);
    }
}