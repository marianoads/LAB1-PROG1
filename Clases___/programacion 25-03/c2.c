#include <stdio.h>
#include <stdlib.h>


void unaFuncion(int x);

int main()
{
    int x = 10;

    printf("x al inicio del main vale %d \n \n", x);

    unaFuncion(x);

    printf("x al final del main vale %d \n \n",x);

    return 0;
}

void unaFuncion(int x)
{
    x = 4;

    printf("X dentro de la funcion vale %d \n \n", x);
}