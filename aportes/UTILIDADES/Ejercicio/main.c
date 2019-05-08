#include <stdio.h>
#include <stdlib.h>

#define TAM 3
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;

}eEmpleado;

int menu();
void inicializarEmpleado(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);


int main()
{
    int opcion;
    char seguir = 's';


    do
    {


        switch(menu())
        {
            case 1:
                printf("ALTA Empleado:\n");

            break;


            case 2:
                printf("BAJA Empleado:\n");

            break;


            case 3:
                printf("MODIFICACION Empleado:\n");

            break;


            case 4:
                printf("LISTAR Empleados:\n");

            break;


            case 5:
                printf("ORDENAR Empleados:\n");

            break;


            case 6:
                printf("Confirma salir? (s/n)\n");
                scanf("%c", &seguir);

                if(seguir == 's')
                {
                    seguir = 'n';
                }
            break;


            default:
                printf("No es un numero valido, reingrese.");
            break;



        }

    }
    while(seguir == 's');




    return 0;
}


void inicializarEmpleado(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].ocupado = 0;
    }

}


void mostrarEmpleado(eEmpleado emp)
{
    printf("%d     %s     %c     %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}


void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;

    printf("Legajo     Nombre     Sexo     Sueldo\n\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado ==1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }

    if(contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }


}

int menu()
{
    int opcion;
    printf(" *** ABM Empleados ***\n\n");
        printf("1- ALTA Empleado\n");
        printf("2- BAJA Empleado\n");
        printf("3- MODIFICACION Empleado\n");
        printf("4- LISTAR Empleados\n");
        printf("5- ORDENAR Empleados\n");
        printf("6- Salir\n\n");

        opcion = obtenerNumero();

        return opcion;
}

int obtenerNumero(void)
{
        int input, temp, status;                            // input	user input -- hopefully a number
                                                        // temp		used to collect garbage characters
                                                        // status	did the user enter a number?
    status = scanf("%d", &input);

    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Numero invalido ingrese un numero: ");
        status = scanf("%d", &input);
    }

    return input;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        if(vec[i].ocupado == 0){
            return i;

        }else{
            return -1;
        }
    }

}
