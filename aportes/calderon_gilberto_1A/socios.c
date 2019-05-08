#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "socios.h"

/** \brief Hace hard coding al vector autores de tipo eAutores
 * \param autores es el vector donde se encuentra los autores almacenados en el sistema
 * \param tamAutores la cantidad de espacio en memoria reservada del vector
 * \return nada
 */


void initAutores(eAutores autores[], int tamAutores){

    eAutores vec[] = {
        {101, "Cortazar", "Julio"},
        {102, "Richie", "Denis"},
        {103, "Allende", "Isabel"},
        {104, "Coelho", "Paulo"},
        {105, "Neruda", "Pablo"},
        {106, "Juan", "Rulfo"},
        {107, "Shakespeare", "William"},
        {108, "Alighieri","Dante"},
        {109, "Tolstoi", "Leon"},
        {110, "Frank", "Ana"}

        };

    for(int i = 0; i < tamAutores; i++){

        autores[i] = vec[i];
    }
}

/** \brief Hace hard coding al vector libros de tipo eLibros
 * \param libros es el array donde se almacenan los libros almacenados en el sistema
 * \param tamLibros la cantidad de espacio en memoria reservado por el vector
 * \return nada
 */


void initLibros(eLibros libros[], int tamLibros){
    eLibros vec[] = {
        {2001, "Paula", 103},
        {2002, "Lenguaje C", 102},
        {2003, "Poemas de amor", 105},
        {2004, "Rayuela", 101},
        {2005,"Adulterio", 104},
        {2006, "Obras", 106},
        {2007, "Romeo y Julieta", 107},
        {2008, "Infierno", 108},
        {2009, "Infancia", 109},
        {2010, "Anne", 110},
        {2011, "La Espia", 104},
        {2012, "Amor", 103},
        {2013, "Soneto 130", 107},
        {2014, "Otelo", 107},
        {2015, "Bestiario", 101},
        {2016, "La Autopista", 101},
        {2017, "Convivio", 108},
        {2018, "Estravagario", 105},
        {2019, "El Zahir", 104},
        {2020, "Valquirias",104}
    };

    for(int i = 0; i < tamLibros; i++){

        libros[i] = vec[i];
    }
}

/** \brief La funcion que se encarga de inicializar el vector socios de modo que se pueda almacenar informacion de dicha entidad
 *
 * \param socios es el array donde se encuentra la informacion de los socios almacenados en el sistema
 * \param tamSocios es la cantidad de espacio en memoria que almacena el vector
 * \return nada
 *
 */


void initSocios(eSocios socios[] , int tamSocios){

    for(int i = 0; i < tamSocios ; i++){

        socios[i].isEmpty  = 1;

    }
}

/** \brief prepara los campos de los prestamos para las altas
 *
 * \param prestamos es el array en donde se almacena la informacion de cada uno de los prestamos
 * \param tamPrestamos es el espacio en memoria que ocupa el vector prestamos
 * \return nada
 *
 */

void initPrestamos(ePrestamos prestamos[], int tamPrestamos){

    for(int i = 0; i < tamPrestamos ; i++){
        prestamos[i].isEmpty = 1;

    }
}

/** \brief Funcion que muestra un menu de opciones por medio el cual, se pueden almacenar informacion , mostrar informacion, etc
 * \param no tiene ningun
 * \return retorna un valor de tipo int de modo que el programa realice la opcion elegida
 */

