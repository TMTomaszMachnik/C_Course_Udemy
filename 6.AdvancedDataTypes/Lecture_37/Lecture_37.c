#include <stdio.h>

int main() {

    size_t size;
    printf("Put the size of an array: ");
    scanf("%zu", &size);
    int array[size];
    int element=0;
    int sum = 0;

    printf("Enter %d elements:\n", size);    
    for(int elementNum=0; elementNum<size; elementNum++){
        printf("Enter %d element: ", elementNum);
        scanf("%d", &array[elementNum]);
        sum += array[elementNum];
    }
    printf("%d", sum);
}