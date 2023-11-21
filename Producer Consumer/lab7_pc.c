#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 8  
int buffer[BUFFER_SIZE];
int in = 0;  
int out = 0; 
int count = 0; 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER; 
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER; 

void *producer(void *arg) {
    int item;
    for (int i = 0; i < 15; i++) {  
        item = rand() % 100;  

        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }

       
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        printf("Producer produced item %d\n", item);

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < 15; i++) {  
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

        
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer consumed item %d\n", item);
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);

   
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);

    pthread_join(consumer_thread, NULL);

    return 0;
}



//implement producer consumer problem without using semaphore