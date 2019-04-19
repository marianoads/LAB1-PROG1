#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
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

/*void pause(){

    setbuf(stdin,NULL);
    printf("Press any key to continue. . . "); //para linux
    getchar();

}*/

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

    int indice;

    indice = -1;

    for(int i = 0 ; i < tam; i++){

        if(vec[i].ocupado == 1 && vec[i].legajo == legajo){
            indice = i;
            break;
        }

    }

    return indice;
}


void bajaEmpleado(eEmpleado emp[],int tam){

    int legajo;
    int esta;


    printf("Ingrese Legajo ");
    legajo = getNumero();

    esta = buscarEmpleado(legajo, emp, tam);

    if(esta == -1){

        printf("No se ha encontrado un empleado con legajo %d\n",legajo);

    }
    else{

        if(emp[esta].legajo == legajo){

            emp[esta].ocupado = 0;
            system("cls");
            printf("Se ha dado de bajo el empleado con legajo %d\n",legajo);
        }
    }

}

void modificarEmpleado(eEmpleado vec[], int tam){

    int indice;
    int legajo;
    char salir;
 //   int status;
 //   int nuevoLegajo;
    /*int nuevoSueldo;
    char nuevoNombre[20];*/

    salir = 'n';

    printf("Ingrese Legajo:\n");
    legajo = getNumero();

    indice = buscarEmpleado(legajo, vec, tam);

    if(indice == -1){
        printf("No existe el empleado de legajo %d\n",legajo);
    }
    else{

        do{
            switch(menuModificar()){

                case 'a':
                 /*   printf("Ingrese nuevo legajo\n");
                    nuevoLegajo = getNumero();
                    resp = confirmarCambios();
                   if(resp == 's'){

                        vec[indice].legajo = nuevoLegajo;

                   }
                   else{

                    break;
                   }*/



                break;

                case 'b':
                    printf("Ingrese nuevo nombre");
                break;

                case 'c':

                break;

                case 'd':

                    printf("Seguro que quiere salir s/n");

                    salir = getche();

                    salir = tolower(salir);

                   while(!(salir == 's' || salir == 'n')){

                    printf("\n\n");
                    printf("Error Ingrese una opcion valida\n");
                    printf("Ingrese una opcion");

                    salir = getche();
                    salir = tolower(salir);
                    printf("\n\n");

                 }
                break;

                default:

                break;
            }
        }
        while(!(salir == 's' ));
    }




}

int menuModificar(){
    char opcion;

    printf("a- Modificar Nombre\n");
    printf("b- Modificar Sueldo\n");
    printf("c- Modificar Fecha De Nacimiento\n");
    printf("d- Salir\n");


    opcion = getchar();
    return opcion;

}

char confirmarCambios(){

    printf("Confirma cambios? s/n");

    char resp;



    scanf(" %c", &resp);
    resp = tolower(resp);
    setbuf(stdin, NULL);

    while(!(resp == 's' || resp == 'n')){

        puts("ERROR ingrese una respuesta valida");
        scanf(" %c", &resp);
        resp = tolower(resp);

    }
    return resp;


}

void ordenarEmpleados(eEmpleado emp[],int tam,int flag){

    eEmpleado auxEmp;

    if(flag == 0){

        printf("No se pueden ordenar los empleados\n\n");
    }
    else{

        for(int i = 0 ; i < tam-1; i++){
            for(int j = i+1; j < tam ; j++){
                if(strcmp(emp[i].nombre, emp[j].nombre)> 0){

                    auxEmp = emp[i];
                    emp[i] = emp[j];
                    emp[j] = auxEmp;

                }
            }
        }

    }



}

