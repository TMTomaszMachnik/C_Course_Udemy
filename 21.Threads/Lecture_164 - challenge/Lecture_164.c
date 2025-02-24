#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

int iCounter = 0; //shared resource
pthread_mutex_t lock;
pthread_cond_t cond;
int number_evens_finished = 0;
int counter = 0;

void *threadCounter( void *ptr ){
    long thread_id = (long)ptr;
    pthread_mutex_lock(&lock);

    if(thread_id%2 != 0){
        pthread_cond_wait(&cond,&lock);
    }
    iCounter++;
    printf("Thread id: %ld incremented counter to %d\n", pthread_self(), iCounter);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}


void* func1(void* data)
{
    int *x = (int *) data;
   
    pthread_mutex_lock( &lock); 

    if (*x % 2 == 0) {
       number_evens_finished++;
    }
    else {
       pthread_cond_wait(&cond, &lock);   
    }
  
    counter++;
    printf("message is %d, thread id = %lud modified the counter to %d\n", *x, pthread_self(), counter);
    printf("message is %d, thread id = %lud read the counter %d\n", *x, pthread_self(), counter); 
    
    pthread_mutex_unlock( &lock );        
}

void challenge_1(){
    pthread_t threads[NUM_THREADS];
    if(pthread_mutex_init(&lock,NULL) != 0) {
        printf("Mutex init failed");
        exit(1);
    }
    for(int i = 0;i<NUM_THREADS;i++){
        pthread_create(&threads[i], NULL, threadCounter, NULL);
    }
    for(int i = 0;i<NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }
    pthread_mutex_destroy(&lock);
    printf("Final Counter Value = %d",iCounter);
    return;
}

void challenge_2(){
   pthread_t thread_id[NUM_THREADS];
   int values[NUM_THREADS];

   for(int i=0; i < NUM_THREADS; i++) {
      values[i] = i;
      pthread_create( &thread_id[i], NULL, func1, &values[i]);
   }

   // NEED TO WAIT UNTIL ALL THREADS HAVE BEEN CREATED AND RUNNING (SO THAT ALL ODD THREADS ARE WAITING, BEFORE WE 
   // EVEN TRY TO SIGNAL  (OR THERE WILL BE A RACE CONDITION, RAN INTO THE PROBLEM OF SIGNALLING BEFORE ALL ODD THREADS WERE WAITING
   sleep(1);
   
   while(1) {
	if(number_evens_finished == NUM_THREADS / 2) {
	  pthread_cond_broadcast(&cond);
      break;
    }    
   }

   for(int j=0; j < NUM_THREADS; j++) {
      pthread_join( thread_id[j], NULL); 
      pthread_exit(&thread_id[j]);
   }
    
    return;
}



int main(){
    challenge_2();
}