#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

int main (void){
//    int a = 6;
//    int *pa = &a;
//
//    printf("%d", *pa);

    int tamano=0;
    char *nombre;
    printf("ingresa tamano: ");
    scanf("%d", tamano);
    nombre = (char *) malloc(tamano * sizeof(char));
    for (int i = 0; i < tamano; i++){
        scanf("%c", (nombre + i));

    }
    return 0;

}
