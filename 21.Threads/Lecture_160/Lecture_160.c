#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<malloc.h>

// void* calls(void* ptr) {
//     printf("In function \nthread id = %d\n",pthread_self());
//     pthread_exit(NULL);
//     return NULL;
// }

// int main() {
//     pthread_t thread;
//     pthread_create(&thread, NULL, calls, NULL);
//     printf("In main \nthread id = %d\n", thread);
//     pthread_join(thread,NULL);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <string.h>

// pthread_attr_t attr;

// void* dowork(void *threadid) {
//     long tid = (long)threadid;
//     size_t mystackSize;

//     pthread_attr_getstacksize(&attr, &mystackSize);
//     printf("Thread %ld: stack size = %lu bytes\n", tid, mystackSize);

//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t myTHread;
//     size_t stack_size;
//     long t = 0; 
//     pthread_attr_init(&attr);
//     pthread_attr_getstacksize(&attr, &stack_size);
//     printf("Default stack size = %lu bytes\n", stack_size);
//     stack_size = 9000000;
//     printf("Amount of stack needed per thread = %lu bytes\n", stack_size);
//     pthread_attr_setstacksize(&attr, stack_size);
//     int rc = pthread_create(&myTHread, &attr, dowork, (void *)t);
//     if (rc) {
//         printf("Error: unable to create thread, %d\n", rc);
//         return 1;
//     }
//     pthread_join(myTHread, NULL);

//     printf("Stack in thread = %lu bytes\n", stack_size);
//     return 0;
// }

void *thread_cancel(void *ptr){
    printf("Hello");
    pthread_cancel(pthread_self());
    return NULL;
}

int main() {
    pthread_t thread = NULL;
    pthread_create(&thread,NULL,thread_cancel,NULL);
    pthread_join(thread,NULL);
    return 0;
}