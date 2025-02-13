#include<stdio.h>

/*int i=5;

char text[255][25];
void foo(void);

int main(){
    printf("%i ", i);
    foo();
    printf ("%i ", i);
    return 0;
}
*/


int count = 5;

extern void write_extern();

int main(){
    write_extern();
    return 1;
}