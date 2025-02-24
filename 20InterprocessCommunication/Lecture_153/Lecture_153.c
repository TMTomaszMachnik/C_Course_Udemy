#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include <unistd.h>  

// void termination_handler (int signum) {
//     struct temp_file *p;
//     for( p = temp_file_list; p; p->next)
//         unlink(p->name);
// }
// int main(){

//     struct sigaction new_action, old_action;

//     new_action.sa_handler = termination_handler;
//     sigemptyset (&new_action.sa_mask);
//     new_action.sa_flags = 0;
//     sigaction (SIGINT, NULL, &old_action);

//     if(old_action.sa_handler != SIG_IGN)
//         sigaction(SIGINT, &new_action, NULL);

//     sigaction(SIGHUP, NULL ,&old_action);

//     if(old_action.sa_handler != SIG_IGN)
//         sigaction(SIGHUP, &new_action, NULL);
    
//     sigaction (SIGTERM,NULL,&old_action);

//     if(old_action.sa_handler != SIG_IGN)
//         sigaction(SIGTERM, &new_action, NULL);

//     return 0;
// }

void handle_sigint(int sig, siginfo_t *info, void *context) {
    printf("\nReceived SIGINT (Ctrl+C)\n");
    printf("Process ID (PID): %d\n", getpid());
    printf("User ID (UID): %d\n", getuid());
}

int main() {
    struct sigaction sa;

    // Set up the sigaction struct
    sa.sa_sigaction = handle_sigint;  // Use sigaction handler
    sa.sa_flags = SA_SIGINFO;         // Use extended signal info
    sigemptyset(&sa.sa_mask);         // No blocked signals

    // Register signal handler for SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction failed");
        exit(EXIT_FAILURE);
    }

    printf("Running... Press Ctrl+C to trigger the signal handler.\n");

    // Infinite loop to keep the program running
    while (1) {
        sleep(5);
    }

    return 0;
}
