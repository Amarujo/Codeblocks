#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int variable=12;
    int *puntero = &variable;
    int arreglo[5];
    int *punteroArray = arreglo;


    cout<<arreglo<<endl;
    punteroArray+=4;
    cout<<punteroArray<<endl;
    *puntero=15;
    cout<<variable;
}
