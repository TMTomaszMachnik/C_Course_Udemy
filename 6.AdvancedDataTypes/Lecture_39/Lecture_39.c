#include<stdio.h>
#include<malloc.h>
struct myArray{
    int arraySize;
    int array[];
};

int main()
{
    struct myArray *ptr; //setting pointer for myArray adress
    int desiredSize;
    printf("Select desired size: ");
    scanf("%d", &desiredSize);
    
    ptr = malloc(sizeof(struct myArray) + desiredSize*sizeof( int ));

    ptr -> arraySize = desiredSize;

    for(int elementNum = 0; elementNum < desiredSize; elementNum++){
        printf("First Number: ");
        scanf("%d", &ptr->array[elementNum]);
    }

    for(int elementNum = 0; elementNum < desiredSize; elementNum++){
        printf("Element %d is %d\n",elementNum, ptr->array[elementNum]);
    }
    
    return 0;
}