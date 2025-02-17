#include<stdio.h>

int somedisplay();
void func1(int iValue) {printf("func1 data: %d\n",iValue);}
void func2(int iValue) {printf("func2 data: %d\n",iValue);}

typedef void FuncType(int);

int main(){
    // int (*func_ptr)();
    // func_ptr = somedisplay;
    // printf("Address is %p\n", func_ptr);
    // (*func_ptr)();
    // return 0;
    FuncType *func_ptr = NULL;

    func_ptr = func1;

    (*func_ptr)(100);

    func_ptr = func2;

    (*func_ptr)(200);
}

int somedisplay(){
    printf("\n---Displaying some text---\n");
    return 0;
}