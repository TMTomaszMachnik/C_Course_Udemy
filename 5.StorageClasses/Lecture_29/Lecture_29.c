#include<stdio.h>
int main(){

    auto int x=10; //local
    printf("%d",x);
    return 0;
}

int function(){
    auto int y=10;
    return y; //local
}   