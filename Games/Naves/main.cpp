#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include "libgame.h"
#include <windows.h>


void gotoxy(int x, int y)  // funcion que posiciona el cursos en la coordenada (x,y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void OcultaCursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE}; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Color(int color){
	static HANDLE hConsole;
    hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hConsole, color | (0 * 0x10 + 0x100) );
}

void pintar_marco()       // funcion que pinta los limites del escenario
{
     // Lineas horizontals
     for(int i=2; i < 78; i++){
        gotoxy (i, 3); printf ("%c", 205);
        gotoxy(i, 23); printf ("%c", 205);
     }
     //Lineas verticales
     for(int v=4; v < 23; v++){
        gotoxy (2,v);  printf ("%c", 186);
        gotoxy(77,v);  printf ("%c", 186);
     }
     // Esquinas
     gotoxy  (2,3);    printf ("%c", 201);
     gotoxy (2,23);    printf ("%c", 200);
     gotoxy (77,3);    printf ("%c", 187);
     gotoxy(77,23);    printf ("%c", 188);
}

void pausa(int x){
    Sleep(x);

}

void pausa(){
    getch();
}



char nave1[] = {' ',' ','*',' ',' ',0};
char nave2[] = {' ','*','*','*',' ',0};
char nave3[] = {'*',' ','*',' ','*',0};

char borrar[] = {' ',' ',' ',' ',' ',0};

char aExplosion[]  = {' ',' ',' ',' ',' ',0};
char aExplosion2[] = {' ',' ','*',' ',' ',0};
char aExplosion3[] = {' ',' ',' ',' ',' ',0};

char bExplosion[]  = {' ',' ','*',' ',' ',0};
char bExplosion2[] = {' ','*',' ','*',' ',0};
char bExplosion3[] = {' ',' ','*',' ',' ',0};

char cExplosion[]  = {' ','*',' ','*',' ',0};
char cExplosion2[] = {'*',' ','*',' ','*',0};
char cExplosion3[] = {' ','*',' ','*',' ',0};

int x=20, y=20;
char tecla;


int vidas=3;
int salud=3;

int astX=15, astY=4;
int astX2=4, astY2=15;
int astX3=60, astY3=22;
int astX4=35, astY4=8;

int balaX=20, balaY=y;
bool disparo=false;

int puntos=0;
int velocidad=100;

void pintarNave(int x, int y){

        gotoxy(x, y); printf(nave1);
        gotoxy(x, y+1); printf(nave2);
        gotoxy(x, y+2); printf(nave3);


}


void borrarNave(int x, int y){

        gotoxy(x, y); printf(borrar);
        gotoxy(x, y+1); printf(borrar);
        gotoxy(x, y+2); printf(borrar);

}

void pintarVida(int vida){
    gotoxy(3, 2); printf("Vida: ");
    gotoxy(9, 2); printf(" ");
    gotoxy(9, 2); printf("%d", vida);
}


void pintarSalud(int _salud){
    if(_salud<0){
        pintarVida(--vidas);
        salud=3; _salud=3;
    }
    gotoxy(63, 2); printf("Salud: ");
    for(int i=0; i<3; i++){
        gotoxy(70+i, 2); printf(" ");
    }
    for(int i=0; i<_salud; i++){
        gotoxy(70+i, 2); printf("%c", 225);
    }
}


void explotar(int x, int y){
    borrarNave(x, y);

    pausa(300);

    gotoxy(x, y); printf(aExplosion);
    gotoxy(x, y+1); printf(aExplosion2);
    gotoxy(x, y+2); printf(aExplosion3);

    pausa(300);

    borrarNave(x, y);

    gotoxy(x, y); printf(bExplosion);
    gotoxy(x, y+1); printf(bExplosion2);
    gotoxy(x, y+2); printf(bExplosion3);

    pausa(180);

    printf("\a");
    borrarNave(x, y);

    gotoxy(x, y); printf(cExplosion);
    gotoxy(x, y+1); printf(cExplosion2);
    gotoxy(x, y+2); printf(cExplosion3);

    pausa(180);


    borrarNave(x, y);

    pintarNave(x, y);


}

