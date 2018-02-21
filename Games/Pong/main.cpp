#include <stdio.h>
#include "libgame.h"

int main(){
    OcultaCursor();
    Color(ROJO);
    inicia_libgame();
    Color(AMARILLO);
    gotoxy(22,8); printf("Aporte echo por David Mendoza Velis");
    Color(AZUL);
    gotoxy(22,15); printf("http://creatusjuegosdecero.webege.com");
    Color(VERDE2);
    gotoxy(20,13); printf("http://www.youtube.com/user/deividcoptero");
    Color(MORADO);
    pintar_marco();
    //pausa();
    pausa(900);
}
