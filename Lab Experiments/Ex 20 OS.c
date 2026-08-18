#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
sem_t writeBlock;

int data = 0;
int readers = 0;

void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);

    readers++;

    if (readers == 1)
        sem_wait(&writeBlock);

    sem_post(&mutex);

    printf("Reader %d reads data = %d\n", id, data);

    sem_wait(&mutex);

    readers--;

    if (readers == 0)
        sem_post(&writeBlock);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&writeBlock);

    data++;

    printf("Writer %d writes data = %d\n", id, data);

    sem_post(&writeBlock);

    return NULL;
}

int main()
{
    pthread_t r[3], w[2];

    int rid[] = {1, 2, 3};
    int wid[] = {1, 2};

    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    for (int i = 0; i < 3; i++)
        pthread_create(&r[i], NULL, reader, &rid[i]);

    for (int i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, &wid[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(r[i], NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}