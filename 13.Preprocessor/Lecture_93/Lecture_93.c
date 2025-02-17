#include<stdio.h>

//#define JUST_CHECKING
//#define LIMIT 4

// int main(){
//     int i;
//     int total = 0;

//     for (i = 1; i<= LIMIT; i++){
//         total += 2*i*i + 1;

//         #ifndef JUST_CHECKING
//             printf("i=%d, running total = %d\n", i ,total);
//         #endif
//     }
//     printf("Cmpleted");
// }

#define MYDEF 5
#define MYOTHERDEF 2

int main(){
    #if MYDEF == 5 && MYOTHERDEF == 2
        printf("Hello");
    #endif
    return 0;
}