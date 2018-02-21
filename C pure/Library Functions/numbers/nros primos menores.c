#include <stdio.h>

int main (){

    int num;  //"comentario" variable que contendra nro proveido por el usuario
    int i, i2;  //iteradores de las sentencias for
    int cont=0; //contador de posibles divisores

    printf("Introduce nro, se devolvera los dos primeros primos: ");
    scanf("%d", &num);

    if(num >=1)  printf("1 ");
    else {
        while(num < 1){
            printf("El nro debe ser mayor a cero: ");
            scanf("%d", &num);
        }
    }
    for(i = 2; i <= num; i++){   //bucle de nros que empieza con el nro introducido y va decreciendo
        for(i2 = 1; i2 <= i; i2++){  //bucle de posibles divisores
             if(i % i2 == 0){
                 cont++;  //contador en caso de encontar un divisor
             }
        }
        if(cont == 2){  //si cont es igual a cero significa que i no tiene divisores distintos al mismo y la unidad
            printf("%d ",i);  //imprimos nro primo

        }
        cont=0;

   }
}
