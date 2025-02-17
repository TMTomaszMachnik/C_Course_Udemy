#include <stdlib.h>
#include <stdio.h>

#include "StringFunctions.h"

int main()
{

  char temp[] = "jason &&''''Fedin";
  char temp2[] = "apple";
  char temp3[100];

  printf("Number of 'p's in apples is %d\n", iFindFrequencySting(temp2, 'p'));

  iRemoveNonAlphaCharacters(temp);
  printf("String temp with alpha characters removed is: %s\n", temp);
 
  printf("String temp length is: %d\n", iCalculateStringLength(temp));
 
  ConcatenateString(temp, temp2);
  printf("String concatenated with string2 is: %s\n", temp);

  CopyString(temp2, temp3);
  printf("String copied is: %s\n", temp3);
  return 0;
}
