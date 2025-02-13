#include <stdio.h>
/*
int main(){

    int x=15;

    register int *a =&x;
    for(x=1;x<=15;x++)
    {
        printf("\n%d", *a);
    }
    return 0;
}
*/


int main()
{
    register int x = 10;

    printf("\n%d", x);
    return 0;
}