int menuBiblioteca(){

        system("cls");
        fflush(stdin);
        int opcion;

        printf("\t\t****SOCIOS****\n");
        printf("1- Alta\n");
        printf("2- Modificar\n");
        printf("3- Baja\n");
        printf("4- Listar\n");
        printf("5- Listar Libros\n");
        printf("6- Listar Autores\n");
        printf("\t\t****Prestamos****\n");
        printf("7- Alta\n\n");
        printf("\t\t****INFORMES****\n");
        printf("8- Informar total general y promedio diario de las solicitudes de prestamos\n");
        printf("9- Informar cantidad de dias que no superan el promedio\n");
        printf("10- Listar socios que solicitaron un determinado libro\n");
        printf("11- Listar libros solicitados por un determinado socio\n");
        printf("12- Listar libros menos solicitados\n");
        printf("13- Listar socios que realizaron mas solicitudes de prestamo\n");
        printf("14- Listar los libros solicitados en una fecha determinada\n");
        printf("15- Listar socios que realizaron al menos una solicitud en una fecha determinada\n");
        printf("16- Listar libros por titulo (descendente)\n");
        printf("17- Listar socios por apellido\n\n");
        printf("Ingrese una opcion o ingrese 18 para salir ");
        scanf("%d", &opcion);

        return opcion;


}

/** \brief Funcion que se encarga de almacenar toda la informacion de un socio
 * \param socios el vector que se encarga de almacenar la informacion de cada uno de los socios
 * \param tamSocios es la cantidad de memoria que ocupa el vector
 * \return nada
 */


void altaSocio(eSocios socios[], int tamSocios){

    int indice;

    indice = buscarEspacioEnElSistema(socios, tamSocios);

    if(indice == -1){
        printf("No hay espacio en el sistema\n\n");

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

        getString(socios[indice].email, "Ingrese Email: ", "Error: El email no debe contener mas de 31 caracteres: ",0 , 31);

        getInt(&socios[indice].fechaAsociado.dia, "Ingrese Dia: ", "Error: Ingrese un dia valido: ", 1, 31);
        getInt(&socios[indice].fechaAsociado.mes, "Ingrese Mes: ", "Error: Ingrese un mes valido: ", 1, 12);
        getInt(&socios[indice].fechaAsociado.anio, "Ingrese Anio: ", "Error: Ingrese un anio valido: ",2000, 2019);

        socios[indice].isEmpty = 0;

        printf("Se ha realizado la alta con exito\n\n");

    }

}

/** \brief Funcion que se encarga de asignar automaticamente el codigo del socio el cual sera identificado por dicho codigo
 * \param socios es el vector que se encarga de almacenar cada uno de los socios
 * \param tamSocios es la cantidad de memoria que el vector socios ocupa
 * \param indice es el indice en donde se encuentra el socio en el vector
 * \return nada
 *
 */


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

/** \brief Funcion que se encarga de buscar un espacio libre en el array de socios
 *
 * \param socios es el vector en donde se almacenan la informacion de cada uno de los socios
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \return un valor de tipo int, retorna -1 si no se encontro ningun espacio donde almacenar, o sino retorna el indice
 *  del vector donde hay espacio libre para almacenar informacion
 */


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

/** \brief Funcion que se encarga de mostrar cada uno de los datos de cada socio, nombre, apellido, codigo, etc
 *
 * \param socios es la variable de un socio en especifico en la cual se encuentra sus dichos datos respectivamente
 * \param tamSocios
 * \return no retorna ningun valor
 *
 */


void mostrarSocios(eSocios socios, int tamSocios){

    printf("%4d\t%11s\t%11s\t%1c\t%16s\t%31s\t%2d/%2d/%4d\n",socios.codigoSocio, socios.nombre, socios.apellido, socios.sexo, socios.telefono, socios.email, socios.fechaAsociado.dia, socios.fechaAsociado.mes, socios.fechaAsociado.anio);
}

/** \brief Funcion que se encarga de listar cada uno de los socios que se encuentrar de alta en el sistema ademas
 *         los ordena alfabeticamete por nombre
 * \param socios es el vector en donde se almacenan los distintos datos de cada socio
 * \param tamSocio es la cantidad de memoria que almacena el vector socios
 * \return nada
 *
 */


