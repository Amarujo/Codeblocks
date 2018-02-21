#include <iostream>
#include <stdio.h>
using namespace std;

//Funcion para hallar la posicion (indice) del menor elemento de un arreglo
int menor(int x[], int k, int tam){
int m=x[k],c=0;
for(int i=k; i<tam; i++)
{
    if(x[i]<=m){
        m=x[i];
        c=i;
    }
}
return c;
}

//Prueba de funcion "menor" (IRRELEVANTE)
void menorp(int x[], int k, int tam){
int m=x[k],c=0;

for(int i=k; i<tam; i++)
{
    printf("%d",i);
    if(x[i]<=m){
        m=x[i];
        c=i;
    }
}

}


int main (){


cout<<"Ingresa tamaño del arreglo: "<<endl;
int tam;
cin>>tam;

int A[tam],k,cop,posm;

for(k=0; k<tam; k++)
{
    printf("Ingrese valor %d: ",k+1);
    scanf("%d",&A[k]);
}

//Rutina metodo seleccion
for(k=0; k<tam-1; k++)
{
    //irrelevante
    menorp(A,k,tam);
    cout<<"        ";
    //irrelevante

    posm=menor(A,k,tam);

    //irrelevante
    cout<<" "<<posm<<endl;
    //irrelevante

    cop=A[k];
    A[k]=A[posm];
    A[posm]=cop;
}

printf("\n\t");
for(k=0; k<tam; k++)
{
    printf("%d ",A[k]);

}

}
