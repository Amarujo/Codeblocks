#include <stdio.h>
#include <stdlib.h>
//stdlib.h permite el uso de system("pause"); puede remplazarse por conio.h para usar
//la función getch(), ojo no todos los IDES admiten esta última función.


bool esPrimo(int num)
{	if(num == 1) return true;
int i;
for(i = 2; i<num; i++)
if(num % i == 0)
break;
if(i == num)
return true;
else
return false;
}

int main()
{
int entero;
printf("Introduce un entero: ");
scanf("%d", &entero);

printf("Primos comprendidos entre 1 y %d\n\n", entero);
for(int i=1; i<=entero; i++)
if(esPrimo(i))
printf(i==1? "%d": ", %d", i);
printf("\n\n");
system("pause");
return 25;
}
