/*extern int i;
extern char text[][25];
void foo(void){
    i = 100;
}
*/

#include<stdio.h>
extern int count;
int fun();

void fun2()
{
    fun();
}
void write_extern(void) {
    printf("count is %d\n",count);
}