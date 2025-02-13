#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
enum selection{fileread, stdinread};

void challenge_1(enum selection eSelection){
  int ch = 0;
  int characters = 0;
  int words = 0;
  FILE * fp;

  switch (eSelection){
    
    case(stdinread): 
    while((ch = getchar()) != EOF){
      if(ch == ' ' || ch == '\n'){
        words += 1;
      }
      else{
        characters += 1;
      }
    }
  break;

  case(fileread):
  fp = fopen("C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_70 - challenge\\data.txt", "r");
  if( fp != NULL){
    while((ch=getc(fp)) != EOF){
      if(ch == ' ' || ch == '\n'){
        words += 1;
      }
      else{
        characters += 1;
      }
    }
  }
  break;
  default:
    break;
  }
  printf("%d\n",characters);
  printf("%d\n",words);
}


void convertCase(FILE *fptr, const char *path)
{
    FILE *dest = NULL;
    char ch = '\0';

    dest = fopen("temp.txt", "w");

    if (dest == NULL)
    {
        printf("Unable to create temporary file.");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }

    while ( (ch = fgetc(fptr)) != EOF)
    {
        if (isupper(ch))
            ch = tolower(ch);
        else if (islower(ch))
            ch = toupper(ch);

        fputc(ch, dest);
    }

    fclose(fptr);
    fclose(dest);

    remove(path);

    rename("temp.txt", path);
}

void challenge_2(){
    FILE *fPtr = NULL;
    char path[200];

    strcpy(path, "C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_70 - challenge\\change.txt");
    fPtr = fopen(path, "r");
    convertCase(fPtr, path);
}



int main(){
  //challenge_1(stdinread);
  challenge_2();
  return 0;
}