#include<stdio.h>
#include "StringFunctions.h"

int iFindFrequency(char *source, char searchCharacter){
    int frequency = 0;
    unsigned char ucCharacterCounter;
    for(ucCharacterCounter=0;source[ucCharacterCounter] != '\0'; ucCharacterCounter++){
        if(source[ucCharacterCounter] == searchCharacter){
            frequency++;
        }
    }
    return frequency;
}

int iRemoveAlphaString(char *source){
    int i,j = 0;
    for(i=0;source[i] != '\0';i++){
        while((source[i] >= 'a' && source[i] <= 'z') || (source[i] >= 'A' && source[i] <= 'Z')){
            for(j = i; source[j] != '\0'; ++j)
            {
                source[j] = source[j+1];
            }
            source[j] = '\0';
        }
    }
    return 0;
}

int iCalculateLength(char *source){
    int length = 0;
    for(length;source[length] != '\0';length++);
    return length;
}

void CopyString(char *sourceString, char *destinationString){
    unsigned char ucCharacterCounter;
    for(ucCharacterCounter=0; sourceString[ucCharacterCounter] != '\0'; ucCharacterCounter++){
        destinationString[ucCharacterCounter] = sourceString[ucCharacterCounter];
    }
    destinationString[ucCharacterCounter]='\0';
}

void ConcatenateString(char *sourceString, char *destinationString){
    unsigned char ucCharacterCounter, ucIndex;
    for(ucCharacterCounter=0; destinationString[ucCharacterCounter] != '\0'; ucCharacterCounter++){
        continue;
    }
    for(ucIndex=0; sourceString[ucIndex] != '\0'; ucIndex++){
        destinationString[ucCharacterCounter++] = sourceString[ucIndex];
    }
    destinationString[ucCharacterCounter] = '\0';
}
