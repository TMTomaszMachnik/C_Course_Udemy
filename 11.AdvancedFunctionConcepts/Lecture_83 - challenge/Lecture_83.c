#include<stdio.h>
#include<stdlib.h>
int SumByLast(int n){

    int sum = 0;
    if(n == 1)
        return 1;
    else
        sum = n + SumByLast(n-1);
    return sum;
}

int main(){
    int n = 10;
    printf("%d",SumByLast(n));
    
    return 0;
}
