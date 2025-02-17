#include<stdio.h>

// #define PI 3.14

// #define PRNT(a,b) \
//     printf("value 1 = %d\n",a);\
//     printf("value 2 = %d\n",b);

// int main(){
//     int x = 2;
//     int y = 3;
//     PRNT(x,y);
//     return 0;
// }
#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))
#define WARNING(...) fprintf(stderr,__VA_ARGS__)
#define FOO BAR 
#define BAR (12)

#define MISC(x) (puts("intcrementing", (x)++))

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define UpTo(i, n) for ((i) = 0; (i) < n; (i)++) //Non Syntactic macro

double circleArea(double x){
    return 3.14 * x * x;
}

int main(){

    WARNING("%s: this program is here\n", "Jason");
    int c = 5;
    int area = CIRCLE_AREA(c + 2);
    int Farea = circleArea(c + 2);
    printf("%d\n", area);
    printf("%d", Farea);
}