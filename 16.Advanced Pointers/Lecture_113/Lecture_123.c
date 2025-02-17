#include<stdio.h>
#include<malloc.h>
#include<string.h>

void foo(int **ptr){
    int a = 5;
    *ptr = &a; //Points to a local copy
}


void foo1(char **ptr){
    *ptr = malloc(255); //Allocating memory of a copy!
    strcpy(*ptr, "Hello world");
}

int main(){

    // int *ptr = NULL;
    // ptr = (int *) malloc(sizeof(int));
    // *ptr = 10;
    // foo(&ptr); //Adress of ptr is a double pointer

    // printf("%d\n", *ptr);

    char *ptr = NULL;
    foo1(&ptr);
    printf("%s\n",ptr);
    free(ptr);
    return 0;
}