#include<stdio.h>

main(){
//    char letras[80];
//    int cont, auxiliar;
//
//    for(cont =0; (letras[cont] = getchar())!='\n'; ++cont)
//
//    ;
//
//    auxiliar = cont;
//
//    for(cont=0; cont<auxiliar; ++cont)
//        putchar(toupper(letras[cont]));
int enter[80];
    int cont, auxiliar;

    for(cont =0; (enter[cont] = getchar())!='\n'; ++cont)

    ;

    auxiliar = cont;

    for(cont=0; cont<auxiliar; ++cont)
        printf("%d,  %c\n",enter[cont],enter[cont]);

}
