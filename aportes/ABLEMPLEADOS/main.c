#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 2

typedef struct{

    char nombre[20];
    char sexo;
    int legajo;
    int sueldo;
    int ocupado;




}eEmpleado;

int menu();
int getNumero();
void inicializarEmpleados(eEmpleado vec[],int tam);
void altaEmpleado(eEmpleado emp[], int tam);
int buscarLibre(eEmpleado vec[],int tam);

int main()
{
    char salir;
    int status;
    eEmpleado emp[TAM];

    inicializarEmpleados(emp, TAM);


    do{

        switch(menu()){

            case 1:
                altaEmpleado(emp,TAM);
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


                printf("Seguro que quiere salir s/n");
                setbuf(stdin, NULL);
                status = scanf("%c", &salir);
                salir = tolower(salir);

                while(status != 1){
                    printf("Error Ingrese una opcion valida\n");
                    printf("Ingrese una opcion ");
                    status = scanf("%c", &salir);
                    salir = tolower(salir);
                    printf("\n");
                }
                setbuf(stdin,NULL);

                if(salir == 's')
                    getchar();





            break;

            default:

            break;
        }



    }
    while(salir != 's');




    return 0;
}


int menu(){

    int opcion;

    puts("***  ABM EMPLEADOS ***");
    puts("1- Alta Empleado\n");
    puts("2- Baja Empleado\n");
    puts("3- Modificar Empleado\n");
    puts("4- Ordenar Empleados\n");
    puts("5- Listar Empleados\n");
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
    int libre;

    libre = buscarLibre(emp, tam);

    if(libre == -1){

        printf("NO HAY LUGAR EN EL SISTEMA\n");
    }
    else{

        printf("Ingrese Legajo ");
        legajo = getNumero();



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


