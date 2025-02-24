#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    //int value = atoi(a); //atoi(char const *)
    //float value = atof(a); //atof(char const *)
    //printf("Value = %f\n",value);
    // sprintf(a, "%d", 45);
    
    // printf("Value = %s\n",a);


    // char *a = "123.456xyz",*end;
    // double value = 0;
    // value = strtod(a, &end);
    // printf("Value = %lf\n", value);

    // char *a = "365.25 7.0",*end;
    // float value_1 = strtof(a, &end);
    // float value_2 = strtof(end, NULL);
    // printf("Value = %f, %f", value_1, value_2);

    // char str[] = "2137 Styrta sie pali";
    // char *ptr = NULL;
    // long ret = 0;
    // ret = strtol(str, &ptr, 10);
    // printf("Number is: %ld\n", ret);
    // printf("String is: %s", ptr);

    srand(time(0));

    for(int i = 0; i < 10; i++)
        printf(" %d", rand() % 5 + 1);
    printf("\n");
    return 0;
}