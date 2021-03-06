#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "socios.h"

#define TAM_AUTORES 10
#define TAM_LIBROS 20
#define TAM_SOCIOS 9
#define TAM_PRESTAMOS 180

int main()
{
    eAutores autores[TAM_AUTORES];
    eLibros libros[TAM_LIBROS];
    eSocios socios[TAM_SOCIOS] = {

    {1000, "calderon", "gilberto", 'm', "11-40044567", "c@gmail.com", 0, {2, 3, 2014}},
    {2222, "fernandez", "maria", 'f', "15-09591234", "mar@gmail.com", 0, {2,9, 2019}},
    {1234, "armani", "alberto", 'm', "11-32459993", "armAlb@gmail.com", 0 ,{5,12, 2018}},
    {1111, "santana", "carlos", 'm', "11-8493029485", "sant@gmail.com", 0, {31, 12, 2019}},
    {1212, "de sales", "antonio", 'm', "11-23450493", "antoniode@gmail.com", 0,{29, 11, 2014}},
    {1012, "vegas", "astrid", 'f', "11-23440392", "va@gmail.com", 0 ,{11, 2, 2019}},
    {3333, "abril", "sandra", 'f', "11-12310493", "abril@gmail.com", 0, {02, 2, 2019}},
    {3434, "villegas", "octavio", 'm', "11-23440984", "octavil@gmail.com", 0 ,{3, 3, 2012}},
    {4444, "villegas", "jose", 'm', "15-23450342", "joe@gmail.com", 0, {9, 9, 2019}}

    };
    ePrestamos prestamos[TAM_PRESTAMOS] = {
    {8000, 2009, 4444, {20, 4, 2019},0},
    {8001, 2008, 1234, {20, 4, 2019}, 0},
    {8002, 2019, 3434, {20, 6, 2019}, 0},
    {8003, 2009, 1012, {9, 7, 2019}, 0},
    {8004, 2014, 4444, {31, 9, 2019}, 0},
    {8005, 2013, 1234, {22, 10, 2019},0},
    {8006, 2012, 2222, {9, 11, 2019},0},
    {8007, 2012, 1012, {9, 12,2019},0}

    };

    initAutores(autores, TAM_AUTORES);
    initLibros(libros, TAM_LIBROS);
    //initSocios(socios, TAM_SOCIOS);
    //initPrestamos(prestamos, TAM_PRESTAMOS);


    char salir = 'n';
    int flag = 1;

    do{
            switch(menuBiblioteca()){
                case 1:
                    altaSocio(socios, TAM_SOCIOS);
                    system("pause");
                    flag = 1;
                break;
                case 2:
                    if(flag){
                        modificarSocio(socios, TAM_SOCIOS);


                    }else{
                        printf("No se puede modificar sin haber dado de alta primero un socio\n\n");
                   }
                    system("pause");
                break;
                case 3:
                    if(flag){
                        bajaSocio(socios, TAM_SOCIOS);


                    }else{
                        printf("No se puede dar de de baja sin haber dado de alta primero un socio\n\n");
                   }
                    system("pause");
                break;
                case 4:
                    if(flag){
                        listarSocios(socios, TAM_SOCIOS);
                    }else{
                       printf("No se puede listar sin haber dado de alta primero un socio\n\n");
                 }
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
                    if(flag){
                        altaPrestamo(prestamos, TAM_PRESTAMOS, socios, TAM_SOCIOS, libros, TAM_LIBROS);

                    }else{
                        printf("No se puede dar de alta un prestamo sin haberse dado de alta primero un socio\n\n");
                    }
                    system("pause");
                break;
                case 8:

                    promedioDiarioPrestamos(prestamos, TAM_PRESTAMOS);
                    system("pause");

                break;

                case 9:
                    diasNoSuperanPromedio(prestamos, TAM_PRESTAMOS);
                    system("pause");
                break;

                case 10:
                    listarSociosConLibros(prestamos, TAM_PRESTAMOS, socios, TAM_SOCIOS, libros,TAM_LIBROS);
                    system("pause");
                break;

                case 11:
                    listarLibrosConSocios(prestamos,TAM_PRESTAMOS , socios , TAM_SOCIOS, libros , TAM_LIBROS);
                    system("pause");

                break;

                case 12:
                    librosMenosSolicitados(libros, TAM_LIBROS, prestamos, TAM_PRESTAMOS);
                    system("pause");
                break;

                case 13:
                    sociosConMasPrestamos(socios,TAM_SOCIOS, prestamos, TAM_PRESTAMOS);
                    system("pause");
                break;

                case 14:
                    librosSolicitadoConFecha(libros, TAM_LIBROS , prestamos, TAM_PRESTAMOS);
                    system("pause");
                break;

                case 15:
                    sociosAlMenosUnaSolicitud(socios, TAM_SOCIOS, prestamos, TAM_PRESTAMOS);
                    system("pause");
                break;

                case 16:
                    listarLibrosOrdenadoPorTitulo(libros, TAM_LIBROS);
                    system("pause");
                break;

                case 17:
                    sociosOrdenadosPorApellido(socios, TAM_SOCIOS);
                    system("pause");
                break;

                case 18:
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


