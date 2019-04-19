#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"

#define TAM 3



int main()
{
    char salir;
    //int status;
    eEmpleado emp[TAM];
    //{{1234, "Juan", 'm', 30000, 1},{2222, "Ana", 'f', 32000, 1}, {2211, "Jorge", 'm', 28000, 0}};

   inicializarEmpleados(emp, TAM);


    do{

        switch(menu()){

            case 1:

                altaEmpleado(emp,TAM);
              //  pause();
                system("pause");


            break;

            case 2:
                bajaEmpleado(emp, TAM);
               // pause();
               system("pause");

            break;

            case 3:
               modificarEmpleado(emp, TAM);
               system("pause");
            break;

            case 4:

            break;

            case 5:
                mostrarEmpleados(emp, TAM);
            break;

            case 6:


                printf("Seguro que quiere salir s/n");
                //setbuf(stdin, NULL);
             //  getche(salir);
               salir = getche();
               // salir = getchar();
                salir = tolower(salir);

                while(!(salir == 's' || salir == 'n')){
                   // setbuf(stdout, NULL);
                    printf("\n\n");
                    printf("Error Ingrese una opcion valida\n");
                    printf("Ingrese una opcion");
                    //salir = getchar();
                    salir = getche();
                    salir = tolower(salir);
                    printf("\n\n");
                   // setbuf(stdout, NULL);
                }


                      //pause();
                    if(salir == 'n')
                        printf("\n\n");


            break;

            default:

            break;
        }



    }
    while(salir != 's');




    return 0;
}
