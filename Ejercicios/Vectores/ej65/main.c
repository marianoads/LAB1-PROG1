#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"

#define TAM 5

int main()
{
    int enteros[TAM];
    char opcion;


    do
    {
        printf("a- Cargar el vector\n");
        printf("b- Ordenar el vector\n");
        printf("c- Mostrar el vector\n");
        printf("d- Salir\n");


       opcion = getchar();

        switch(opcion)
        {
            case 'a':
                system("cls");
                fflush(stdin);

                for(int i = 0; i < TAM ; i++)
                    enteros[i] = obtenerNumero();

                     /*printf("ingrese un numero\n");
                     scanf("%d",&enteros[1]);

                     while(isdigit(enteros[1]) != 0)
                     {
                            printf("ERROR: ingrese un numero");
                            scanf("%d",&enteros[1]);
                     }*/

            break;

            case 'b':
            break;

            case 'c':
            break;

            case 'd':
            break;


        }

    }
    while(!(opcion == 'a' || opcion == 'b' || opcion == 'c' || opcion == 'd'));


    return 0;

    }
