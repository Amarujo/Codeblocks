#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

bool primo (int nro){
    int cop=nro;
    int root=sqrt(nro)+1;
    bool bol=0;

    for(int i=2; i<=root; (i<=2)?i++:i+=2){
        if(nro%i==0) bol=1; break;
    }
    return bol;
}

void factors(int nro){
    int root=sqrt(nro);
    printf("1  ");
    for(int i=2; i<=root; (i==2)?i++:i+=2){
        while(nro%i==0){
            printf("%d  ",i);
            nro/=i;
        }
    }
    if (nro>1) printf("%d",nro);
}

int main(){
    int num;
    cout<<"Introduce un valor:"<<endl;
    cin>>num;
    //(primo(num)==1)?factors(num):printf("\nes primo; facts: 1,    %d",num);
    factors(num);
return 0;
}