void listarSocios(eSocios socios[], int tamSocios){
   // eSocios auxSocios;

    /*for(int i = 0; i < tamSocios-1; i++){
        for(int j = i+1 ; j < tamSocios; j++){
            if(strcmp(socios[i].nombre, socios[j].nombre) > 0 ){

                auxSocios = socios[i];
                socios[i] = socios[j];
                socios[j] = auxSocios;

            }else if(strcmp(socios[i].nombre, socios[j].nombre)== 0){

                if(strcmp(socios[i].apellido, socios[j].apellido) > 0){
                    auxSocios = socios[i];
                    socios[i] = socios[j];
                    socios[j] = auxSocios;
                }
            }*/

            /*else if(strcmp(socios[i].apellido, socios[j].apellido) > 0 ){

                auxSocios = socios[i];
                socios[i] = socios[j];
                socios[j] = auxSocios;
            }*/

      //  }
    //}

        printf("codigo     nombre        apellido      sexo         telefono                                email      fecha asociado\n\n");
        for(int i=0; i < tamSocios; i++){
            if(socios[i].isEmpty == 0){
                mostrarSocios(socios[i],tamSocios);

            }
        }
        printf("\n\n");

}

/** \brief Funcion que se encarga de listar los libros que se encuentran en el sistema
 *
 * \param libros es el array en donde se encuentra almacenados la informacion de los distintos libros que se encuentran
 * \param tamLibros es la cantidad de espacio en memoria que almacena el vector libros
 * \return nada
 *
 */


void listarLibros(eLibros libros[], int tamLibros){

        printf("   CODIGO-LIBRO:    \tTitulo:    Codigo-Autor:\n\n");
    for(int i = 0 ; i < tamLibros; i++){

        printf("%10d\t%15s\t%10d\n", libros[i].codigoLibro, libros[i].titulo, libros[i].codigoAutor);
    }

}

/** \brief Funcion que se encarga de listar la informacion de los distintos autores que se encuentran en el sistema
 *
 * \param autores es el array en donde se almacena la informacion de cada uno de los autores
 * \param tamAutores es la cantidad de espacio en memoria que el vector autores ocupa
 * \return nada
 *
 */


void listarAutores(eAutores autores[], int tamAutores){

        printf("     CODIGO:         Nombre:       \tApellido:\n\n");
    for(int i = 0 ; i < tamAutores; i++){

        printf("%10d\t%10s\t%15s\n\n", autores[i].codigoAutor, autores[i].nombre, autores[i].apellido);
    }

}

/** \brief Funcion que se encarga de asignar automaticamente el codigo de cada prestamo que se realiza el cual se identificara ocn dicho codigo
 *
 * \param prestamos el array en donde que se almacenan la informacion de los distintos prestamos que se realizan
 * \param tamPrestamos la cantidad de de memoria que ocupa el vector prestamos
 * \return nada
 *
 */


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

/** \brief Funcion que se encarga de almacenar la informacion de los distintos prestamos que se realizan
 *
 * \param prestamos es el array en donde se almacena la informacion de los distintos prestamos que se encuentrar
 * \param tamPrestamos es la cantidad de memoria que ocupa el vector prestamos
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param libros es el array en donde se almacena la informacion de los distintos libros que se encuentrar
 * \param tamLibros es la cantidad de memoria que ocupa el vector libros
 * \return nada
 *
 */


