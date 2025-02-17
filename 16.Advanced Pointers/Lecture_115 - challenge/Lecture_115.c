#include<stdio.h>
#include<malloc.h>
#include<string.h>

void challenge_1(){
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;


    printf("Value of a = %d\n",a);
    printf("Value of a = %d\n",*p1);
    printf("Value of a = %d\n",**p2);

    printf("Adress of a = %u\n",&a);
    printf("Adress of a = %u\n",p1);
    printf("Adress of a = %u\n",*p2);

    printf("Value of p1 = %d\n",p1);
    printf("Value of p1 = %d\n",*p2);

    printf("Adress of p1 = %u\n",&p1);
    printf("Adress of p1 = %u\n",p2);

    printf("Value of p2 = %d\n",p2);
    printf("Adress of p2 = %d\n",&p2);

    
    
}

void allocateMemory(int **ptr){
    *ptr = malloc(255);
}

int main(){
    //challenge_1();
    int *p1 = NULL;
    allocateMemory(&p1);
    *p1 = 5;
    printf("%d",*p1);
    free(p1);
    return 0;
}