#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){
    time_t calendar_start = time(NULL);
    clock_t cpu_start = clock();
    int count = 0;
    const long long iteratiions = 10000000LL;
    char answer = 'y';
    double x = 0.0;
    printf("Initial clock time = %lld Initial callendar time = %lld\n", (long long)cpu_start, (long long)calendar_start);

    while(tolower(answer) == 'y'){
        for(long long i = 0LL ; i < iteratiions ; i++){
            x = sqrt(3.14521512);
        }
    printf("%lld square roots were completed", iteratiions*(++count));
    printf("Do you want to run some more?\n");
    scanf("\n%c",&answer);
}

clock_t cpu_end = clock();
time_t calendar_end  = time(NULL);
printf("Final clck time = %lld\n",(long long)cpu_end, (long long)calendar_end);
printf("Actual time to execute is %8.2lf seconds\n", difftime(calendar_end,calendar_start));
}