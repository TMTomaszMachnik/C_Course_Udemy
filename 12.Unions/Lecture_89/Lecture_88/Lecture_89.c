#include<stdio.h>

// union mixed {
//     char cValue;
//     float fValue;
//     int iValue;
// };

// union mixed x;

// union number
// {
//     int xValue;
//     double yValue;
// };

union student {
    char cletterGrade;
    int iroundedGrade;
    float fexactGrade;
};


int main(){
    // // union mixed x;
    // // x.cValue = 'j';
    // // x.fValue = 784.3323;
    // // //printf("Characeter = %c\n", x.cValue);
    // // printf("Float = %.2f", x.fValue);

    // union number value;
    // value.xValue = 100;
    // //value.yValue = 100;
    // printf("x = %d\n",value.xValue);
    // printf("y = %d",value.yValue);
    union student record1;
    union student record2;

    record1.cletterGrade = '8';
    record1.iroundedGrade = 87;
    record1.fexactGrade = 86.50;

    printf("Record1: \n");
    printf( "Letter grade: %c\n",record1.cletterGrade);
    printf( "Rounded grade: %d\n",record1.iroundedGrade);
    printf( "Exact grade: %.2f\n",record1.fexactGrade);

    printf("Record2: \n");
    record2.cletterGrade = 'A';
    printf( "Letter grade: %c\n",record2.cletterGrade);
    record2.iroundedGrade = 100;
    printf( "Rounded grade: %d\n",record2.iroundedGrade);
    record2.fexactGrade = 99.50;
    printf( "Exact grade: %.2f\n",record2.fexactGrade);
    return 0;
}