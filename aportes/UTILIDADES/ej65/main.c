#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "input.h"

#define TAM 5

int main()
{
    int enteros[TAM];
    char opcion;
    int aux;
    int i,j;


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
                    system("clear");
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
                    system("clear");

                    for( i = 0; i < TAM-1; i++)
                    {
                        for( j = i+1; j < TAM; j++)
                        {
                            if(enteros[i] < enteros[j])
                            {
                                aux = enteros[i];
                                enteros[i] = enteros[j];
                                enteros[j] = aux;
                            }
                        }
                    }

                    printf("Vector ordenado\n");
                break;

                case 'c':
                    system("clear");
                    for(int i = 0 ; i < TAM ; i++)
                        printf("%d\n",enteros[i]);
                    printf("\n");
                break;

                case 'd':

                    system("clear");
                    printf("Usted Salio exitosamente\n");

                break;


            }

        }
        while(!(opcion == 'a' || opcion == 'b' || opcion == 'c' || opcion == 'd'));




    return 0;

    }
