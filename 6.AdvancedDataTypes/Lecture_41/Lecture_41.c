#include<stdio.h>

struct point{int x, y, z;};
int main(){

    // int numbers[] = {1,2,3, [10] = 80, 15, [70] = 50, [42] = 400};
    // // for (int i=0;i<20;i++)
    // //     printf("%d ",numbers[i]);
    // //     printf("\n%d",numbers[70]);
    // //     printf("\n%d",numbers[42]);
    // int n = sizeof(numbers) / sizeof(numbers[0]);
    // printf("%d", n);
    // return 0;


    // struct point p = {.y=2, .x=3, .z=5};
    // printf("x = %d, y = %d, z = %d", p.x, p.y, p.z);


    struct point pts[5] = {
        [2].y = 5,
        [2].x = 6,
        [0].x = 2
    };
    for(int i=0;i<5;i++){
        printf("%d %d\n", pts[i].x, pts[i].y);
    }
    return 0;
}