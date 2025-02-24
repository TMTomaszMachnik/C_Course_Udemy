#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<time.h>
void handler_dividebyzero(int signum);
void signalHandler(int signalValue);

int main(){
    // int result = 0;
    // int v1,v2 = 0;
    // void(*sigHandlerReturn)(int);
    // sigHandlerReturn = signal(SIGFPE, handler_dividebyzero);

    // if(sigHandlerReturn == SIG_ERR){
    //     perror("Signal Error");
    //     return 1;
    // }
    // v1 = 121;
    // v2 = 0;
    // result = v1/v2;
    // //raise(SIGFPE);
    // printf("Result of Divide by Zero is %d\n", result);
    // return 0;

    int i;
    int x;
    signal(SIGINT, signalHandler);
    srand(clock());

    for(i=1;i<100;i++){
        printf("%d ", i);
        if(i % 25 == 0){
            raise(SIGINT);
        }
    }
    return 0;
}

void handler_dividebyzero(int signum){
    if(signum == SIGFPE) {
        printf("Received SIGFPE, Divideby zero exception\n");
        exit(0);
    }
    else {
        printf("Received %d Signal\n",signum);
    }
    return;
}

void signalHandler( int signalValue ){
    int response;
    printf("\nReceiver SIG int do you wish to continue? ");

    while (scanf("%d", &response) != 1 || (response != 1 && response != 2)) {
        printf("Invalid input. Enter 1 for Yes or 2 for No: ");
        while (getchar() != '\n');  // Clear input buffer
    }

    if (response == 2) {
        printf("Exiting program.\n");
        exit(0);
    } else {
        signal(SIGINT, signalHandler);
        printf("Continuing program.\n");
    }
}
