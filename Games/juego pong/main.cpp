#include <stdio.h>
#include <conio.h>
#include "libgame.h"



int x=2;
int y=20;
int xAdd=2;
int yAdd=1;

int jugadorX=1;
int jugadorY=15;

int jugador2X=77;
int jugador2Y=15;
char tecla;


int score1=0;
int score2=0;


void pintar_pelota(){

        x+=xAdd;
        y+=yAdd;
        gotoxy(x,y);
        printf("%c",184);
        pausa(60);
        gotoxy(x, y);
        printf(" ");

        if(x==jugadorX+1 && (y==jugadorY-1 || y==jugadorY || y==jugadorY+1 )) xAdd=-xAdd;
        if(x==jugador2X-1 && (y==jugador2Y-1 || y==jugador2Y || y==jugador2Y+1 )) xAdd=-xAdd;

        if(x==0){
            x=70;
            printf("\a");
            gotoxy(75,24); printf(" "); printf("%d",++score2);
        }

        if(x==78){
            x=8;
            printf("\a");
            gotoxy(3,24); printf(" "); printf("%d",++score1);
        }

        if(y==23) yAdd=-yAdd;
        if(x==78) xAdd=-xAdd;
        if(yAdd<0 && y==0) yAdd=-yAdd;
        if(xAdd<0 && x==0) xAdd=-xAdd;




}

void mover_jugador(){
    gotoxy(jugadorX, jugadorY-1); printf(" ");
    gotoxy(jugadorX, jugadorY);   printf(" ");
    gotoxy(jugadorX, jugadorY+1); printf(" ");

    tecla=getch();
            if(tecla=='q' && jugadorY>2)jugadorY-=1;
            if(tecla=='a' && jugadorY<22)jugadorY+=1;

        gotoxy(jugadorX, jugadorY-1); printf("%c",219);
        gotoxy(jugadorX, jugadorY);   printf("%c",219);
        gotoxy(jugadorX, jugadorY+1); printf("%c",219);

}

void pintar_jugador(){

        gotoxy(jugadorX, jugadorY-1); printf("%c",219);
        gotoxy(jugadorX, jugadorY);   printf("%c",219);
        gotoxy(jugadorX, jugadorY+1); printf("%c",219);

        gotoxy(jugador2X, jugador2Y-1); printf("%c",219);
        gotoxy(jugador2X, jugador2Y);   printf("%c",219);
        gotoxy(jugador2X, jugador2Y+1); printf("%c",219);

        if(kbhit()){

//            mover_jugador();
            gotoxy(jugadorX, jugadorY-1); printf(" ");
            gotoxy(jugadorX, jugadorY);   printf(" ");
            gotoxy(jugadorX, jugadorY+1); printf(" ");

            gotoxy(jugador2X, jugador2Y-1); printf(" ");
            gotoxy(jugador2X, jugador2Y);   printf(" ");
            gotoxy(jugador2X, jugador2Y+1); printf(" ");
            /////////////////////////////////////////////

            tecla=getch();
            if(tecla=='q' && jugadorY>2)jugadorY-=1;
            if(tecla=='a' && jugadorY<22)jugadorY+=1;

            if(tecla=='p' && jugador2Y>2)jugador2Y-=1;
            if(tecla=='l' && jugador2Y<22)jugador2Y+=1;
            /////////////////////////////////////////////////

            gotoxy(jugadorX, jugadorY-1); printf("%c",219);
            gotoxy(jugadorX, jugadorY);   printf("%c",219);
            gotoxy(jugadorX, jugadorY+1); printf("%c",219);

            gotoxy(jugador2X, jugador2Y-1); printf("%c",219);
            gotoxy(jugador2X, jugador2Y);   printf("%c",219);
            gotoxy(jugador2X, jugador2Y+1); printf("%c",219);
        }

}

//void pintar_jugador2(){
//
//        gotoxy(jugador2X, jugador2Y-1); printf("%c",219);
//        gotoxy(jugador2X, jugador2Y);   printf("%c",219);
//        gotoxy(jugador2X, jugador2Y+1); printf("%c",219);
//
//        if(kbhit()){
//
////            mover_jugador2();
//            gotoxy(jugador2X, jugador2Y-1); printf(" ");
//            gotoxy(jugador2X, jugador2Y);   printf(" ");
//            gotoxy(jugador2X, jugador2Y+1); printf(" ");
//
//            tecla=getch();
//            if(tecla=='p' && jugador2Y>2)jugador2Y-=1;
//            if(tecla=='l' && jugador2Y<22)jugador2Y+=1;
//
//            gotoxy(jugador2X, jugador2Y-1); printf("%c",219);
//            gotoxy(jugador2X, jugador2Y);   printf("%c",219);
//            gotoxy(jugador2X, jugador2Y+1); printf("%c",219);
//        }
//
//}



int main(){
    OcultaCursor();
    while(true){
    pintar_jugador();

    pintar_pelota();
    }
    pintar_marco();
    //pausa();
    pausa(900);
}




