#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct date{
    int day;
    int month;
    int year;
};

struct date foo(struct date x){
    ++x.day;
};

int main(){
    // const int data[5] = {1,2,3,4,5};
    // int i = 0, sum = 0;

    // for(i=0;i>=0;i++)
    //     sum += data[i];
    // printf( "sum = %i\n",sum);
    // return 0;
    struct date  today = {10,11,2014};
    int          array[5] = {1,2,3,4,5};
    struct date *newdate,foo();
    char        *string = "test string";
    int          i = 3;
    newdate = (struct date*) malloc (sizeof(struct date));
    newdate -> month = 11;
    newdate -> day = 15;
    newdate -> year = 2014;

    today = foo(today);
    free(newdate);
    return 0;
}