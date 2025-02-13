#include<stdio.h>
#include<stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE ( RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow","blue","magenta","cyan","white"};

struct box_property{
    bool opaque                  :1;
    unsigned int fill_color      :3;
    unsigned int                 :4;
    bool show_border             :1;
    unsigned int border_color    :3;
    unsigned int border_style     :2;
    unsigned int                 :2;
};


void show_settings(const struct box_property *pb){
    printf("Box is %s \n", pb ->opaque  == true ? "opaque": "transparent");
    printf("Fill is %s \n", colors[pb->fill_color]);
    printf("Border is %s \n", pb ->opaque  == true ? "visible" :"not visible");
    printf("Border color is %s \n", colors[pb->fill_color]);
    printf("Border style is: ");
    switch (pb->border_style)
    {
        case SOLID: 
            printf("solid\n"); 
            break;
        case DOTTED: 
            printf("dotted\n"); 
            break;
        case DASHED: 
            printf("dashed\n");
            break;
        default: printf("default:"); break;
    }
}

int main(){
    struct box_property box = {true,YELLOW,true,GREEN,DASHED};
    show_settings(&box);
    box.opaque = false;
    box.fill_color = WHITE;
    show_settings(&box);

    
    return 0;
}