void mostrarPuntos(int x){
    gotoxy(30,2); printf("Puntos: %d",x);
}





void jugar(){

    if(disparo==false){ balaX = x+2; balaY= y;}

    gotoxy(astX, astY); printf("%c", 184);
    gotoxy(astX2, astY2); printf("%c", 184);
    gotoxy(astX3, astY3); printf("%c", 184);
    gotoxy(astX4, astY4); printf("%c", 184);
    if(disparo && balaY>=5){
        balaY--;  gotoxy(balaX, balaY); printf("A");
    }
    if(balaY==4){
        gotoxy(balaX, balaY); printf(" ");
        disparo=false; balaY=y;
    }

    pausa(velocidad);

    gotoxy(astX, astY); printf(" ");
    gotoxy(astX2, astY2); printf(" ");
    gotoxy(astX3, astY3); printf(" ");
    gotoxy(astX4, astY4); printf(" ");
    if(disparo) gotoxy(balaX, balaY); printf(" ");

    if(disparo && (balaX == astX && balaY<=astY+2)){
        astY=4;
        astX = rand()%73+3;
        puntos+=10; mostrarPuntos(puntos);
        velocidad-=2;
    }
    if(disparo && (balaX == astX2 && balaY<=astY2+2)){
        astY2=4;
        astX2 = rand()%73+3;
        puntos+=10; mostrarPuntos(puntos);velocidad-=2;
    }
    if(disparo && (balaX == astX3 && balaY<=astY3+2)){
        astY3=4;
        astX3 = rand()%73+3;
        puntos+=10; mostrarPuntos(puntos);velocidad-=2;
    }
    if(disparo && (balaX == astX4 && balaY<=astY4+2)){
        astY4=4;
        astX4 = rand()%73+3;
        puntos+=10; mostrarPuntos(puntos);velocidad-=2;
    }


    if(astY>=y && (astX>=x && astX<=x+4) ){
        explotar(x, y); astY=3; salud--; pintarSalud(salud);
    }
    if(astY2>=y && (astX2>=x && astX2<=x+4)){
        explotar(x, y); astY2=3; salud--; pintarSalud(salud);
    }
    if(astY3>=y && (astX3>=x && astX3<=x+4) ){
        explotar(x, y); astY3=3; salud--; pintarSalud(salud);
    }
    if(astY4>=y && (astX4>=x && astX4<=x+4) ){
       explotar(x, y); astY4=3; salud--; pintarSalud(salud);
    }

    if(kbhit()){
        tecla=getch();
        borrarNave(x, y);
        if(tecla== 77 && x<72) x++;
        if(tecla== 75 && x>3) x--;
        if(tecla== 72 && y>6) y--;
        if(tecla== 80 && y<20) y++;
        if(tecla=='d') disparo=true;
        pintarNave(x, y);
    }

    astY++;
    astY2++;
    astY3++;
    astY4++;

    if(astY>=23){
        astY=4;
        astX = rand()%73+3;
//        if (astX%2!=0) astX4++;
    }
    if(astY2>=23){
        astY2=4;
        astX2 = rand()%73+3;
//        if (astX2%2!=0) astX4++;
    }
    if(astY3>=23){
        astY3=4;
        astX3 = rand()%73+3;
//        if (astX3%2!=0) astX4++;
    }
    if(astY4>=23){
        astY4=4;
        astX4 = rand()%73+3;
//        if (astX4%2!=0) astX4++;
    }

    gotoxy(50, 2); printf("%d", x);

}

int main(){

//    astX = rand()%70+3;

    pintarVida(vidas);
    OcultaCursor();
    pintar_marco();
    pintarNave(x, y);
    pintarSalud(salud);
    while(vidas>0){
        jugar();
    }
    //pausa();
    pausa(900);
}
