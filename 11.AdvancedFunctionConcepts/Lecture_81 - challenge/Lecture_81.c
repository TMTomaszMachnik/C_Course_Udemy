#include<stdio.h>
#include<stdarg.h>
#include<math.h>

void print(const char *format, ...){
    va_list args;
    va_start(args,format);
    while(*format){
        if(*format == '^'){
            format++;
        switch (*format)
        {
        case 'd':{
            int num  = va_arg(args,int);
            char buffer[20];
            sprintf(buffer,"%d",num);
            for(char *ptr = buffer; *ptr; ptr++){
                putchar(*ptr);
            }
            break;
        }
        case 'c':{
            char ch = (char)va_arg(args,int);
            putchar(ch);
            break;
        }
        default:
            putchar('^');
            putchar(*format);
            break;
        }
    }
    else{
        putchar(*format);
    }
    format++;
    }
    va_end(args);
}

double challenge(int number1,int number2, ...){
    va_list parg;
    double sum = number1 + number2;
    double value = 0.0;

    va_start(parg,number2);

    while ((value = va_arg(parg,double)) != 0.0)
    {
        sum += value;
    }
    va_end(parg);
    return sum;
}

int main(){
    print("^d\n",(int)challenge(4,5,8.0,0.0));
    return 0;
}
