#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int available = 0; 
pthread_mutex_t lock;
pthread_cond_t cond;  

void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sleep(1);  

        pthread_mutex_lock(&lock);  

        available = 1; 
        printf("Producer: Produced item %d\n", i);

        pthread_cond_signal(&cond);  
        pthread_mutex_unlock(&lock);  
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        pthread_mutex_lock(&lock); 

        while (available == 0) {  
            pthread_cond_wait(&cond, &lock);
        }

        available = 0; 
        printf("Consumer: Consumed item %d\n", i);

        pthread_mutex_unlock(&lock);  
    }
    return NULL;
}

int main() {
    pthread_t prodThread, consThread;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);

    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
