#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
int main(){
  //FGETS

  // char buf[255];
  // int ch = '\0';
  // char *p = NULL;

  // if (fgets(buf, sizeof(buf),stdin)){
  //   p = strchr(buf,'\n');
  //   if(p){
  //     *p = '\0';
  //   }
  //   else{
  //     while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
  //   }
  // }
  // printf("%s", buf);
  // return 0;

  //GETLINE
  // char *buffer = NULL;
  // size_t buffsize = 32;
  // size_t characters;

  // buffer = (char *)malloc(buffsize * sizeof(char));

  // if( buffer == NULL){
  //   exit(1);
  // }

  // printf("Write sth: ");
  // characters = getline(&buffer,&buffsize,stdin);
  // printf("%zu characters were read: \n",characters-1);
  // printf("You typed %s",buffer);

  //PUTS
  // char string[40];
  // strcpy(string, "Hello how are you");
  // puts(string);
  FILE *fp = NULL;
  fp = fopen("somefile.txt", "w+");
  if(fp == NULL){
    exit(1);
  }
  fputs("Hello  there",fp);
  fclose(fp);
  return 0;
}