// #include<stdio.h>
// #include<pthread.h>

// void *print_message( void *ptr);

// int main(){
//     pthread_t thread1,thread2;
//     char *message1= "Thread 1";
//     char *message2 = "Thread 2";
//     int iret1 = 0, iret2 = 0;
//     iret1 = pthread_create(&thread1, NULL,print_message ,(void*)message1);
//     iret2 = pthread_create(&thread2, NULL,print_message ,(void*)message2);
//     pthread_join(thread1,NULL);
//     pthread_join(thread2,NULL);
//     printf("Thread 1 returns: %d\n", iret1);
//     printf("Thread 1 returns: %d\n", iret2);

//     pthread_exit(NULL);
    
//     return 0;
// }

// void *print_message( void *ptr ){
//     char *message;
//     message = (char*) ptr;
//     printf("%s \n",message);
// }

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<malloc.h>

struct thread_data{
    int thread_id;
    int sum;
    char *message;
};

void *printHello(void *thread_arg){
    struct thread_data *my_data;
    int taskid = 0, sum = 0;
    char hello_msg[255];
    my_data = (struct thread_data *) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strcpy(hello_msg, my_data->message);
    printf("Task id = %d, sum = %d, Message = %s\n",taskid,sum,hello_msg);
}

int main(int argc, char *argv[]){
    pthread_t my_thread;
    struct thread_data my_thread_data;
    
    my_thread_data.message = malloc(sizeof(char) * 255);
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 5;
    my_thread_data.message = "Hello";

    pthread_t my_id = pthread_create(&my_thread,NULL,printHello,(void* )&my_thread_data);
    pthread_join(my_thread,NULL);
    pthread_exit(NULL);
    return 0;
}