void altaPrestamo(ePrestamos prestamos[], int tamPrestamo, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros){


    int indice;
    int ok;

    indice = buscarPrestamos(prestamos, tamPrestamo);

    if(indice == -1){
        printf("No hay espacio en el sistema\n\n");

    }else{

        asignarCodigoPrestamo(prestamos, tamPrestamo, indice);

        system("cls");
        listarLibros(libros, tamLibros);
        getInt(&prestamos[indice].codigoLibro, "Ingrese codigo libro: ", "Error: No existe el libro en el sistema: ",2001,2020);

        system("cls");
        listarSocios(socios, tamSocios);
        getInt(&prestamos[indice].codigoSocio, "Ingrese codigo socio: ", "Error: Ingrese numero mayor a cero: ",0, 999999999);

        ok = buscarSocio(socios, tamSocios, prestamos[indice].codigoSocio);
        while(ok == -1){
            printf("No existe un socio de codigo %d en sistema: ", prestamos[indice].codigoSocio);
            printf("\n");
            getInt(&prestamos[indice].codigoSocio, "Ingrese codigo socio: ", "Error: Ingrese numero mayor a cero: ",0, 9999);
        }

        //system("cls");
        printf("Ingrese Fecha de prestamo\n");
        getInt(&prestamos[indice].fechaPrestamo.dia, "Ingrese Dia: ", "Error: Ingrese un dia valido: ", 1, 31);
        getInt(&prestamos[indice].fechaPrestamo.mes, "Ingrese Mes: ", "Error: Ingrese un mes valido: ", 1, 12);
        getInt(&prestamos[indice].fechaPrestamo.anio, "Ingrese Anio: ", "Error: Ingrese un anio valido: ",1900, 2019);

        prestamos[indice].isEmpty = 0;
        printf("\n\nSe ha hecho la alta con exito\n\n");
    }
}

/** \brief Funcion que se encarga de inhabilitar a un socio que se encuentra en el sistema
 * \param socios es el array que se encarga de almacenar la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de espacio en memoria que ocupa el vector socios
 * \return nada
 *
 */

