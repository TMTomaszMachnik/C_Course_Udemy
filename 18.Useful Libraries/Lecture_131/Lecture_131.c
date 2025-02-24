#include<assert.h>
#include<stdio.h>


int main(){

    // int y = 5;

    // for(int x= 0; x < 20; x++){
    //     printf("x = %d, y = %d",x,y);
    //     assert(x<y);
    // }

    double x, y ,z;
    puts("Enter a pait of numbers 0,0 is to quit");
    while ((scanf("%lf%lf", &x, &y) == 2) && (x != 0 || y != 0)){
        z = x * x - y * y;
        assert(z >= 0);
        printf("Answer is %f\n", sqrt(z));
        puts("another one: ");
    }
    puts("DOne");

    return 0;
}