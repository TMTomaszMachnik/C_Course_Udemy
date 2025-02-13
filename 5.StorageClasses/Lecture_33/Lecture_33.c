#include <stdio.h>

/*
static int last_sum = 0;
int sum(int num) 
{

    last_sum = last_sum + num;
    return last_sum;
}

int main()
{
    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d ", sum(35));
    return 0;
}
*/
extern int iCounter;
extern void Display(void);
int main()
{   
    for(iCounter;iCounter<5;iCounter++)
    {
    Display();
    }
    return 0;
}