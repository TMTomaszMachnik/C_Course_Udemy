#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main(){
    // char command[50];

    // strcpy(command, "pwd");
    // system(command);

    char *str;

    assert((str = getenv("HOME")) != NULL);
    printf(("Value of \"HOME Enviroment Variable\" is : %s\n"),str);
    return 0;
}