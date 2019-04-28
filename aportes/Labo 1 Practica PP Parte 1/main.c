#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>


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
char opcionSalir();
void altaEmpleado(eEmpleado empleado[] , int tamEmpleado, eSector sector[],int tamSector);
int asignarSector(eSector sector[], int tamSector, char descripcion[], int idSector);
void asignarLegajo(eEmpleado empleado[] , int tam, int indice);
int menuModificar();
void modificarEmpleado(eEmpleado empleado[] , int tamEmpleado);
void modificarNombre(eEmpleado empleado[], int tam );
void modificarApellido(eEmpleado empleado[], int tam);
void modificarFechaDeIngreso(eEmpleado empleado[] , int tam);
void modificarSalario(eEmpleado empleado[], int tam);
void modificarSector(eEmpleado empleado[], int tam );
void modificarSexo(eEmpleado empleado[], int tam);
void bajaEmpleado(eEmpleado empleado[] , int tam);
void mostrarEmpleado(eEmpleado empleado, eSector sector[], int tamSector);
void listarEmpleados(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector);

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
              //  system("pause");
              pause();


            break;

            case 2:
                bajaEmpleado(empleado, TAM_EMP);
                system("pause");

            break;

            case 3:
                modificarEmpleado(empleado , TAM_EMP);
                system("pause");
            break;

            case 4:
                listarEmpleados(empleado, TAM_EMP, sectores, TAM_SEC);
               // system("pause");
               pause();
            break;

            case 5:
                salir = opcionSalir();
            break;

            default:
                printf("opcion invalida\n");
                system("pause");

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
        puts("4- Listar Empleados");
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

               asignarLegajo(empleado , tamEmpleado, indice);
               empleado[indice].isEmpty = 0;

                printf("La alta se ha hecho exitosamente\n");

    }



}

void asignarLegajo(eEmpleado empleado[] , int tam, int indice){

    int legajo = 0;



    for(int i = 0 ; i < tam ; i++){
            legajo++;

        if(i == indice){

          empleado[indice].legajo = legajo;
          break;
        }


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

int buscarEmpleado(eEmpleado empleado[], int tamEmpleado, int legajo){

    int indice = -1;

    for(int i = 0 ; i < tamEmpleado; i++){

        if(legajo == empleado[i].legajo){

            indice = i;
            break;
        }
    }

    return indice;
}


void modificarEmpleado(eEmpleado empleado[] , int tamEmpleado){

    char salir;
 //   int status;
 //   int nuevoLegajo;
    /*int nuevoSueldo;
    char nuevoNombre[20];*/

    salir = 'n';


        do{
            switch(menuModificar()){

                case 1:

                    modificarNombre(empleado, tamEmpleado);
                    system("pause");


                break;

                case 2:
                    modificarApellido(empleado, tamEmpleado );
                    system("pause");
                break;

                case 3:
                    modificarSalario(empleado, tamEmpleado);
                    system("pause");

                break;

                case 4:
                    modificarSexo(empleado, tamEmpleado);
                    system("pause");
                break;

                case 5:
                    modificarFechaDeIngreso(empleado, tamEmpleado);
                    system("pause");

                break;

                case 6:
                    modificarSector(empleado, tamEmpleado);
                    system("pause");
                break;

                case 7:
                    salir = opcionSalir();
                break;

                default:
                    printf("Opcion no valida \n\n");
                    system("pause");


                break;
            }
        }
        while(!(salir == 's' ));
    }




int menuModificar(){

    system("cls");
    int opcion;

    printf("-------Modificar Empleados-------\n");
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar Sexo\n");
    printf("5- Modificar Fecha De Ingreso\n");
    printf("6- Modificar Sector\n");
    printf("7- Salir\n\n");

    printf("Ingrese una opcion ");
    scanf("%d", &opcion);

    return opcion;
}

void modificarNombre(eEmpleado empleado[], int tam ){


    int legajo;
    int indice;
    char nombre[55];
    char respuesta;

    printf("Ingrese Legajo:\n");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam, legajo);

    if(indice == -1){
        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

       printf("Ingrese nuevo nombre: ");
       fgets(nombre, sizeof(nombre)-2, stdin);
       nombre[strlen(nombre)-1] = '\0';

       printf("Nombre anterior: %s , Nombre Nuevo: %s\n", nombre, empleado[indice].nombre);
       printf("Esta seguro que desea cambiar el nombre del legajo NRO %d [s/n] ", legajo);

       scanf(" %c", &respuesta);
       respuesta = tolower(respuesta);

       printf("\n");
       while(!(respuesta == 's' || respuesta == 'n')){

            printf("Opcion invalida ingrese [s/n] ");
            scanf(" %c", &respuesta);
            respuesta = tolower(respuesta);
       }

       if(respuesta == 's'){

            strcpy(empleado[indice].nombre, nombre);

            printf("Se ha cambiado el nombre del empleado %d", legajo);
       }else{

            printf("no se han realizado ningun cambio\n");
       }

    }






}

void modificarApellido(eEmpleado empleado[], int tam){

    int legajo;
    int indice;
    char apellido[55];
    char respuesta;

    printf("Ingrese Legajo:\n");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam, legajo);

    if(indice == -1){
        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

       printf("Ingrese nuevo apellido: ");
       fgets(apellido, sizeof(apellido)-2, stdin);
       apellido[strlen(apellido)-1] = '\0';

       printf("Apellido anterior: %s , Apellido Nuevo: %s\n", apellido, empleado[indice].apellido);
       printf("Esta seguro que desea cambiar el nombre del legajo NRO %d [s/n] ", legajo);

       scanf(" %c", &respuesta);
       respuesta = tolower(respuesta);

       printf("\n");
       while(!(respuesta == 's' || respuesta == 'n')){

            printf("Opcion invalida ingrese [s/n] ");
            scanf(" %c", &respuesta);
            respuesta = tolower(respuesta);
       }

       if(respuesta == 's'){

            strcpy(empleado[indice].apellido, apellido);

            printf("Se ha cambiado el apellido del empleado %d", legajo);
       }else{

            printf("no se han realizado ningun cambio\n");
       }

    }

}

