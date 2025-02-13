#include<stdio.h>
#include<ctype.h>

int main(){
  // GETC

  // char ch = '\0';
  // FILE *fp;
  // fp = fopen("C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_65\\Lecture_64.c", "r");
  // if(fp != NULL){
  //   while((ch = getc(fp))!= EOF){
  //     putchar(ch);
  //   }
  //   fclose(fp);
  // }

  //char ch = '\0';

  //ch = getc(stdin);

  //GETCHAR

  // int ch = 0;
  // while((ch = getchar()) != EOF){
  //   printf("read in character %c\n", ch);
  // }
  
  //FGETC

  // char ch = '\0';
  // FILE *fp;
  // fp = fopen("C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_65\\Lecture_64.c", "r");
  // if(fp == NULL){
  //   printf("COuld not open the file");
  //   return 1;
  // }
  // printf("Reading the file...");

  // while(1){
  //   ch = fgetc(fp);

  //   if(ch==EOF)
  //     break;
  //   printf("%c", ch);
  // }
  // fclose(fp);

  char ch = 0; 
  while(isspace(ch = (char)getchar()));
    ungetc(ch, stdin);
  printf("char is %c\n ",getchar());

  return 0;
}