#include<stdio.h>

static int fun(){
    static int count = 100;
    int localvar = 0;
    printf("automatic = %d, static = %d\n",localvar,count);
    count ++;
    localvar++;
    return count;
}

int main() {

for(int i=0;i<5;i++){
    //printf("%d ", fun());
    //printf("%d ", fun());
    fun();
}
return 0;
}