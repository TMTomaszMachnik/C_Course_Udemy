#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2
#define NUM_INCREMENTS 100

pthread_mutex_t lock;
int iCounter = 0;

void* increment_counter(void* thread_id){
    long tid = (long)thread_id;
    for (int i = 0;i < NUM_INCREMENTS;i++){
        pthread_mutex_lock(&lock);
        iCounter++;
        pthread_mutex_unlock(&lock);
    }
    printf("THread %d finished\n", tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    if(pthread_mutex_init(&lock,NULL) != 0){
        printf("Mutex init failed");
        return 1;
    }
    for(long i = 0; i< NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,increment_counter,(void*)i);
    }

    for( int i = 0; i<NUM_THREADS;i++) {
        pthread_join(threads[i],NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Final Counter Value = %d",iCounter);
    return 0;
}