void modificarSalario(eEmpleado empleado[], int tam){

    int legajo;
    int indice;
    float salario;
    char respuesta;

    printf("Ingrese Legajo:\n");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam, legajo);

    if(indice == -1){
        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

        printf("Ingrese nuevo salario ");
        scanf("%f", &salario);

        printf("Esta seguro que quiere modificar el salario ");
        scanf(" %c", &respuesta);

        while(!(respuesta == 's' || respuesta == 'n')){

            printf("Respuesta invalida ingrese s/n");
            scanf(" %c",&respuesta);
        }

        if(respuesta == 's'){

            empleado[indice].salario = salario;

        }else{

            printf("No se han realizado ningun cambio\n");

        }
    }

}
void modificarSexo(eEmpleado empleado[], int tam){

    int legajo;
    int indice;
    char sexo;
    char respuesta;

    printf("Ingrese Legajo ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam , legajo);

    if(indice == -1){

        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

        printf("Ingrese Sexo: s/n");
        scanf(" %c", &sexo);
        sexo = tolower(sexo);

        while(!(sexo == 's' || sexo == 'n')){

            printf("Error ingrese una opcion valida: s/n");
            scanf(" %c", &sexo);
            sexo = tolower(sexo);
        }

        printf("Esta seguro que quiere modificar sexo? s/n ");
        scanf(" %c", &respuesta);

        if(respuesta == 's'){
            empleado[indice].sexo = sexo;

            printf("Se ha modifica el sexo del empleado %d\n",legajo);

        }else{

            printf("No se han realizado ninguna modificacion\n");
        }

    }
}

void modificarFechaDeIngreso(eEmpleado empleado[] , int tam){

    int legajo;
    int indice;
    char respuesta;
    int dia;
    int mes;
    int anio;

    printf("Ingrese Legajo ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam , legajo);

    if(indice == -1){

        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

        printf("Ingrese fecha de ingreso ");
        printf("Dia: ");
        scanf("%d", &dia);
        while(dia < 1 || dia > 31){

            printf("Dia no valido ");
            scanf("%d", &dia);

        }
        printf("Mes: ");
        scanf("%d", &mes);
        while(mes < 1 || mes > 31){

            printf("Mes no valido ");
            scanf("%d", &mes);
        }
        printf("Anio: ");
        scanf("%d", &anio);
        while(anio < 1900 ){

            printf("Anio no valido ");
            scanf("%d", &anio);

        }

        printf("Esta seguro que quiere modificar la fecha de ingreso? s/n ");
        scanf(" %c", &respuesta);

        while(!(respuesta == 's' || respuesta == 'n')){
            printf("Error ingrese una opcion valida ");
            scanf(" %c", &respuesta);

        }

        if(respuesta == 's'){
            empleado[indice].fechaIngreso.dia = dia;
            empleado[indice].fechaIngreso.mes = mes;
            empleado[indice].fechaIngreso.anio = anio;


            printf("Se ha modifica la fecha de ingreso del empleado %d\n",legajo);

        }else{

            printf("No se han realizado ninguna modificacion\n");
        }


    }

}

void modificarSector(eEmpleado empleado[], int tam ){

    int legajo;
    int indice;
    char respuesta;
    int idSector;

    printf("Ingrese Legajo ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleado, tam , legajo);

    if(indice == -1){

        printf("No existe el empleado de legajo en el sistema %d\n",legajo);
    }else{

        puts("ID: 1 SECTOR: RRHH");
        puts("ID: 2 SECTOR: COMPRAS");
        puts("ID: 3 SECTOR: VENTAS");
        puts("ID: 4 SECTOR: SISTEMAS");
        puts("ID: 5 SECTOR: LEGALES");

        printf("\n\nIngrese nro de Sector ");
        scanf("%d", &idSector);

        while(idSector < 1 || idSector > 5){

            printf("ERROR: Ingrese un sector valido ");
            scanf("%d", &idSector);
        }

        printf("Esta seguro que quiere modificar el sector? s/n ");
        scanf("%c", &respuesta);

        while(!(respuesta == 's' || respuesta == 'n')){

            printf("Opcion no valida ingrese s/n ");
            scanf(" %c", &respuesta);
        }

        if(respuesta == 's'){
            empleado[indice].idSector = idSector;

            printf("Se ha hecho la modificacion exitosamente \n\n");
        }else{

            printf("No se ha hecho ninguna modificacio\n");
        }


    }

}

char opcionSalir(){

    char salir;
    printf("Seguro que quiere salir s/n");

    // salir = getche();
    salir = getchar();

    salir = tolower(salir);

    while(!(salir == 's' || salir == 'n')){

        printf("\n\n");
        printf("Error Ingrese una opcion valida\n");
        printf("Ingrese una opcion");

//        salir = getche();
        salir = getchar();
        salir = tolower(salir);
        printf("\n\n");

    }
        return salir;
}

void listarEmpleados(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector){

   /* eEmpleado auxEmpleado;

    for(int i = 0; i < tamEmpleado-1; i++){
        for(int j = i+1 ; j < tamEmpleado; j++){
            if(strcmp(empleado[i].nombre, empleado[j].nombre)> 0 && strcmp(empleado[i].apellido, empleado[j].apellido)> 0){

                auxEmpleado = empleado[i];
                empleado[i] = empleado[j];
                empleado[j] = auxEmpleado;

            }
        }
    }*/

        printf("LEGAJO NOMBRE APELLIDO SEXO SALARIO FECHA DE INGRESO\tSECTOR\n\n");
        for(int i=0; i < tamEmpleado; i++){
            if(empleado[i].isEmpty == 0){
                mostrarEmpleado(empleado[i], sector, tamSector);

            }
        }
}





void mostrarEmpleado(eEmpleado empleado, eSector sector[], int tamSector){

    char descripcionSector[30];
    int gotit;

    gotit = asignarSector(sector, tamSector, descripcionSector, empleado.idSector);

    if(gotit == -1){

        strcpy(descripcionSector, "Sin Definir");
    }

   // ;
    printf("%d   %s   %s   %c  %.0f  %d--%d--%d  %s\n",empleado.legajo, empleado.nombre, empleado.apellido,empleado.sexo,empleado.salario,empleado.fechaIngreso.dia,empleado.fechaIngreso.mes,empleado.fechaIngreso.anio,descripcionSector);
}

int asignarSector(eSector sector[], int tamSector, char descripcion[], int idSector){

    int oK = -1;
    int i;

    for(i = 0 ; i < tamSector ; i++){
        if(sector[i].id == idSector){

            strcpy(descripcion, sector[i].descripcion);
            oK = 1;
        }

    }

    return oK;
}