void bajaSocio(eSocios socios[], int tamSocio){

    int codigoSocio;
    int indice = -1;
    char resp;

    listarSocios(socios, tamSocio);
    printf("Ingrese Codigo Socio: ");
    scanf("%d", &codigoSocio);

    for(int i = 0 ; i < tamSocio ; i++){

        if(codigoSocio == socios[i].codigoSocio){

            indice = i;
            break;

        }
    }

    if(indice == -1 ){

        printf("No se ha encontrado un socio con codigo %d\n\n",codigoSocio);
        fflush(stdin);

    }else{

        fflush(stdin);
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

/** \brief Funcion que se encarga de modificar la informacion de un socio en el sistema
 *
 * \param socios es el array que se encarga de almacenar la informacion de los distintos socios que se encuentrar
 * \param tamSocios es la cantidad de memoria que ocupa el vector  socios
 * \return nada
 *
 */


void modificarSocio(eSocios socios[], int tamSocios){

    char salir = 'n';
    int codigoSocio;
    int indice;

    listarSocios(socios, tamSocios);
    printf("\nIngrese codigo socio: ");
    scanf("%d", &codigoSocio);

    indice = buscarSocio(socios,tamSocios, codigoSocio);

    if(indice == -1){
        printf("No se ha podido encontrar el socio de codigo nro: %d\n\n",codigoSocio);
    }else{

        do{
            switch(menuModificar(socios, tamSocios, indice)){

                case 1:
                    modificarApellido(socios, tamSocios, indice);
                    system("pause");

                break;

                case 2:
                    modificarNombre(socios, tamSocios, indice);
                    system("pause");

                break;

                case 3:
                    modificarSexo(socios,tamSocios, indice);
                    system("pause");

                break;

                case 4:
                    modificarTelefono(socios, tamSocios, indice);
                    system("pause");

                break;

                case 5:
                    modificarEmail(socios, tamSocios, indice);
                    system("pause");

                break;

                case 6:
                    printf("Quiere salir s/n ");
                    salir = getche();
                    salir = tolower(salir);
                    while(!(salir == 'n' || salir == 's')){

                        printf("ERROR INGRESE s/n ");
                        salir = getche();
                    }
                    printf("\n\n");

                break;

                default:
                    printf("Opcion no valida \n\n");
                    system("pause");


                break;
            }
        }
        while(!(salir == 's' ));
    }






}
/** \brief Funcion que se encarga de mostrar la un menu de opciones para modificar algun socio del sistema
 *
 * \param socios es el array en donde se almacenan la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice con el cual se identifica un socio en especifico
 * \return valor tipo int, la opcion escogida para modificar
 *
 */


int menuModificar(eSocios socios[], int tamSocios, int indice){
    int opcion;
    system("cls");
    printf("**********************Modificar Empleado***********************\n\n");
    printf("codigo     nombre        apellido      sexo         telefono                                email      fecha asociado\n\n");
    mostrarSocios(socios[indice], tamSocios);
    printf("\n\n");
    printf("1- Modificar Apellido\n");
    printf("2- Modificar Nombre\n");
    printf("3- Modificar Sexo\n");
    printf("4- Modificar Telefono\n");
    printf("5- Modificar Email\n\n");

    printf("Ingrese una opcion o pulse 6 para salir: ");
    scanf("%d", &opcion);

    return opcion;

}

/** \brief Funcion que se encarga de buscar un espacio libre en el sistema para realizar dicho prestamo
 *
 * \param prestamos es el array que se encarga de almacenar la informacion de los distintos prestamos que se realizan
 * \param tamPrestamos es la cantidad de memoria que ocupa el vector prestamos
 * \return  -1 si no encontro algun espacio libre, sino retorna el indice de un espacio desocupado
 *
 */


int buscarPrestamos(ePrestamos prestamos[], int tamPrestamos){
    int indice = -1;

    for(int i = 0 ; i < tamPrestamos ; i++){

        if(prestamos[i].isEmpty == 1){

            indice = i;
            break;

        }

    }

    return indice;


}

/** \brief Funcion que se encarga de buscar un socio mediante su identificacion
 *
 * \param socios es el array que se encarga de almacenar la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \return valor de tipo int -1 si no encuentra el socio, si lo encuentra retorna el indice
 *
 */


int buscarSocio(eSocios socios[], int tamSocio, int codigoSocio){

    int indice = -1;

    for(int i = 0; i < tamSocio; i++){

        if(codigoSocio == socios[i].codigoSocio){
            indice = i;
            break;
        }

    }
    return indice;
}

/** \brief modifica el nombre de un socio en especifico
 *
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice por medio del cual se puede acceder a la informacion de un vector en especifico
 * \return nada
 *
 */


void modificarNombre(eSocios socios[], int tamSocios, int indice){

    char auxNombre[1024];
    char resp;


        getString(auxNombre, "Ingrese nombre nuevo: ", "Error: el nombre no dehe tener menos de 2 caracteres o mas 31", 2, 31);
        printf("\n\nNombre anterior: %s -- Nombre nuevo: %s\n", socios[indice].nombre, auxNombre);
        getChar(&resp, "Esta seguro que desea realizar los cambios s/n?: ", "Error: Ingrese s o n: ", 's', 'n');

        if(resp == 's'){
            strcpy(socios[indice].nombre, auxNombre);
            printf("\n\nSe ha modificado el nombre exitosamente\n\n");
        }else{
            printf("\nNo se ha hecho ninguna modificacion\n\n");
        }

}

/** \brief modifica el apellido de un socio en especifico
 *
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice por medio del cual se puede acceder a la informacion de un vector en especifico
 * \return nada
 *
 */

void modificarApellido(eSocios socios[], int tamSocios, int indice){

    char auxApellido[1024];
    char resp;

        getString(auxApellido, "Ingrese nuevo apellido: ", "Error: el apellido no debe tener menos de 2 caracteres o mas de 31",2, 31);
        printf("\n\nApellido anterior: %s -- Apellido nuevo: %s\n", socios[indice].apellido, auxApellido);
        getChar(&resp, "Esta seguro que desea realizar los cambios s/n?: ", "Error: Ingrese s o n: ", 's', 'n');

         if(resp == 's'){
            strcpy(socios[indice].apellido, auxApellido);
            printf("\n\nSe ha modificado el apellido exitosamente\n\n");
        }else{
            printf("\nNo se ha hecho ninguna modificacion\n\n");
        }

    }


    /** \brief modifica el sexo de un socio en especifico
 *
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice por medio del cual se puede acceder a la informacion de un vector en especifico
 * \return nada
 *
 */

void modificarSexo(eSocios socios[], int tamSocios, int indice){

    char auxSexo;
    char resp;


        getChar(&auxSexo, "Ingrese nuevo sexo m/f: ", "Error: Ingrese m/f: ", 'm', 'f');
        printf("\n\nSexo anterior: %c -- Sexo nuevo: %c\n", socios[indice].sexo, auxSexo);
        getChar(&resp, "Esta seguro que desea realizar los cambios s/n?: ", "Error: Ingrese s o n: ", 's', 'n');

         if(resp == 's'){
            socios[indice].sexo = auxSexo;
            printf("\n\nSe ha modificado el sexo exitosamente\n\n");
        }else{
            printf("\nNo se ha hecho ninguna modificacion\n\n");
        }

    }
/** \brief modifica el telefono de un socio en especifico
 *
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice por medio del cual se puede acceder a la informacion de un vector en especifico
 * \return nada
 *
 */

void modificarTelefono(eSocios socios[], int tamSocios, int indice){


    char auxTelefono[1024];
    char resp;

      getString(auxTelefono, "Ingrese nuevo telefono: ", "Error: No ingrese mas de 16 caracteres ni menos de 1: ", 1 , 16);
      printf("\n\nTelefono anterior: %s -- Telefono nuevo: %s\n", socios[indice].telefono, auxTelefono);
      getChar(&resp, "Esta seguro que desea realizar los cambios s/n?: ", "Error: Ingrese s o n: ", 's', 'n');

         if(resp == 's'){
            strcpy(socios[indice].telefono ,auxTelefono);
            printf("\n\nSe ha modificado el numero de telefono exitosamente\n\n");
        }else{
            printf("\nNo se ha hecho ninguna modificacion\n\n");
        }
}

/** \brief modifica el email de un socio en especifico
 *
 * \param socios es el array en donde se almacena la informacion de los distintos socios que se encuentran
 * \param tamSocios es la cantidad de memoria que ocupa el vector socios
 * \param indice es el indice por medio del cual se puede acceder a la informacion de un vector en especifico
 * \return nada
 *
 */


void modificarEmail(eSocios socios[], int tamSocios, int indice){


    char auxEmail[1024];
    char resp;

        getString(auxEmail, "Ingrese nuevo email: ", "Error: Ingrese no ingrese menos de 1 caracteres o mas de 31: ", 1, 31);
        printf("\n\nEmail anterior: %s -- Email nuevo: %s\n", socios[indice].email, auxEmail);
        getChar(&resp, "Esta seguro que desea realizar los cambios s/n?: ", "Error: Ingrese s o n: ", 's', 'n');

         if(resp == 's'){
            strcpy(socios[indice].email, auxEmail);
            printf("\n\nSe ha modificado el sexo exitosamente\n\n");
        }else{
            printf("\nNo se ha hecho ninguna modificacion\n\n");
        }

}

/* **************informes********************** */

void promedioDiarioPrestamos(ePrestamos prestamos[], int tamPrestamos){

    int flag = 0;
    int dias = 31;
    int cont = 0;
    int cantidadSolicitudesDePrestamos;
    float promedioDiarioPrestamos;

    for(int i = 0; i < tamPrestamos; i++){
        cont++;
        if(flag == 0 || prestamos[i].isEmpty == 0){

            cantidadSolicitudesDePrestamos = cont;
            flag = 1;
        }
    }

    promedioDiarioPrestamos = (float) cantidadSolicitudesDePrestamos / dias;

    printf("La cantidad total de solicitudes de prestamos: %d\n",cantidadSolicitudesDePrestamos);
    printf("Promedio diario de la solicitudes a prestamo de los libros: %f ", promedioDiarioPrestamos);


}

void diasNoSuperanPromedio(ePrestamos prestamos[], int tamPrestamos){

    int cont1 = 0;
    int cont2 = 0;
    int flag1 = 0;
    int flag2 = 0;
    int dias = 31;
    int cantidadSolicitudesDePrestamos;
    float promedioDiarioPrestamos;
    int cantDiasMenorAlPromedio;

    for(int i = 0; i < tamPrestamos; i++){

        if(flag1 == 0 || prestamos[i].isEmpty == 0){
            cont1++;
            cantidadSolicitudesDePrestamos = cont1;
            flag1 = 1;
        }
    }

    promedioDiarioPrestamos = (float) cantidadSolicitudesDePrestamos / dias;

    for(int i = 0 ; i < tamPrestamos; i++){

        if(prestamos[i].fechaPrestamo.dia < promedioDiarioPrestamos || flag2 == 0){
            cont2++;
            cantDiasMenorAlPromedio = cont2;
            flag2 = 1;
        }
    }

    printf("cantidad de dias cuya solicitud de prestamos NO superan el promedio: %d\n", cantDiasMenorAlPromedio);
}

void listarSociosConLibros(ePrestamos prestamos[], int tamPrestamos, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros){

    for(int i = 0; i < tamLibros; i++){
        for(int j = 0; j < tamPrestamos; j++){
            if(libros[i].codigoLibro == prestamos[i].codigoLibro){// busco la tabla intermedia que contiene dos fk
                for(int k = 0; k < tamSocios; k++){
                    if(socios[k].isEmpty == 0 && prestamos[j].codigoSocio == socios[k].codigoSocio){
                        printf("\t%10s\t%10s\t%10s\n\n", socios[k].apellido, socios[k].nombre, libros[i].titulo);
                    }
                }
            }
        }
    }

}

void listarLibrosConSocios(ePrestamos prestamos[], int tamPrestamos, eSocios socios[], int tamSocios, eLibros libros[], int tamLibros){

    for(int i = 0; i < tamSocios; i++){
        for(int j = 0; j < tamPrestamos; j++){
            if(libros[i].codigoLibro == prestamos[i].codigoLibro){// busco la tabla intermedia que contiene dos fk
                for(int k = 0; k < tamLibros; k++){
                        printf("%10s %10s",socios[i].apellido, socios[i].nombre);
                    if(socios[k].isEmpty == 0 && prestamos[j].codigoSocio == socios[k].codigoSocio){
                        printf("*%10s  %10d\n", libros[k].titulo, libros[k].codigoLibro);
                    }
                }
            }
        }
    }
}

void librosMenosSolicitados(eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos){

    int cont;
    int minimoDeSolicitados;
    int flag = 0;
    int cont2 = 0;


    for(int i = 0 ; i < tamLibros; i++){
        cont = 0;
        for(int j = 0; j < tamPrestamos; j++){
            if(libros[i].codigoLibro == prestamos[j].codigoLibro){
                cont++;
                if(flag == 0 || cont < minimoDeSolicitados){

                    minimoDeSolicitados = cont;
                    flag = 1;
                }
            }else{
                minimoDeSolicitados = 0;
                printf("%10s %10d\n\n", libros[i].titulo , libros[i].codigoLibro);
            }

    }
    }

    for(int i = 0; i < tamLibros; i++){
        cont2 = 0;
        for(int j = 0 ; j < tamPrestamos ; j++){
                if(prestamos[j].codigoLibro == libros[i].codigoLibro)
                cont2++;
        }

        while(minimoDeSolicitados <= cont2){

            printf("%10s %10d",libros[i].titulo, libros[i].codigoLibro);
        }
    }

}

void sociosConMasPrestamos(eSocios socios[], int tamSocio, ePrestamos prestamos[], int tamPrestamos ){

    int cont1;
    int cont2;
    int flag1 = 0;
    int mayorPrestamo;

    for(int i = 0; i < tamSocio; i++){
        for(int j = 0; j < tamPrestamos; j++){
            cont1 = 0;
            if(prestamos[j].codigoSocio == socios[i].codigoSocio){
                    cont1++;
                if(flag1 == 0  || cont1 > mayorPrestamo){

                }
            }
            else{
                mayorPrestamo = cont1;
            }
        }
    }

    for(int i = 0; i < tamSocio; i++){
        cont2 = 0;
        for(int j = 0 ; j < tamPrestamos ; j++){
                if(prestamos[j].codigoSocio == socios[i].codigoSocio)
                cont2++;
        }

        while(mayorPrestamo <= cont2){

            printf("%10s %10s %10d",socios[i].apellido, socios[i].nombre, socios[i].codigoSocio);
        }
    }
}

void librosSolicitadoConFecha(eLibros libros[], int tamLibros, ePrestamos prestamos[], int tamPrestamos){

    for(int i = 0; i < tamLibros ; i++){
        for(int j = 0; j < tamPrestamos; j++){
            printf("%%d/%d/%d:\n\n", prestamos[j].fechaPrestamo.dia,prestamos[j].fechaPrestamo.mes, prestamos[j].fechaPrestamo.anio );
            if(libros[i].codigoLibro == prestamos[j].codigoLibro){
                printf("%10s %10d\n\n", libros[i].titulo, libros[i].codigoLibro);
            }
        }
    }
}

void sociosAlMenosUnaSolicitud(eSocios socios[], int tamSocios, ePrestamos prestamos[], int tamPrestamos){

    for(int i = 0 ; i <tamPrestamos; i++){
            printf("%d/%d/%d",prestamos[i].fechaPrestamo.dia, prestamos[i].fechaPrestamo.mes, prestamos[i].fechaPrestamo.anio);
        for(int j = 0 ; j < tamSocios; j++){
            if(socios[j].codigoSocio == prestamos[i].codigoSocio){
                printf("%10s  %10s\n", socios[j].apellido, socios[j].nombre);
            }
        }
    }
}

void listarLibrosOrdenadoPorTitulo(eLibros libros[], int tamLibros){




    eLibros aux;
     int flagNoEstaOrdenado = 1;
     while (flagNoEstaOrdenado == 1)
     {
        flagNoEstaOrdenado = 0;
         for (int j = 1; j < tamLibros; j++)
         {
             if(strcmp(libros[j].titulo, libros[j - 1].titulo) < 0)
             {
                aux = libros[j];
                libros[j] = libros[j - 1];
                libros[j - 1] = aux;
                flagNoEstaOrdenado = 1;
             }
         }
     }

    printf("   CODIGO-LIBRO:    \tTitulo:    Codigo-Autor:\n\n");
    for(int i = 0 ; i < tamLibros; i++){

        printf("%10d\t%15s\t%10d\n", libros[i].codigoLibro, libros[i].titulo, libros[i].codigoAutor);
    }

}

void sociosOrdenadosPorApellido(eSocios socios[], int tamSocios){

    int j;
    eSocios aux;
    for(int i = 1; i < tamSocios; i++){
        aux = socios[i];
        j = i-1;

        while(j >= 0 && strcmp(aux.apellido, socios[j].apellido) < 0){

            socios[j+1] = socios[j];
            j--;
        }
        socios[j+1] = aux; // inserción
    }

    printf("codigo     nombre        apellido      sexo         telefono                                email      fecha asociado\n\n");
        for(int i=0; i < tamSocios; i++){
            if(socios[i].isEmpty == 0){
                mostrarSocios(socios[i],tamSocios);

            }
        }
        printf("\n\n");
}



