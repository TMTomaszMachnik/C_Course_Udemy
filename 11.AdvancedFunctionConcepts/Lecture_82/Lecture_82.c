#include<stdio.h>
#include<stdlib.h>
int factorial(int n){
    int result = 0;
    if( n == 0 )
        result = 1;
    else
        result = n * factorial (n-1);
    return result;
}

int main(){
    for(int i=0;i<10;i++){
    printf("%d! = %d\n",i,factorial(i));
    }
    return 0;
}
