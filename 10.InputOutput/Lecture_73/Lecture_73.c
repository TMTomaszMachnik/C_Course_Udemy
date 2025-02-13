#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX 41

int main(){
  //SPRINTF

  // char string[100];
  // int a = 10, b = 20, c = 0;
  // c = a + b;
  // //sprintf(string, "hello this is the number: %d", 55);
  // sprintf(string, "Sum of %d and %d is %d", a, b, c);
  // puts(string);


  //FPRINTF
  
//   FILE *f = NULL;
//   char path[255];
//   char ch[100];
//   strcpy(path, "C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_73\\data.txt");
//   if((f = fopen(path, "r+")) ==  NULL){
//     printf("File cant be opened");
//     exit(1);
//     fclose(f);
//   }
//   else
//   {
//     for(int i = 1; i<10; i++){
//       fprintf(f,"The count number is: %d\n", i);
//     }
//     fclose(f);
//   }

//   printf("File content is --\n");
//   printf("\n...... print the strings ......... \n\n");

//   if((f = fopen(path, "r+")) ==  NULL){
//     printf("File cant be opened");
//     exit(1);
//     fclose(f);
//   }
//   else{
//   while(!feof(f)){
//     fgets(ch,100,f);
//     printf("%s",ch);
//     }
//     fclose(f);
//   }
//   return 0;
// }

//FPRINT F with stdin

  // FILE *fp = NULL;
  // char words[MAX];
  // char buf[100];
  // if((fp = fopen("data1.txt", "a+")) == NULL){
  //   fprintf(stdout, "Unable to acces file\n");
  //   exit(1);
  // }

  // while(fscanf(fp,"%s",buf) != EOF){
  //   printf("%s ", buf);
  // }

  // puts("Enter words to append to file; press the #");
  // puts("Key at the beggining of a line to terminate.");
  // while ((fscanf(stdin,"%40s",words) == 1) && (words[0] != '#'))
  // {
  //   fprintf(fp, "%s\n", words);
  // }
  // puts("File contents: ");
  // rewind(fp); //Takes program to the begginig of the file! resseting the pointer
  // while(fscanf(fp,"%s",words) != EOF)
  //   puts(words);
  // puts("done");

  // if(fclose(fp) != 0)
  //   fprintf(stderr, "error closing file");

  char *str = "Tomasz Student 19";
  char name[10], title[10];
  int age = 0, ret =0;

  ret = sscanf(str, "%s %s %d", name, title, &age);

  printf("Name: %s\n", name);
  printf("Title: %s\n", title);
  printf("Age: %d\n", age);
return 0;
}