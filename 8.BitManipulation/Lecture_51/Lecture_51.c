#include<stdio.h>

long long DecimalToBinary(int n){
    long long binary_number = 0;
    int remainder,i = 1;

    while(n>0){
        remainder = n%2;
        n = n/2;
        binary_number += remainder*i;
        i = i*10;
    }
    return binary_number;
}

int main(){
    /*short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;

    w3 = w1 & w2;
    printf("%d", w3);
    */
    unsigned int w1  = 10; //1010
    unsigned int w2 = 11; //1011

    int resultw1 = ~w1;
    int resultw2 = ~w2;

    int result = w1 & w2;
    printf("%d %d \n", resultw1, resultw2);
    printf("%d", DecimalToBinary(w1&w2));
    printf("%d\n", DecimalToBinary(w1|w2));
    printf("%d\n", DecimalToBinary(w1 << 2));
    printf("%d\n", DecimalToBinary(w2 << 1));
    
    return 0;
}