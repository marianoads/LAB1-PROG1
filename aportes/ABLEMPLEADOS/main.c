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
    eEmpleado emp[TAM]={
        {1234, "Juan", 'm', 30000, 1, 1 ,{2, 11, 2000}},
        {2222, "Ana", 'f', 32000, 1, 1,{1, 4, 1998}},
        {2211, "Jorge", 'm', 28000, 1,3 ,{13 , 8 , 1995}}};

    eSector sector[] = {

        {1, "SISTEMAS"},
        {2, "R.R.H.H"},
        {3, "COMPRAS"},
        {4, "VENTAS"},
        {5, "LEGALES"}

    };
    int flag = 0;

   //inicializarEmpleados(emp, TAM);


    do{

        switch(menu()){

            case 1:

                altaEmpleado(emp,TAM);
              //  pause();
                system("pause");

                flag = 1;
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
                ordenarEmpleados(emp, TAM, flag);
                system("pause");
            break;

            case 5:

                mostrarEmpleados(emp, TAM);
                system("pause");
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
                printf("Opcion Invalida \n\n");
                system("pause");

            break;
        }



    }
    while(salir != 's');




    return 0;
}
