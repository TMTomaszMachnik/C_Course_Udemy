#include<stdio.h>
#include <stdio.h>
#include <math.h>

long long convertDecimalToBinary(int n){
   long long binaryNumber = 0;
   int remainder, i=1;

   while(n>0) {
     remainder = n%2;
     n = n / 2;
     binaryNumber += remainder * i;
     i = i * 10;
   }

   return binaryNumber;

}

int convertBinaryToDecimal(long long n){
    long long decimalNumber = 0;
    int remainder, i = 0;
    while(n!=0){
        remainder = n%10;
        n = n / 10;
        decimalNumber += remainder * pow(2,i);
        i++;
    }
}

int main() {
    int decimal,binary = 0;
    long long result = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    result = convertDecimalToBinary(decimal);
    printf("%d in decimal = %lld to binary", decimal , result);

    printf("Enter a binary number: ");
    scanf("%d", &binary);
    result = convertBinaryToDecimal(binary);
    printf("%d in binary = %lld to decimal", binary , result);
    return 0;
}