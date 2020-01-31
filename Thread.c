#include "Thread.h"
#define DEBUG

void newThread(int client_socketfd)
{
#ifdef DEBUG
    printf("-------------------new Thread------------------\n");
#endif
    int t = pthread_create(&tid, NULL,
                           getDataInThread,
                           (int)client_socketfd);

    if (t > 0)
    {
        perror("create thread wrong");
        exit(1);
    }
    pthread_detach(tid);
}

void *getDataInThread(void *argc)
{
#ifdef DEBUG
    printf("-------------------get data------------------\n");
#endif
    int client_socketfd = (int)argc;
    while (1)
    {
        char buffer[20];
        memset(&buffer, 0, 20);
        int n = recv(client_socketfd, buffer, 20, 0);
        if (0 == n)
        {
            printf("%d disconnect\n", client_socketfd);
            return;
        }
        printf("%d : %s\n", client_socketfd, buffer);
    }
    pthread_exit(NULL);
}