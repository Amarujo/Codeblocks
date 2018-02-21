#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "libgame.h"

//int snake[][]={{15,15},{16,15},{17,15}};int snake[100][2];
//snake[0][0]=l5; snake[0][1]=l5;
//snake[1][0]=l6; snake[1][1]=l5;
//snake[2][0]=l7; snake[2][1]=l5;
int tam = 5;
int n=0;
int x=15, y=10;

char tecla='d';
int direccion=2;

int comX=20, comY=15;

void teclear(){
    if(kbhit()){
            tecla = getch();
            switch (tecla){
            case 72:
                if(direccion!=0) direccion=1;
                break;
            case 80:
                if(direccion!=1) direccion=0;
                break;
            case 75:
                if(direccion!=2) direccion=3;
                break;
            case 77:
                if(direccion!=3) direccion=2;
                break;

            }

        }

}

void moveSnake(){
    snake[n][0]=x;
    snake[n][1]=y;
    n++;
    if(n==tam) n=0;



}

void putSnake(){
    gotoxy(snake[n][0], snake[n][1]); printf(" ");


    moveSnake();
    for(int i=0; i<tam; i++){//try change order
        gotoxy(snake[i][0], snake[i][1]); printf("%c", 254);
    }


}



void comida(){
    if(x==comX && y==comY) {
            tam++;
            comX = rand()%70+4;
            comY = rand()%20+3;
            gotoxy(comX,comY); printf("*");
    }
}

bool game_over(){
    if(y==-1||y==25) return false;
    if(x==-1||x==80) return false;
    return true;
}

int main(){
    OcultaCursor();
    gotoxy(comX,comY); printf("*");
//        snake[0][0]=l5; snake[0][1]=l5;
//        snake[1][0]=l6; snake[1][1]=l5;
//        snake[2][0]=l7; snake[2][1]=l5;
    while(tecla!=ESC && game_over()){
        teclear();
        putSnake();
        comida();
        teclear();

        if(direccion==1) y--;
        if(direccion==0) y++;
        if(direccion==3) x--;
        if(direccion==2) x++;
//        teclear();

    pausa(100);
    }
    pausa(900);
}
