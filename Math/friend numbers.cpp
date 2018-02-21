#include <iostream>
#include <stdio.h>
#include <math.h>



bool perfect(int n){

    int a=1;
    if(n%2==0)a=3;

    for(int i=3; i<n; i++){
       if (n%i==0) a+=i;
    }
    if(a==n) return 1;
    else return 0;
}

/*void perfectC(int n){
    int a=1;
    if(n%2==0)a=3;

    for(int i=3; i<n; i++){
       if (n%i==0) a+=i, printf(" i %d ",i);

    }
    printf(" a %d ",a);
}*/
int main ()
{
        int e= 1;
        int n;
        n=2^1(2^2-1);
        if (perfect(n))
        printf(" %d ",n);



}
