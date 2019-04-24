#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <unistd.h>


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
    char nombre[55];
    char apellido[55];
    char sexo;
    float salario;
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

int menuEmpleado();
void pause();
void inicializarSector(eSector sectores[], int tam);
void inicializarMenues(eMenu  menu[], int tam);
void inicializarEmpleados(eEmpleado empleado[] , int tam);
int buscarEspacioEnElSistema(eEmpleado empleado[], int tam);
void altaEmpleado(eEmpleado empleado[] , int tamEmpleado, eSector sector[],int tamSector);
void bajaEmpleado(eEmpleado empleado[] , int tam);

int main()
{

    eEmpleado empleado[TAM_EMP];
    eSector sectores[TAM_SEC];
    eMenu menues[TAM_MENUES];
    char salir = 'n';

    inicializarSector(sectores, TAM_SEC);
    inicializarMenues(menues, TAM_MENUES);
    inicializarEmpleados(empleado , TAM_EMP);

    do{
        switch(menuEmpleado()){

            case 1:
                altaEmpleado(empleado, TAM_EMP , sectores , TAM_SEC);
                pause();



            break;

            case 2:

            break;

            case 3:

            break;

            case 5:

            break;

            case 6:

            break;

            default:

            break;

        }

    }while(!(salir == 's'));




    return 0;
}
int menuEmpleado(){

        system("clear");
        int opcion;



        puts("1- Alta Empleado");
        puts("2- Baja Empleado");
        puts("3- Modificar Empleado");
        puts("4- Ordenar Empleados");
        puts("5- Mostrar Empleados");
        puts("6- Salir\n\n\n");

        printf("Ingrese Una Opcion ");
        scanf("%d", &opcion);

        return opcion;


}

void inicializarSector(eSector sectores[], int tam){


    eSector vec[]  ={
                    {1,"R.R.H.H"},
                    {2, "COMPRAS"},
                    {3, "VENTAS"},
                    {4,"SISTEMAS"},
                    {5,"LEGALES"}
    };

    for(int i = 0; i < tam ; i++ ){

        sectores[i] = vec[i];


    }
}

void inicializarMenues(eMenu  menu[], int tam){

    eMenu vec[] = {

        {1, "Sopa",100},
        {2, "Ensalada" ,150},
        {3, "Milaneasa" ,95},

    };

    for(int i = 0 ; i < tam ; i++){

        menu[i] = vec[i];
    }


}

void inicializarEmpleados(eEmpleado empleado[] , int tam){

    for(int i = 0; i < tam ; i++){

        empleado[i].isEmpty  = 1;

    }
}

void altaEmpleado(eEmpleado empleado[] , int tamEmpleado, eSector sector[],int tamSector){

//buscar lugar en el sistema o verctor

    int indice;
    int legajo = 1;
   // int input;

    indice = buscarEspacioEnElSistema(empleado , tamSector);

    if(indice == -1){

        printf("NO HAY ESPACIO EN EL SISTEMA\n\n");

    }else{

        setbuf(stdin, NULL);
        printf("Ingrese Nombre ");
        fgets(empleado[indice].nombre , sizeof(empleado[indice].nombre)-2, stdin);
        empleado[indice].nombre[strlen(empleado[indice].nombre)-1] = '\0';

        while(strlen(empleado[indice].nombre) > 51){

            printf("Error No de ser mas de 51 caracteres\n");
            printf("Ingrese Nombre ");
            fgets(empleado[indice].nombre , sizeof(empleado[indice].nombre)-2, stdin);
            empleado[indice].nombre[strlen(empleado[indice].nombre)-1] = '\0';

        }

        printf("Ingrese Apellido ");
        fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
        empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';

        while(strlen(empleado[indice].apellido) > 51){

            printf("Error No de ser mas de 51 caracteres\n");
            printf("Ingrese Nombre ");
            fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
            empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';

        }

        printf("Ingrese Sexo m/f");
        setbuf(stdin, NULL);
        scanf("%c", &empleado[indice].sexo);

        while(!(empleado[indice].sexo == 'm' || empleado[indice].sexo == 'f')){

            printf("Error: ingrese solo [m]/[f]\n");
            printf("Ingrese Sexo ");
            setbuf(stdin, NULL);
            scanf("%c", &empleado[indice].sexo);
        }

        printf("Ingrese Salario ");
        scanf("%f", &empleado[indice].salario);

        while(empleado[indice].salario <= 0){

            printf("ERROR SALARIO DEBE SER MAYOR A 0\n");
            printf("Ingrese Salario ");
            scanf("%f", &empleado[indice].salario);

        }

        printf("Ingrese Fecha de ingreso\n");

        printf("Ingrese dia ");
        scanf("%d", &empleado[indice].fechaIngreso.dia);
        while(empleado[indice].fechaIngreso.dia < 1 || empleado[indice].fechaIngreso.dia > 31){

            printf("Error Dia no valido ");
            scanf("%d", &empleado[indice].fechaIngreso.dia);

        }

        printf("Ingrese mes ");
        scanf("%d", &empleado[indice].fechaIngreso.mes);
        while(empleado[indice].fechaIngreso.mes < 1 || empleado[indice].fechaIngreso.mes > 12){

            printf("Error mes no valido ");
            scanf("%d", &empleado[indice].fechaIngreso.mes);

        }

        printf("Ingrese anio ");
        scanf("%d", &empleado[indice].fechaIngreso.anio);
        while(empleado[indice].fechaIngreso.anio < 1900){

            printf("Error anio no valido ");
            scanf("%d", &empleado[indice].fechaIngreso.anio);
        }


        empleado[indice].legajo = legajo;
        empleado[indice].isEmpty = 0;




        printf("La alta se ha hecho exitosa\n\n");

        legajo++;



    }






}

int buscarEspacioEnElSistema(eEmpleado empleado[], int tam){

    int indice = -1;

    for(int i = 0 ; i < tam ; i++){

        if(empleado[i].isEmpty == 1){

            indice = i;
            break;

        }

    }

    return indice;

}

void bajaEmpleado(eEmpleado empleado[] , int tam){

    int legajo;
    int indice = -1;
    char resp;

    printf("Ingrese legajo ");
    scanf("%d", &legajo);

    for(int i = 0 ; i < tam ; i++){

        if(legajo == empleado[i].legajo){

            indice = i;
            break;

        }
    }

    if(indice == -1 ){

        printf("No se ha encontrado un empleado con legajo %d",legajo);

    }else{

        printf("Esta seguro que quiere dar de baja el empleado %d\n", legajo);
        printf("s/n? ");
        setbuf(stdin, NULL);
        scanf("%c", &resp);
        resp = tolower(resp);
        while(!(resp == 's' || resp == 'n')){

            printf("Opcion no validad ingrese 's' o 'n' ");
             scanf("%c", &resp);

        }

        if(resp == 's'){
            empleado[indice].isEmpty = 1;

            printf("Se ha dado de baja el empleado exitosamente\n");
        }



    }


}

void pause(){

printf("Press any key to continue. . .");
                setbuf(stdin , NULL);
                getchar();

}






