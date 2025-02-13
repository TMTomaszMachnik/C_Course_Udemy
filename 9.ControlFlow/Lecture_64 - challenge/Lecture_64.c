#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

jmp_buf buf;

void myFunction(){
  printf("In my function()\n");
  longjmp(buf,1);
  printf(";(");
}

void ErrorHandler(){
  printf("Error handling...\n");
  longjmp(buf,1);
}

int main(){
  while(1){
    if(setjmp(buf)){
      printf("Main\n");
      break;
    }
    else
      ErrorHandler();
  }
return 0;
}



  // int i = setjmp(buf);
  // printf("i=%d\n", i);
  // if(i != 0) exit(0);
  // longjmp(buf,42);
  // printf("Does this get printed\n");
  // if(setjmp(buf)==1)
  //   printf("back in  main\n");
  // else{
  //   printf("first time\n");
  //   myFunction();
  // }