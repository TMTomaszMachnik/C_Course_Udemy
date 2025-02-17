#include<stdio.h>

struct owner {
    char socsecurity[12];
}

struct leasecomp {
    char name[40];
    char headdquarters[40];
};

struct car_data {
    char make[15];
    int status;
    union {
        struct owner owncar;
        struct leasecomp leasecar; //Anonymus union
    }
}

union car {
    int iValue;
    float fValue;
    char cValue[40];
}car1, car2, *car3;

int main()
{
    //union car car1, car2, *car3;
    printf("Memory size is: %zu\n", sizeof(car1));

    return 0;
}