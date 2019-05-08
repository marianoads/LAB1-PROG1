#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "socios.h"

#define TAM_AUTORES 10
#define TAM_LIBROS 20
#define TAM_SOCIOS 7
#define TAM_PRESTAMOS (TAM_SOCIOS * TAM_LIBROS)

int main()
{
    eAutores autores[TAM_AUTORES];
    eLibros libros[TAM_LIBROS];
    eSocios socios[TAM_SOCIOS] = {
        {1002,"martinez","juan", 'm', "11-29203003", "jm@gmail.com", 0,{4, 2, 2018}},
        {1003, "martinez", "carlos", 'm', "11-40042002", "cm@gmail.com", 0,{1, 9, 2018}},
        {1001, "calderon", "gilberto", 'm', "11-50095932", "calderongilberto3@gmail.com",0, {6, 5, 2018}},
        {1004, "zambrano", "horacio", 'm', "11-49390213", "horac@gmail.com", 0, {5, 9, 2018}},
        {1005, "zapata", "antonella", 'f', "15-05499430", "anto@gmail.com",0,{30, 11, 2018}},
        {1006, "vegas", "michelle", 'f', "15-12345678", "asvegas@gmail.com",0 ,{29, 12, 2018}},
        {1007, "campazzo", "sabrina", 'f', "11-35342111", "ccampa@gmail.com",0,{9, 10, 2018}}
    };
    ePrestamos prestamos[TAM_PRESTAMOS] = {
        {1, 2020,1001, {5, 12, 2019},0},
        {2, 2010, 1004, {23,4,2019},0},
        {3, 2011, 1005, {12, 9, 2019}, 0},
        {4, 2005, 1001, {31, 11, 2019},0},
        {5, 2009, 1006, {10,10, 2019},0}
    };

    initAutores(autores, TAM_AUTORES);
    initLibros(libros, TAM_LIBROS);
    //initSocios(socios, TAM_SOCIOS);
    //initPrestamos(prestamos, TAM_PRESTAMOS);


    char salir = 'n';
    //int flag = 0;

    do{
            switch(menuBiblioteca()){
                case 1:
                    altaSocio(socios, TAM_SOCIOS);
                    system("pause");
                 //   flag = 1;
                break;
                case 2:
                //    if(flag){
                        modificarSocio(socios, TAM_SOCIOS);


                 //   }else{
                 //       printf("No se puede modificar sin haber dado de alta primero un socio\n\n");
                 //   }
                    system("pause");
                break;
                case 3:
                  //  if(flag){
                        bajaSocio(socios, TAM_SOCIOS);


                 //   }else{
                  //      printf("No se puede dar de de baja sin haber dado de alta primero un socio\n\n");
                  //  }
                    system("pause");
                break;
                case 4:
                 //   if(flag){
                        listarSocios(socios, TAM_SOCIOS);
                 //   }else{
                 //       printf("No se puede listar sin haber dado de alta primero un socio\n\n");
                  //  }
                    system("pause");
                break;
                case 5:
                    listarLibros(libros, TAM_LIBROS);
                    system("pause");
                break;
                case 6:
                    listarAutores(autores, TAM_AUTORES);
                    system("pause");
                break;
                case 7:
                 //   if(flag){
                        altaPrestamo(prestamos, TAM_PRESTAMOS, socios, TAM_SOCIOS, libros, TAM_LIBROS);

                  //  }else{
                       // printf("No se puede dar de alta un prestamo sin haberse dado de alta primero un socio\n\n");
                  //  }
                    system("pause");
                break;
                case 8:
                    printf("Quiere salir s/n ");
                    salir = getche();
                    salir = tolower(salir);
                    while(!(salir == 'n' || salir == 's')){

                        printf("ERROR INGRESE s/n ");
                        salir = getche();
                    }

                break;
                default:
                    printf("Ingrese una opcion valida\n\n");
                    system("pause");
                break;
            }


    }while(!(salir == 's'));


    return 0;
}
