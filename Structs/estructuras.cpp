#include<iostream>
#include<stdio.h>

using namespace std;

void readString(char a[]){
    for(int i =0; i < sizeof(a); i++){
        a[i] = getchar();
        if(a[i]=='\n') break;
    }
}

void wString(char *a){
    for(int i = 0; (*a[i] = getchar()!='\n'); ++i){
}
}

int main (void){
    printf("hello world");

    char nombre[20];
//    readString(nombre);
    wString(&nombre);


printf(nombre);

//    struct alumno{
//        int edad;
//        char *nombre;
//    };


    return 0;
}
