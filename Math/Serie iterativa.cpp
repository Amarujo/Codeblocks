#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;

int main (){
    long nro, cop;
    cout<<"Ingrese un nro:";
    scanf("%d", &nro);
    while(1){
        cout<<nro<<" ";
        if (nro%2==0) nro/=2;
        else cop=nro*3+1, nro=cop/2;
        //nro/=(nro%2==0)?2:2/(3+1/nro);
        Sleep(20);
    }
    return 0;
}
