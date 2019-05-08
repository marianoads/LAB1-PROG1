#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "input.h"


typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{
    int codigoAutor;
    char apellido[31];
    char nombre[31];

}eAutores;

typedef struct{
    int codigoLibro;
    char titulo[51];
    int codigoAutor;


}eLibros;

typedef struct{
   int codigoSocio;
   char apellido[31];
   char nombre[31];
   char sexo;
   char telefono[16];
   char email[31];
   int isEmpty;
   eFecha fechaAsociado;

}eSocios;

typedef struct{
    int codigoPrestamo;
    int codigoLibro;
    int codigoSocio;
    eFecha fechaPrestamo;


}ePrestamos;

void initAutores(eAutores autores[], int tamAutores);
void initLibros(eLibros libros[], int tamLibros);
void initSocios(eSocios socios[] , int tamSocios);
int menuBiblioteca();
int buscarEspacioEnElSistema(eSocios socios[], int tamSocios);
void asignarCodigoSocio(eSocios socios[] , int tamSocios, int indice);
void altaSocio(eSocios socios[], int tamSocios);
void bajaSocio(eSocios socios[], int tamSocio);
void mostrarSocios(eSocios socios, int tamSocios);


#define TAM_AUTORES 5
#define TAM_LIBROS 5
#define TAM_SOCIOS 3
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

    char salir = 'n';

    do{
            switch(menuBiblioteca()){
                case 1:
                    altaSocio(socios, TAM_SOCIOS);
                    system("pause");

                break;
                case 2:

                break;
                case 3:
                    bajaSocio(socios, TAM_SOCIOS);
                    system("pause");

                break;
                case 4:
                    listarSocios(socios, TAM_SOCIOS);
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
                    altaPrestamo(prestamos, TAM_PRESTAMOS, socios, TAM_SOCIOS, libros, TAM_LIBROS);
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

void initAutores(eAutores autores[], int tamAutores){

    eAutores vec[] = {
        {101, "Cortazar", "Julio"},
        {102, "Richie", "Denis"},
        {103, "Allende", "Isabel"},
        {104, "Coelho", "Pablo"},
        {105, "Neruda", "Pablo"}
    };

    for(int i = 0; i < tamAutores; i++){

        autores[i] = vec[i];
    }
}

void initLibros(eLibros libros[], int tamLibros){
    eLibros vec[] = {
        {2000, "La casa de los espiritus", 103},
        {2001, "Lenguaje C", 102},
        {2002, "Poemas de amor", 105},
        {2003, "Rayuela", 101},
        {2004,"Adulterio", 104}
    };

    for(int i = 0; i < tamLibros; i++){

        libros[i] = vec[i];
    }
}

void initSocios(eSocios socios[] , int tamSocios){

    for(int i = 0; i < tamSocios ; i++){

        socios[i].isEmpty  = 1;

    }
}

int menuBiblioteca(){

        system("cls");
        int opcion;

        printf("\t\t****SOCIOS****\n");
        printf("1- Alta\n");
        printf("2- Modificar\n");
        printf("3- Baja\n");
        printf("4- Listar\n");
        printf("5- Listar Libros\n");
        printf("6- Listar Autores\n");
        printf("7- Prestamos\n\n");

        printf("Ingrese una opcion o pulse 8 para salir ");
        scanf("%d", &opcion);

        return opcion;


}



void altaSocio(eSocios socios[], int tamSocios){

    int indice;

    indice = buscarEspacioEnElSistema(socios, tamSocios);

    if(indice == -1){
        printf("No hay lugar en el sistema\n\n");

    }else{

        asignarCodigoSocio(socios, tamSocios, indice);

        fflush(stdin);
        getString(socios[indice].apellido, "Ingrese Apellido: ", "Error: El apellido debe tener como minimo 2 caracteres y 31 como maximo: ", 2,31);
        strlwr(socios[indice].apellido);

        fflush(stdin);
        getString(socios[indice].nombre, "Ingrese Nombre: ", "Error: El nombre debe tener como minimo 2 caracteres y 31 como maximo: ", 2 , 31);
        strlwr(socios[indice].nombre);

        getChar(&socios[indice].sexo, "Ingrese Sexo m o f: ", "Error: Ingrese m o f: ", 'm', 'f');

        getString(socios[indice].telefono, "Ingrese Telefono: ", "Error: No ingrese mas de 16 caracteres ni menos de 1: ", 1, 16);

        getString(socios[indice].email, "Ingrese Email: ", "Error: El email no debe contener mas de 31 caracteres: ",0 , 16);

        getInt(&socios[indice].fechaAsociado.dia, "Ingrese Dia: ", "Error: Ingrese un dia valido: ", 1, 31);
        getInt(&socios[indice].fechaAsociado.mes, "Ingrese Mes: ", "Error: Ingrese un mes valido: ", 1, 12);
        getInt(&socios[indice].fechaAsociado.anio, "Ingrese Anio: ", "Error: Ingrese un anio valido: ",1900, 2019);

        socios[indice].isEmpty = 0;

        printf("Se ha realizado la alta con exito\n\n");

    }

}

void asignarCodigoSocio(eSocios socios[] , int tamSocios, int indice){

    int codigoSocio = 1000;



    for(int i = 0 ; i < tamSocios ; i++){
            codigoSocio++;

        if(i == indice){

          socios[indice].codigoSocio = codigoSocio;
          break;
        }


    }

}

int buscarEspacioEnElSistema(eSocios socios[], int tamSocios){

    int indice = -1;

    for(int i = 0 ; i < tamSocios ; i++){

        if(socios[i].isEmpty == 1){

            indice = i;
            break;

        }

    }

    return indice;

}

void mostrarSocios(eSocios socios, int tamSocios){

    printf("%d\t%s\t%s\t%c\t%s\t%s\t%d/%d/%d",socios.codigoSocio, socios.nombre, socios.apellido, socios.sexo, socios.telefono, socios.email, socios.fechaAsociado.dia, socios.fechaAsociado.mes, socios.fechaAsociado.anio);
}

void listarSocios(eSocios socios[], int tamSocios){
    eSocios auxSocios;

    for(int i = 0; i < tamSocios-1; i++){
        for(int j = i+1 ; j < tamSocios; j++){
            if(strcmp(socios[i].nombre, socios[j].nombre)> 0 && strcmp(socios[i].apellido, socios[j].apellido)> 0){

                auxSocios = socios[i];
                socios[i] = socios[j];
                socios[j] = auxSocios;

            }
        }
    }

        printf("codigo\tnombre\tapellido\tsexo\ttelefono\temail\tfecha asociado\n\n");
        for(int i=0; i < tamSocios; i++){
            if(socios[i].isEmpty == 0){
                mostrarSocios(socios[i],tamSocios);

            }
        }

}

void listarLibros(eLibros libros[], int tamLibros){

        printf("CODIGO\tTitulo\tCodigo Autor\n\n");
    for(int i = 0 ; i < tamLibros; i++){

        printf("%d\t%s\t%d", libros[i].codigoLibro, libros[i].titulo, libros[i].codigoAutor);
    }

}

void listarAutores(eAutores autores[], int tamAutores){

        printf("CODIGO\tNombre\tApellido\n\n");
    for(int i = 0 ; i < tamAutores; i++){

        printf("%d\t%s\t%s", autores[i].codigoAutor, autores[i].nombre, autores[i].apellido);
    }

}

void asignarCodigoPrestamo( ePrestamos prestamos[] , int tamPrestamos, int indice){

    int codigoPrestamo = 0;



    for(int i = 0 ; i < tamPrestamos ; i++){
            codigoPrestamo++;

        if(i == indice){

          prestamos[indice].codigoPrestamo = codigoPrestamo;
          break;
        }


    }

}

void altaPrestamo(ePrestamos prestamos[], int tamPrestamo, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros){


    int indice;

    indice = buscarEspacioEnElSistema(prestamos, tamPrestamo);

    if(indice == -1){
        printf("No hay lugar en el sistema\n\n");

    }else{

        asignarCodigoPrestamo(prestamos, tamPrestamo, indice);

        system("cls");
        listarLibros(libros, tamLibros);
        getInt(&prestamos[indice].codigoLibro, "Ingrese codigo libro: ", "Error: No existe el libro en el sistema: ",101,105);

        system("cls");
        listarSocios(socios, tamSocios);
        getInt(&prestamos[indice].codigoSocio, "Ingrese codigo socio: ", "Error: No existe el socio en el sistema: ",0, 9999);

        system("cls");
        printf("Ingrese Fecha de prestamo\n");
        getInt(&prestamos[indice].fechaPrestamo.dia, "Ingrese Dia: ", "Error: Ingrese un dia valido: ", 1, 31);
        getInt(&prestamos[indice].fechaPrestamo.mes, "Ingrese Mes: ", "Error: Ingrese un mes valido: ", 1, 12);
        getInt(&prestamos[indice].fechaPrestamo.anio, "Ingrese Anio: ", "Error: Ingrese un anio valido: ",1900, 2019);

        printf("\n\nSe ha hecho la alta con exito\n\n");
    }
}

void bajaSocio(eSocios socios[], int tamSocio){

    int codigoSocio;
    int indice;
    char resp;

    listarSocios(socios, tamSocio);
    scanf("%d", &codigoSocio);

    for(int i = 0 ; i < tamSocio ; i++){

        if(codigoSocio == socios[i].codigoSocio){

            indice = i;
            break;

        }
    }

    if(indice == -1 ){

        printf("No se ha encontrado un socio con codigo %d\n\n",codigoSocio);

    }else{

        printf("Esta seguro que quiere dar de baja el socio %d\n", codigoSocio);
        printf("s/n? ");
        fflush(stdin);

        getChar(&resp, "s/n", "Error: ingrese s o n", 's', 'n');


        if(resp == 's'){
            socios[indice].isEmpty = 1;

            printf("Se ha dado de baja el empleado exitosamente\n");
        }

    }

}

void modificarSocio(eSocios socios, int tamSocios){

    char salir;

    salir = 'n';


        do{
            switch(menuModificar()){

                case 1:


                break;

                case 2:


                break;

                case 3:


                break;

                case 4:

                break;

                case 5:


                break;

                case 6:

                break;

                case 7:

                break;

                default:
                    printf("Opcion no valida \n\n");
                    system("pause");


                break;
            }
        }
        while(!(salir == 's' ));

}

void menuModificar(){
    int opcion;

    printf("1- Modificar Apellido\n");
    printf("2- Modificar Nombre\n");
    printf("3- Modificar Sexo\n");
    printf("4- Modificar Telefono\n");
    printf("5- Modificar Email\n");

    opcion = getchar();


}










