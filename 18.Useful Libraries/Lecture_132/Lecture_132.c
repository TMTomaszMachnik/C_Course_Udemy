#include<stdlib.h>
#include<stdio.h>

// FILE *openFile (const char *file){
//     FILE *inFile;

//     if ((inFile = fopen(file, 'r')) == NULL){
//         fprintf(stderr, "cant open file for reading");
//         exit(EXIT_FAILURE); //Exit in case of error
//     }
//     return inFile;
// }

// void sign_off(void);
// void too_bad(void);

// int main(){
//     int n = 0;
//     atexit(sign_off);
//     puts("Enter an integer");
//     if(scanf("%d",&n) != 1) {
//         puts("Thats no integer");
//         atexit(too_bad);
//         exit(EXIT_FAILURE);
//     }
//     return 0;
// }

// void sign_off(void){
//     puts("Signing off...");
// }
// void too_bad(void) {
//     puts("in too_bad");
// }

int comp_ints(const void *, const void *);

int main(){
    int data[5] = {54, 3, 12, 9, 24};
    int comp_ints (const void *, const void *);
    qsort (data, 5, sizeof(int), comp_ints);
    for (int i = 0; i < 5; i++)
        printf("%d\n", data[i]);
}

int comp_ints (const void *p1, const void *p2) {
    const int i1 = * (const int *) p1;
    const int i2 = * (const int *) p2;
    return i1 - i2;
}