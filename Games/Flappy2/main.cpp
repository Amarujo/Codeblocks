#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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


                                                                                                                                                                                                                                                                                                                                                                                                                                  void inicia_libgame(){char inicio[50][100] ={"                  AAA        AAAAAAAA    AAAAAA                       ","                  AAA           AA       AA   AA                      ","                  AAA           AA       AAAAAA                       ","                  AAAAAAA       AA       AA   AA                      ","                  AAAAAAA    AAAAAAAA    AAAAAA                       ","                                                                      ","                                                                      ","                                                                      ","       AAAAAAAAA      AAAAAA       AAAA  AAAA      AAAAAAAAAAA        ","       AAAAAAAAA     AAA    A    AAAAAAAAAAAAAA    AAAAAAAAAAA        ","       AA     AA     AAA    A   AAA  AAAAA   AAA   AAA                ","       AA            AAA    A   AAA   AAA    AAA   AAAAAAAA           ","       AA   AAAAAA   AAAAAAAA   AAA   AAA    AAA   AAAAAAAA           ","       AA        A   AAA    A   AAA   AAA    AAA   AAA                ","       AAAAAAAAA A   AAA    A   AAA   AAA    AAA   AAAAAAAAAAA        ","       AAAAAAAAA     AAA    A   AAA   AAA    AAA   AAAAAAAAAAA        ","                                                                      ",};for(int i = 0 ; i< 17 ; i++){for(int j = 0 ; j < 71 ; j++){if(inicio[i][j] == 'A'){gotoxy(j+5,i+5); printf("*");}}}getch();for(int i = 0 ; i< 17 ; i++){for(int j = 0 ; j < 71 ; j++){if(inicio[i][j] == 'A'){gotoxy(j+5,i+5); printf(" ");}}}}



int wallx=78, wally=1;
int wall2x=78, wall2y=5;
int wall3x=78, wall3y=9;
int wall4x=78, wall4y=13;
int wall5x=78, wall5y=17;
int wall6x=78, wall6y=21;

int ran = 4;

int jugadorX=15;
int jugadorY=10;
char tecla;

void game_over(){
    printf("\a");
    gotoxy(30,15); printf("GAME OVER");
    pausa(5000);
    exit(0);
}


void jugador(){
    gotoxy(jugadorX, jugadorY); printf("%c", 184);
    if(kbhit()){
        tecla=getch();
        if(tecla=='d'){

            gotoxy(jugadorX, jugadorY); printf(" ");
            jugadorY-=3;
        }
//    gotoxy(jugadorX, jugadorY); printf("%c", 184);
    }

}


void borrar_pared(){
    gotoxy(wallx+1, wally-1); printf(" ");
    gotoxy(wallx+1, wally); printf(" ");
    gotoxy(wallx+1, wally+1); printf(" ");
    gotoxy(wallx+1, wally+2); printf(" ");
//        gotoxy(wallx-1, wally-1); printf(" ");
//    gotoxy(wallx-1, wally); printf(" ");
//    gotoxy(wallx-1, wally+1); printf(" ");
//    gotoxy(wallx-1, wally+2); printf(" ");

        gotoxy(wall2x+1, wall2y-1); printf(" ");
    gotoxy(wall2x+1, wall2y); printf(" ");
    gotoxy(wall2x+1, wall2y+1); printf(" ");
    gotoxy(wall2x+1, wall2y+2); printf(" ");
//            gotoxy(wall2x-1, wall2y-1); printf(" ");
//    gotoxy(wall2x-1, wall2y); printf(" ");
//    gotoxy(wall2x-1, wall2y+1); printf(" ");
//    gotoxy(wall2x-1, wall2y+2); printf(" ");


        gotoxy(wall3x+1, wall3y-1); printf(" ");
    gotoxy(wall3x+1, wall3y); printf(" ");
    gotoxy(wall3x+1, wall3y+1); printf(" ");
    gotoxy(wall3x+1, wall3y+2); printf(" ");
//            gotoxy(wall3x-1, wall3y-1); printf(" ");
//    gotoxy(wall3x-1, wall3y); printf(" ");
//    gotoxy(wall3x-1, wall3y+1); printf(" ");
//    gotoxy(wall3x-1, wall3y+2); printf(" ");


        gotoxy(wall4x+1, wall4y-1); printf(" ");
    gotoxy(wall4x+1, wall4y); printf(" ");
    gotoxy(wall4x+1, wall4y+1); printf(" ");
    gotoxy(wall4x+1, wall4y+2); printf(" ");
//            gotoxy(wall4x-1, wall4y-1); printf(" ");
//    gotoxy(wall4x-1, wall4y); printf(" ");
//    gotoxy(wall4x-1, wall4y+1); printf(" ");
//    gotoxy(wall4x-1, wall4y+2); printf(" ");


        gotoxy(wall5x+1, wall5y-1); printf(" ");
    gotoxy(wall5x+1, wall5y); printf(" ");
    gotoxy(wall5x+1, wall5y+1); printf(" ");
    gotoxy(wall5x+1, wall5y+2); printf(" ");
//            gotoxy(wall5x-1, wall5y-1); printf(" ");
//    gotoxy(wall5x-1, wall5y); printf(" ");
//    gotoxy(wall5x-1, wall5y+1); printf(" ");
//    gotoxy(wall5x-1, wall5y+2); printf(" ");


        gotoxy(wall6x+1, wall6y-1); printf(" ");
    gotoxy(wall6x+1, wall6y); printf(" ");
    gotoxy(wall6x+1, wall6y+1); printf(" ");
    gotoxy(wall6x+1, wall6y+2); printf(" ");
//            gotoxy(wall6x-1, wall6y-1); printf(" ");
//    gotoxy(wall6x-1, wall6y); printf(" ");
//    gotoxy(wall6x-1, wall6y+1); printf(" ");
//    gotoxy(wall6x-1, wall6y+2); printf(" ");

    gotoxy(jugadorX, jugadorY); printf(" ");

}

