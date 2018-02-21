#include <stdio.h>

int main (){
    int i;
    for(i=1; i<=10; i++){
        printf((i%2!=0)?"es impar, ":" %d ,",i);
    }
    return 0;

}
