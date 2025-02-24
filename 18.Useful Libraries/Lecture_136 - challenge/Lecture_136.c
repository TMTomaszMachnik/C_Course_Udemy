#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<time.h>

void randomNum(double Tab[], int n){
    for(int i = 0; i < n; i++){
        Tab[i] = 1 + (4.0 * rand() / RAND_MAX);
    }
}

void ShowArray(const double Ar[], int n){
    for(int i = 0; i < n; i++){
        printf("%6.3lf", Ar[i]);
        if((i + 1) % 10 == 0 ){
            printf("\n");
        }
    }
}

int comp_ints(const void *p1, const void *p2){
    const double d1 = * (const double *) p1;
    const double d2 = * (const double *) p2;
    return d2 - d1;
}

void challenge_3(){
    time_t cur_time;
    char* cur_t_string;
    cur_time = time(NULL);
 
   if (cur_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to get the current time.\n");
        exit(EXIT_FAILURE);
    }
    cur_t_string = ctime(&cur_time); //convert to local time format
    if (cur_t_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
    (void) printf("\n The Current time is : %s \n", cur_t_string);
    exit(EXIT_SUCCESS);
}

void challenge_4(){
    time_t now;
    time(&now);
    
    struct tm month_begin;
    month_begin = *localtime(&now);
    month_begin.tm_sec = 0;
    month_begin.tm_min = 0;
    month_begin.tm_hour = 0;
    month_begin.tm_mday = 1;

    double seconds = difftime(now, mktime(&month_begin));
	
    printf("\n %.f seconds passed since the beginning of the month.\n\n", seconds);
}

int main(){
    // TEST 1
    // double Array[50];
    // randomNum(Array);
    // for(int i = 0; i < 50; i++){
    //     printf("%lf ", Array[i]);
    // }
    
    //TEST 2
    // srand(time(0));
    // int n = 50;
    // double Array[n];
    // randomNum(Array,n);
    // ShowArray(Array,n);
    // qsort(Array, n, sizeof(double), comp_ints);
    // puts("\n");
    // ShowArray(Array,n);

    challenge_4();

    return 0;
}