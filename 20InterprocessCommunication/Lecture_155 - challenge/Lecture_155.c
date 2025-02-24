#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void handle_sigint(int sig, siginfo_t *info, void *context) {
    printf("Received %d\n",signal);
    printf("UID is: %d",getuid());
    printf("PID is: %d",getpid());
    printf("Now exiting...");
    exit(1);
}

void handle_alarm(int sig, siginfo_t *info, void *context){
    printf("\nAlarm received, you took too long,\n now exiting...");
    exit(1);
}

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}
void challenge_1(){
    struct sigaction sa_sigint, sa_alarm;

    sa_sigint.sa_sigaction = handle_sigint;  // Use sigaction handler
    sa_sigint.sa_flags = SA_SIGINFO;         // Use extended signal info
    sigemptyset(&sa_sigint.sa_mask);         // No blocked signals

    sa_alarm.sa_sigaction = handle_alarm;  // Use sigaction handler
    sa_alarm.sa_flags = SA_SIGINFO;         // Use extended signal info
    sigemptyset(&sa_alarm.sa_mask);  

    if(sigaction(SIGINT,&sa_sigint,NULL) == -1){
        perror("sigaction failed");
        exit(EXIT_FAILURE);
    }

    if(sigaction(SIGALRM,&sa_alarm,NULL) == -1){
        perror("sigaction failed");
        exit(EXIT_FAILURE);
    }

   srand (time(0));
   
   while(1) {
      alarm(5);
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];
    
      printf("\nWhat is %d times %d: ", a, b);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else {
         printf("\nWrong! Score: %d\n", score);
         raise(SIGTERM);  
        }
    }
}

void challege_2(){
 
    // Creating first child 
    int n1 = fork(); 
  
    // Creating second child. First child also executes this line and creates grandchild. 
    int n2 = fork(); 
  
    if (n1 > 0 && n2 > 0) 
    { 
        printf("parent\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else if (n1 == 0 && n2 > 0) 
    { 
        printf("\nFirst child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d  \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else if (n1 > 0 && n2 == 0) 
    { 
        printf("\nsecond child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d  \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
    else { 
        printf("\nthird child\n"); 
        printf("%d %d \n", n1, n2); 
        printf("   my id is %d \n", getpid()); 
        printf("   my parentid is %d \n", getppid()); 
    } 
  
}


int main() {
    challege_2();
    return 0;
} 
