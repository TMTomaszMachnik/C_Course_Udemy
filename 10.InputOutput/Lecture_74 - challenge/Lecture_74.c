#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(){

  FILE *fp;
  char path[255];
  int num;
  strcpy(path,"C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_74 - challenge\\numbers.txt");
  if((fp = fopen(path, "r+")) == NULL){
    fprintf(stderr,"Not accesible");
    fclose(fp);
    exit(1);
  }
  else
  {
    printf("Read succesfull\n");
    while((fscanf(fp,"%d",&num)) != EOF){
      if(num%2 == 0)  printf("Even number detected %d\n", num);
      else printf("Odd number detected %d\n", num);
    }
  }

  if(fclose(fp) != 0)
    fprintf(stderr, "error closing file");

  return 0;
}