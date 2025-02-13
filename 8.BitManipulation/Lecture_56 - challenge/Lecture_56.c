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

    unsigned int w1,position,bitStatus;
    scanf("%d", &w1);
    scanf("%d",&position);
    //Right shift num, position times and perform bitwise AND with 1 
    bitStatus = (w1 >> position) & 1;
    printf("The %d bit is set to %d\n", position, bitStatus);
    int newNum = (1 << position) | w1; //set 1 on position bit

    printf("Number before setting %d bit: %d (in decimal)\n", position, w1);
    printf("Number after setting %d bit: %d (in decimal)\n", position, newNum);
    return 0;
}