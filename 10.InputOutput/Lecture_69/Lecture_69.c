#include<stdio.h>
#include<ctype.h>


int main() {

    //PUTC

    // int ch;
    // FILE *fp = fopen("C:\\Users\\kmach\\.vscode\\VSC_Programms\\C_Advanced\\Lecture_69\\dupa.c", "r+");

    // if (fp != NULL) {
    //     while ((ch = getc(fp)) != EOF) {
    //         putchar(ch); 
    //         putc(ch, fp); 
    //     }
    //     fclose(fp);
    // } else {
    //     printf("Error opening file.\n");
    // }


    //PUTCHAR
    // char string[] = "Hello there";
    // int i = 0;
    // while(string[i] != '\0'){
    //   if(string[i] != '\n')
    //     putchar(string[i]);
    //     i++;
    // }

    int ch = 0;
    while((ch = getchar()) != EOF)
      putchar(ch);
    ungetc(ch,stdin);
    printf("tahnk you");

    return 0;
}