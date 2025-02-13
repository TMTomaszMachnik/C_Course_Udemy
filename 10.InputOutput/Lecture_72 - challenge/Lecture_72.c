#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<string.h>

int main(){

  char *buffer = NULL;
  size_t buffsize = 32;
  size_t characters;
  FILE *fp;
  char path[255];
  char target = 'K';
  strcpy(path, "C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_72 - challenge\\data.txt");
  fp = fopen(path, "r");
  
  //buffer = (char *)malloc(buffsize * sizeof(char));
  while((characters = getline(&buffer,&buffsize,fp)) != EOF){
    if(buffer[0] == target) 
      printf("%s", buffer);
  }
  free(buffer);
  fclose(fp);
  return 0;
}