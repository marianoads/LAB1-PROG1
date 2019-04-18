#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "empleados.h"




char getSexo(){

    char sexo;



    scanf(" %c", &sexo);
    sexo = tolower(sexo);
    setbuf(stdin, NULL);

    while(!(sexo == 'm' || sexo == 'f')){

        puts("ERROR ingrese un sexo valido");
        scanf(" %c", &sexo);
        sexo = tolower(sexo);

    }
    return sexo;
}

void pause(){

    setbuf(stdin,NULL);
    puts("Pulse enter para continuar");
    getchar();

}

void mostrarEmpleado(eEmpleado emp){


    printf("\t%d\t%s\t%c\t%.2f\t%d-%d-%d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio);

}
void mostrarEmpleados(eEmpleado vec[], int tam){
    int contador = 0;

    printf("\tLegajo\tNombre\tSexo\tSueldo\tfecha de nacimiento\n\n");
    for(int i=0; i < tam; i++){
        if(vec[i].ocupado == 1){
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }
}


int menu(){

    int opcion;

    puts("***  ABM EMPLEADOS ***");
    puts("1- Alta Empleado");
    puts("2- Baja Empleado");
    puts("3- Modificar Empleado");
    puts("4- Ordenar Empleados");
    puts("5- Listar Empleados");
    puts("6- Salir\n\n\n");

    printf("Ingrese Una Opcion ");

    opcion = getNumero();


    return opcion;


}

int getNumero(void){

    int input, temp, status;                        // input es el "numero" ingresado por el usuario
                                                        // temp es para recolectar caracteres basura
                                                        // status para saber si el usuario en realidad ingreso un numero


    status = scanf("%d", &input);

    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("ERROR ingrese una opcion valida: ");
        status = scanf("%d", &input);
    }

    return input;

}

void inicializarEmpleados(eEmpleado emp[],int tam){

    int i;

    for( i = 0 ; i < tam ; i++){

        emp[i].ocupado = 0;

    }
}

void altaEmpleado(eEmpleado emp[], int tam){

    int legajo;
    int indice;
    int esta;
    int c;

    indice = buscarLibre(emp, tam);

    if(indice == -1){

        printf("NO HAY LUGAR EN EL SISTEMA\n");
    }
    else{

        puts("Ingrese legajo");
        legajo = getNumero();

        esta = buscarEmpleado(legajo, emp, tam);

        if(esta != -1){
            printf("Existe un empleado de legajo %d en el sistema", legajo);
            mostrarEmpleado(emp[esta]);
        }
        else{

            emp[indice].legajo = legajo;

            puts("Ingrese nombre ");
            setbuf(stdin, NULL);
            fgets(emp[indice].nombre, sizeof(emp[indice].nombre), stdin);
            c = strlen(emp[indice].nombre);
            emp[indice].nombre[c-1] = '\0';


            puts("Ingrese sexo m/f");
            setbuf(stdin, NULL);
            emp[indice].sexo = getSexo();

            puts("Ingrese sueldo");
            scanf("%f",&emp[indice].sueldo);

            puts("Ingrese Fecha de nacimiento");
            puts("Dia");
            emp[indice].fechaNac.dia = getNumero();
            puts("Mes");
            emp[indice].fechaNac.mes = getNumero();
            puts("Anio");
            emp[indice].fechaNac.anio = getNumero();

            emp[indice].ocupado = 1;
            system("clear");
            puts("Alta empleado exitosa\n");


        }



    }
}

int buscarLibre(eEmpleado vec[],int tam){

    int libre = -1;

    for(int i = 0 ; i < tam ; i++){

       if(vec[i].ocupado == 0){

            libre = i;
            break;

       }


    }

    return libre;
}
int buscarEmpleado(int legajo , eEmpleado vec[], int tam){

    int libre;

    libre = -1;

    for(int i = 0 ; i < tam; i++){

        if(vec[i].ocupado == 1 && vec[i].legajo == legajo){
            libre = i;
            break;
        }

    }

    return libre;
}


void bajaEmpleado(eEmpleado emp[],int tam){

    int legajo;
    int esta;
    int indice;

    printf("Ingrese Legajo ");
    legajo = getNumero();

    esta = buscarEmpleado();

    if(esta == -1){

        printf("No se ha encontrado un empleado con legajo %d",legajo);
    }


}
