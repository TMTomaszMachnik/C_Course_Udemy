#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main() {
    alarm(5);

    // printf("Testing sigstop\n");
    // raise(SIGSTOP);
    // printf("Im back\n");
    // return 0;
    for(int i = 1; i < 10; i++){
        printf("%d\n", i);
        sleep(1);
    }
    return 0;
}