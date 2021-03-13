// threads.c - main processo padre
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <mqueue.h>
#include <pthread.h>
#include "data.h"

// prototipi globali
extern void* reader(void *arg);
extern void* writer(void *arg);

// funzione main()
int main(int argc, char* argv[])
{
    // set attributi della message queue
    struct mq_attr ma;
    ma.mq_flags   = 0;              // flags: 0 o O_NONBLOCK
    ma.mq_maxmsg  = 10;             // numero massimo di messaggi permessi nella coda
    ma.mq_msgsize = sizeof(Data);   // massimo size di un messaggio (in byte)
    ma.mq_curmsgs = 0;              // numero di messaggi attualmente nella coda

    // creo la message queue
    if (mq_open(MQUEUE_PATH, O_RDWR | O_CREAT, 0700, &ma) == -1) {
        // errore di creazione
        printf("%s: non posso creare la message queue (%s)\n", argv[0], strerror(errno));
        exit(EXIT_FAILURE);
    }

    pthread_t tid[2];
    int error;

    // crea il thread 1
    if ((error = pthread_create(&tid[0], NULL, &reader, NULL)) != 0)
        printf("%s: non posso creare il thread 0 (%s)\n", argv[0], strerror(error));

    // crea il thread 2
    if ((error = pthread_create(&tid[1], NULL, &writer, NULL)) != 0)
        printf("%s: non posso creare il thread 1 (%s)\n", argv[0], strerror(error));

    // join thread
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    // exit
    printf("%s: thread terminati\n", argv[0]);
    mq_unlink(MQUEUE_PATH);
    return 0;
}
