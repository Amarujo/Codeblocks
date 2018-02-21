#include<stdio.h>
#include<iostream>

using namespace std;

double raiz(double x){
    double r = x, t = 0;
    while (t != r){
        t = r;
        r = (x/(4*r) +3*r)/4;
    }
    return r;
}

int main()
{
    int num;
    cout<<"Insert a number"<<endl;
    cin>>num;
    cout<<raiz(num);
}
