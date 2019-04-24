#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_SEC 5
#define TAM_EMP 3
#define TAM_MENUES 3



typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;
typedef struct{

    int legajo; //autoincremental
    char nombre[20];
    char apellido[20];
    char sexo;
    int salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;


}eEmpleado;

typedef struct{

    int id; // autoincremental
    char descripcion[51];

}eSector;

typedef struct{
    int codigoAlmuerzo;
    int codigoMenu;
    int LegajoEmpleado;
    eFecha fecha;


}eAlmuerzo;


typedef struct{

    int codigoMenu;//autoincremental
    char descripcion[51];
    int importe;
}eMenu;


void inicializarSector(eSector sectores[], int tam);

int main()
{

    eEmpleado empleado[TAM_EMP];
    eSector sectores[TAM_SEC];
    eMenu menues[TAM_MENUES];

    inicializarSector(sectores, TAM_SEC);

    for(int i = 0 ; i < TAM_SEC; i++){

        printf("-- %s\n",sectores[i].descripcion);
    }




    return 0;
}

void inicializarSector(eSector sectores[], int tam){


    eSector vec[]  ={
                    1,"R.R.H.H",
                    2, "COMPRAS",
                    3, "VENTAS",
                    4,"SISTEMAS",
                    5,"LEGALES" };

    for(int i = 0; i < tam ; i++ ){

        sectores[i].id = vec[i].id;
        strcpy(sectores[i].descripcion, vec[i].descripcion);


    }
}


