#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "empleados.h"
//#include <conio.h>

#define TAM 2





int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];//={{1234, "Juan", 'm', 30000, 1},{2222, "Ana", 'f', 32000, 1}, {2211, "Jorge", 'm', 28000, 0}};
    inicializarEmpleados(lista, TAM);


    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            //system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            //system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            //system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            //system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            //system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            //fflush(stdin);
            //confirma = getche();

            setbuf(stdin, NULL);

            scanf("%c",&confirma);

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            //system("break");
        }
    }
    while(seguir == 's');

    return 0;
}
