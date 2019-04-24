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
    fflush(stdin);


    while(!(sexo == 'm' || sexo == 'f')){

        fflush(stdin);
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

void mostrarEmpleado(eEmpleado emp, eSector sectores[],int tam){

    char nombreSector[20];
    int  consigio;


    consigio = obtenerSector(sectores, tam , emp.idSector, nombreSector );
    if(!consigio){
        strcpy(nombreSector, "Sin Definir");
    }


    printf("\tLegajo\tNombre\tSexo\tSueldo\tfecha de nacimiento\tSector\n");
    printf("\t%d\t%s\t%c\t%.2f\t%d-%d-%d\t%s\n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio,nombreSector);

}
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamsectores){
    int contador = 0;

   // printf("\tLegajo\tNombre\tSexo\tSueldo\tfecha de nacimiento\n\n");
    for(int i=0; i < tam; i++){
        if(vec[i].ocupado == 1){
            mostrarEmpleado(vec[i], sectores, tam);
            contador++;
        }
    }
}


int menu(){

    int opcion;

    system("cls");
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

void altaEmpleado(eEmpleado emp[], int tam, eSector sector[], int tamsectores){

    int legajo;
    int indice;
    int esta;
    int c;

    indice = buscarLibre(emp, tam);

    if(indice == -1){

        printf("NO HAY LUGAR EN EL SISTEMA\n");
    }
    else{

        printf("Ingrese legajo ");

        legajo = getNumero();

        esta = buscarEmpleado(legajo, emp, tam);

        if(esta != -1){
            printf("Existe un empleado de legajo %d en el sistema", legajo);
            mostrarEmpleado(emp[esta], sector , tamsectores);
        }
        else{

            emp[indice].legajo = legajo;

            printf("Ingrese nombre ");
            fflush(stdin);
            fgets(emp[indice].nombre, sizeof(emp[indice].nombre), stdin);
            c = strlen(emp[indice].nombre);
            emp[indice].nombre[c-1] = '\0';


            printf("Ingrese sexo m/f ");
            fflush(stdin);
            emp[indice].sexo = getSexo();

            printf("Ingrese sueldo ");
            scanf("%f",&emp[indice].sueldo);

            puts("Ingrese Fecha de nacimiento\n");
            printf("Dia ");
            emp[indice].fechaNac.dia = getNumero();

            while(emp[indice].fechaNac.dia <=0 || emp[indice].fechaNac.dia > 32){

                printf("Dia invalido: Ingrese dia ");
                emp[indice].fechaNac.dia = getNumero();
            }


            printf("Mes ");
            emp[indice].fechaNac.mes = getNumero();

            while(emp[indice].fechaNac.mes <= 0 || emp[indice].fechaNac.mes >= 13){
                printf("Mes invalido: Ingrese mes ");
                emp[indice].fechaNac.mes = getNumero();

            }
            printf("Anio ");
            emp[indice].fechaNac.anio = getNumero();
            while( emp[indice].fechaNac.anio < 1900 ||  emp[indice].fechaNac.anio > 2000){

                printf("Anio invalido: Ingrese anio ");
                 emp[indice].fechaNac.anio = getNumero();
            }

            printf("Ingrese Sector ");
            emp[indice].idSector = getNumero();

            emp[indice].ocupado = 1;

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

int obtenerSector(eSector sectores[], int tam, int id, char desc[]){

    int todoOk = 0;

    for(int i = 0 ; i < tam ; i++){

        if(sectores[i].id == id){

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;

}

