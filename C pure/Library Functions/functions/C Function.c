#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int i=8, j=5;
double x = 0.005, y = -0.01;
char c = 'c', d = 'd';



int main(){
    //printf("%d",abs(i-2*j));printf("%c",c);
    c= getchar();
    putchar(c);

    printf("%f\t%f\n%f",sin(x),cos(y),sqrt(sin(x)+cos(y)));
    return 0;
}
