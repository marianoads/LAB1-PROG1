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
    eSocios socios[TAM_SOCIOS];
    ePrestamos prestamos[TAM_PRESTAMOS];

    initAutores(autores, TAM_AUTORES);
    initLibros(libros, TAM_LIBROS);
    initSocios(socios, TAM_SOCIOS);
    initPrestamos(prestamos, TAM_PRESTAMOS);


    char salir = 'n';
    int flag = 0;

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


