#include <stdio.h>
#include <conio.h>
#include "libgame.h"


class Nave{
    int x, y;
public:
    Nave(int _x, int _y): x(_x), y(_y){}
    void pintar();
    void borrar();
    void mover();
};

//Nave::Nave(int _x, int _y): x(_x), y(_y){}

void Nave::pintar(){
    gotoxy(x, y); printf("  %c", 30);
    gotoxy(x, y+1); printf(" %c%c%c", 40,207,41);
    gotoxy(x, y+2); printf("%c%c %c%c", 30,190,190,30);
}

void Nave::borrar(){
    for(int i=0; i<3; i++){
    gotoxy(x, y+i); printf("     ");
    }
}

void Nave::mover(){
    if(kbhit()){
        borrar();
        char tecla = getch();
        if(tecla==DERECHA)   x++;
        if(tecla==IZQUIERDA) x--;
        if(tecla==ABAJO)     y++;
        if(tecla==ARRIBA) y--;
        pintar();
    }
}

int main(){
    OcultaCursor();

    Nave e(7,7);
    e.pintar();
    while(1){
    e.mover();
    }
    pintar_marco();
    //pausa();
    pausa(900);
}
