#include<stdio.h>

main(){
    char linea[80];
//    scanf("%[ avcdefghijklmnopqrstuvwxy]", linea);
    scanf("%[^\n]", linea);
    printf("%s",linea);

//    char* texto;
//    scanf("%s",&texto);
//    printf("%s",texto);
}
