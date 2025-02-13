#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 5
#define COLS 5
// int main(){


//     size_t rows = 0;
//     size_t columns = 0;

//     printf("Enter tthe number of elements: ");
//     scanf("%zd", &rows);
//     printf("Enter tthe number of elements: ");
//     scanf("%zd", &columns);

//     float values[rows][columns];
//     return 0;
// }

void array(int size){
    char alpha[size];
    int x = 0;

    while(x<size) {
        alpha[x] = 'A' + x;
        printf("alpha is: %c\n", alpha[x]);
        x++;
    }
}

int sum2d(int rows, int cols, int array[rows][cols]){
    int r;
    int c;
    int tot = 0;

    for (r=0; r<rows;r++)
        for (c=0;c<cols;c++)
            tot += array[r][c];
    return tot;
}

int main() {
    srand(time(NULL));
    int array[ROWS][COLS];
    for(int rowNum=0;rowNum<ROWS;rowNum++)
        for(int colNum=0;colNum<COLS;colNum++)
            array[rowNum][colNum] = (rand() % (100));
        
    for (int i = 0; i < ROWS; i++){ 
        for (int j = 0; j < COLS; j++){ 
            printf("%4d", array[i][j]);
        }
        printf("\n"); 
    }
    int total = sum2d(ROWS,COLS,array);
    printf("%d", total);
}