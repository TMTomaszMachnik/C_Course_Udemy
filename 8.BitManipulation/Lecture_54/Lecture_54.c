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
    int flags = 15; //0000 1111
    int mask = 182; // 1011 0110

    int or_flags = flags | mask;
    int and_flags = flags & ~mask;
    int xor_flags = flags ^ mask;

    printf("%d\n", DecimalToBinary(or_flags));
    printf("%d\n", DecimalToBinary(and_flags));
    printf("%d", DecimalToBinary(xor_flags));

     //if(flags&mask==mask)
     //packed_data |= 7<<18
    return 0;
}