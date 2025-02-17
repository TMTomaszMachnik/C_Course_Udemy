#include<stdio.h>
#include<ctype.h>
#define SUM(x,y) ((x) + (y))
#define SQUARE(a) ((a)*(a))
#define CUBE(a) ((a)*(a)*(a))
#define IS_UPPER(ch) if(isupper(ch) == 1) printf("IT is uppercase\n");\
                     else printf("Either lowercase or invalid\n");                                   
                     
#define IS_LOWER(ch) if(islower(ch) == 1) printf("IT is lowercase\n");\
                     else printf("Either uppercase or invalid\n");   

void challenge_1(){
    printf("File %s line is %d\n",__FILE__, __LINE__);
    printf("Program last compiled at %s on %s\n", __TIME__, __DATE__);
    printf("Enter numbers: \n");
    
}

void challenge_2(){
    char buf[255];
    int ch = '\0';
    char *p = NULL;
    int num1, num2;
    if (fgets(buf, sizeof(buf),stdin)){
        p = strchr(buf,'\n');
        if(p){
        *p = '\0';
        }
        else{
            while(((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
        }
        if(sscanf(buf, "%d %d", &num1, &num2) == 2){
            printf("%d %d\n", num1,num2);
        }
    }
    printf("SUM is: %d", SUM(num1,num2));
}

void challenge_3(){
    char buf[255]; //Storing user input
    int ch = '\0'; //clearing extra input from stdinn
    char *p = NULL; //finding the newline character
    int iValue;
    if(fgets(buf,sizeof(buf),stdin)){
        p = strchr(buf, '\n');
        if(p) {
            *p = '\0';
        }
        else{
            while((ch = getchar()) != '\n');
        }
    }
    sscanf(buf, "%d", &iValue);
    printf("Square is: %d\n",SQUARE(iValue));
    printf("Cube is: %d\n",CUBE(iValue));
}

int main(){
    char ch;
    printf("please give me a char: ");
    scanf("%c",&ch);
    IS_LOWER(ch);
    IS_UPPER(ch);
    return 0;
}