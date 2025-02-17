#include<stdio.h>

int iFindFrequencySting(char *str, char searchString){

    int frequency = 0;
    for(int i = 0; str[i]!= '\0'; i++){
        if(searchString==str[i]){
            frequency++;
        }
    }
    return frequency;
}

int iRemoveNonAlphaCharacters(char *source)
{
    int i = 0, j = 0;

    for(i = 0; source[i] != '\0'; ++i)
    {
        while (!( (source[i] >= 'a' && source[i] <= 'z') || (source[i] >= 'A' && source[i] <= 'Z') || source[i] == '\0') )
        {
            for(j = i; source[j] != '\0'; ++j)
            {
                source[j] = source[j+1];
            }
            source[j] = '\0';
        }
    }
}

int iCalculateStringLength(char *source){
    int length=0;

    for(int i = 0; source[i] != '\0'; i++){
        length++;
    }

    return length;
}

void CopyString(char sourceString[], char destinationString[]){

    unsigned char ucCharacterCounter;
    for(ucCharacterCounter; destinationString[ucCharacterCounter] != '\0'; ucCharacterCounter++){
        destinationString[ucCharacterCounter] = sourceString[ucCharacterCounter];
    }
}

void ConcatenateString(char sourceString[], char destinationString[]){

    unsigned char ucCharacterCounter;
    for(ucCharacterCounter = 0; destinationString[ucCharacterCounter] != '\0'; ucCharacterCounter++){
        continue;
    }
    CopyString(sourceString,&destinationString[ucCharacterCounter]);
}

