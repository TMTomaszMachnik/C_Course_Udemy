#include<stdio.h>
#include<complex.h>
#include<math.h>

int main(){

    double complex cx = 1.0 + 3.0*I;
    double complex cy = 1.0 - 4.0*I;
    printf("Starting values: cx = %.2f%+.2fi cy=%.2f%+.2fi\n", creal(cx),cimag(cx),creal(cy),cimag(cy));
    
    double complex sum = cx+cy;
    printf("Sum value: sum = %.2f%+.2fi\n", creal(sum), cimag(sum)); 

    double complex difference = cx-cy;
    printf("Sum value: difference = %.2f%+.2fi\n", creal(difference), cimag(difference)); 
    
    double complex product = cx*cy;
    printf("Sum value: product = %.2f%+.2fi\n", creal(product), cimag(product)); 

    double complex quotient = cx-cy;
    printf("Sum value: quotient = %.2f%+.2fi\n", creal(quotient), cimag(quotient)); 
    
    double complex conjugate = conj(cx);
    printf("Sum value: conjugate = %.2f%+.2fi\n", creal(conjugate), cimag(conjugate)); 
    
    double complex z1 = I * I;     
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    double complex z2 = pow(I,2);     // imaginary unit squared
    printf("I * I = %.1f%+.1fi\n", creal(z2), cimag(z2));
    
    double omega = acos(-1)/2;
    double complex z4 = cos(omega) + I*sin(omega);
    printf("Euler(I*PI) = %.1f%+.1fi\n", creal(z4), cimag(z4));
    
    return 0;
}