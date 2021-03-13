// reader.c - funzione per thread writer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <mqueue.h>
#include <pthread.h>
#include "data.h"

// writer() - thread routine
void *writer(void *arg)
{
    // apro la message queue in modo scrittura
    printf("thread %ld partito\n", pthread_self());
    mqd_t mq;
    if ((mq = mq_open(MQUEUE_PATH, O_WRONLY)) == -1) {
        // errore di apertura
        printf("%s: non posso aprire la message queue (%s)\n", __func__, strerror(errno));
        pthread_exit(NULL);
    }

    // loop di scrittura messaggi per il reader
    Data my_data;
    my_data.index = 0;
    do {
        // test index per forzare l'uscita
        if (my_data.index == N_MESSAGES) {
            // il thread chiude la message queue ed esce per indice raggiunto
            printf("thread %d terminato (text=%s index=%ld)\n", getpid(), my_data.text, my_data.index);
            mq_close(mq);
            pthread_exit(NULL);
        }

        // compongo il messaggio e lo invio
        my_data.index++;
        snprintf(my_data.text, sizeof(my_data.text), "un-messaggio-di-test:%ld", my_data.index);
    } while (mq_send(mq, (char *)(&my_data), sizeof(Data), 1) != -1);

    // il thread chiude la message queue ed esce per altro motivo (errore)
    printf("thread %d terminato con errore (%s)\n", getpid(), strerror(errno));
    mq_close(mq);
    pthread_exit(NULL);
}
