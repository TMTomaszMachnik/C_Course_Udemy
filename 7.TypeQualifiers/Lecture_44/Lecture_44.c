#include<stdio.h>

const double pi = 3.141592654;

int main(){

    /*const double pi = 3.141592654;

    const int days[12] = {31,28,31,30,...}

    typedef const int zip;

    const zip q = 9;*/
    const float *pf; //Points to a constant value

    float *const pt; //Points to a constant adress - value can change

    const float * const ptr; //Both are constant!

    return 0;
}

void display(const int array[], int limit)

char *strcat(char *restrict sl,  constant char *restrict s2)