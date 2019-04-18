#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "empleados.h"

#define TAM 3



int main()
{
    char salir;
    int status;
    eEmpleado emp[TAM];
    //{{1234, "Juan", 'm', 30000, 1},{2222, "Ana", 'f', 32000, 1}, {2211, "Jorge", 'm', 28000, 0}};

   inicializarEmpleados(emp, TAM);


    do{

        switch(menu()){

            case 1:

                altaEmpleado(emp,TAM);
                pause();
               // system("psuse");


            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
                mostrarEmpleados(emp, TAM);
            break;

            case 6:


                printf("Seguro que quiere salir s/n");
                setbuf(stdin, NULL);
//                getche(salir);
                status = scanf("%c", &salir);
                salir = tolower(salir);

                while(status != 1){
                    printf("Error Ingrese una opcion valida\n");
                    printf("Ingrese una opcion ");
                    status = scanf("%c", &salir);
                    salir = tolower(salir);
                    printf("\n");
                }

                    if(salir == 's')
                    getchar();





            break;

            default:

            break;
        }



    }
    while(salir != 's');




    return 0;
}
