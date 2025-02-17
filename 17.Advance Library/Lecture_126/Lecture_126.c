#include <stdio.h>
#include <string.h>
#include "StringFunctions.h"

int main()
{
    char temp[] = "jason &&''''Fedin";
    char temp2[] = "apple";
    char temp3[100];

    char tempCopy1[100], tempCopy2[100];

    strcpy(tempCopy1, temp);
    strcpy(tempCopy2, temp2);

    printf("Number of 'p's in apple is %d\n", iFindFrequency(tempCopy2, 'p'));

    iRemoveAlphaString(tempCopy1);
    printf("String tempCopy1 with alpha characters removed is: %s\n", tempCopy1);
 
    printf("String tempCopy1 length is: %d\n", iCalculateLength(tempCopy1));

    strcpy(tempCopy1, temp); 
    ConcatenateString(tempCopy2, tempCopy1);
    printf("String tempCopy1 concatenated with tempCopy2 is: %s\n", tempCopy1);

    CopyString(tempCopy2, temp3);
    printf("String copied is: %s\n", temp3);
  
    return 0;
}
