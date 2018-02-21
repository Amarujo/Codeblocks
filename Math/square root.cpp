#include<stdio.h>
#include<iostream>

using namespace std;

double raiz(double x){
    double r = x, t = 0;
    while (t != r){
        t = r;
        r = (x/r + r)/2;
    }
    return r;
}

int main()
{
    cout<<raiz(144);
}
