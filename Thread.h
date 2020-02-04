#include <pthread.h>
#include <unistd.h>

#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static pthread_t tid;
extern int connecting;

void newThread(int client_socketfd );
void *getDataInThread(void *argc);