void mover_pared(){
    if(wallx==1){
    wallx=0;
    wall2x=0;
    wall3x=0;
    wall4x=0;
    wall5x=0;
    wall6x=0;
            borrar_pared();
    wallx=78;
    wall2x=78;
    wall3x=78;
    wall4x=78;
    wall5x=78;
    wall6x=78;
    ran= rand()%5;
    }
    wallx--;
    wall2x--;
    wall3x--;
    wall4x--;
    wall5x--;
    wall6x--;

    if(ran==0 && (wallx==15 )){
        if(jugadorY>3) game_over();
    }
    if(ran==1 && (wallx==15 )){
        if(jugadorY<4 || jugadorY>7) game_over();
    }
    if(ran==2 && (wallx==15 )){
        if(jugadorY<8 || jugadorY>11) game_over();
    }
    if(ran==3 && (wallx==15 )){
        if(jugadorY<12 || jugadorY>15) game_over();
    }
    if(ran==4 && (wallx==15 )){
        if(jugadorY<16 || jugadorY>19) game_over();
    }
    if(ran==5 && (wallx==15 )){
        if(jugadorY<20) game_over();
    }

//    if(wallx==14 && (wally==jugadorY || wall2y==jugadorY || wall3y==jugadorY || wall4y==jugadorY || wall5y==jugadorY || wall6y==jugadorY)){
//        printf("has perdido");
//    }

    if(wallx%2==0) jugadorY++;

}


void pintar_pared(){

    jugador();
//    gotoxy(wallx, wally-1); printf("%c", 219);
//    gotoxy(wallx, wally); printf("%c", 219);
//    gotoxy(wallx, wally+1); printf("%c", 219);
//    gotoxy(wallx, wally+2); printf("%c", 219);

    if(ran!=0){
    gotoxy(wallx, wally-1); printf("%c", 219);
    gotoxy(wallx, wally); printf("%c", 219);
    gotoxy(wallx, wally+1); printf("%c", 219);
    gotoxy(wallx, wally+2); printf("%c", 219);
    }
    ///////////////////////////////////////////

//    gotoxy(wall2x, wall2y-1); printf("%c", 219);
//    gotoxy(wall2x, wall2y); printf("%c", 219);
//    gotoxy(wall2x, wall2y+1); printf("%c", 219);
//    gotoxy(wall2x, wall2y+2); printf("%c", 219);
    if(ran!=1){
    gotoxy(wall2x, wall2y-1); printf("%c", 219);
    gotoxy(wall2x, wall2y); printf("%c", 219);
    gotoxy(wall2x, wall2y+1); printf("%c", 219);
    gotoxy(wall2x, wall2y+2); printf("%c", 219);
    }
     /////////////////////////////////////////////

//    gotoxy(wall3x, wall3y-1); printf("%c", 219);
//    gotoxy(wall3x, wall3y); printf("%c", 219);
//    gotoxy(wall3x, wall3y+1); printf("%c", 219);
//    gotoxy(wall3x, wall3y+2); printf("%c", 219);
    if(ran!=2){
    gotoxy(wall3x, wall3y-1); printf("%c", 219);
    gotoxy(wall3x, wall3y); printf("%c", 219);
    gotoxy(wall3x, wall3y+1); printf("%c", 219);
    gotoxy(wall3x, wall3y+2); printf("%c", 219);
    }
     /////////////////////////////////////////////

//    gotoxy(wall4x, wall4y-1); printf("%c", 219);
//    gotoxy(wall4x, wall4y); printf("%c", 219);
//    gotoxy(wall4x, wall4y+1); printf("%c", 219);
//    gotoxy(wall4x, wall4y+2); printf("%c", 219);
    if(ran!=3){
    gotoxy(wall4x, wall4y-1); printf("%c", 219);
    gotoxy(wall4x, wall4y); printf("%c", 219);
    gotoxy(wall4x, wall4y+1); printf("%c", 219);
    gotoxy(wall4x, wall4y+2); printf("%c", 219);
    }
     /////////////////////////////////////////////

//    gotoxy(wall5x, wall5y-1); printf("%c", 219);
//    gotoxy(wall5x, wall5y); printf("%c", 219);
//    gotoxy(wall5x, wall5y+1); printf("%c", 219);
//    gotoxy(wall5x, wall5y+2); printf("%c", 219);
    if(ran!=4){
    gotoxy(wall5x, wall5y-1); printf("%c", 219);
    gotoxy(wall5x, wall5y); printf("%c", 219);
    gotoxy(wall5x, wall5y+1); printf("%c", 219);
    gotoxy(wall5x, wall5y+2); printf("%c", 219);
    }
    /////////////////////////////////////////////

//    gotoxy(wall6x, wall6y-1); printf("%c", 219);
//    gotoxy(wall6x, wall6y); printf("%c", 219);
//    gotoxy(wall6x, wall6y+1); printf("%c", 219);
//    gotoxy(wall6x, wall6y+2); printf("%c", 219);
    if(ran!=5){
    gotoxy(wall6x, wall6y-1); printf("%c", 219);
    gotoxy(wall6x, wall6y); printf("%c", 219);
    gotoxy(wall6x, wall6y+1); printf("%c", 219);
    gotoxy(wall6x, wall6y+2); printf("%c", 219);
    }


}





int main(){
    OcultaCursor();wallx=78;

    while(true){

    pintar_pared();
    pausa(50);
    borrar_pared();
    mover_pared();




    }
//    pintar_marco();
    //pausa();
    pausa(900);
}
