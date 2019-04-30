#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#define TAM_SEC 5
#define TAM_EMP 3
#define TAM_MENUES 3
#define TAM_ALMUERZOS (TAM_EMP * TAM_MENUES)



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
    int legajoEmpleado;
    eFecha fecha;


}eAlmuerzo;


typedef struct{

    int codigoMenu;//autoincremental
    char descripcion[51];
    int importe;
}eMenu;

int menuEmpleado();
//void pause();
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
void listarEmpleadosPorSector(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector);
void listadoMenuPorEmpleado ( eEmpleado empleados[], eMenu menues[], eAlmuerzo almuerzos[], int cantEmp, int cantMenu );

int main()
{

    eEmpleado empleado[TAM_EMP] = {
        {1001, "GILBERTO","CALDERON",'m', 120000,{02,11,2000},1,0},
         {1002, "PEDRO","SANCHEZ",'m', 120000,{1,4,1998},1,0},
          {1003, "MARIA","BALVUENA",'f', 120000,{02,12,2000},4,0}



    };
    eSector sectores[TAM_SEC] =  {
                    {1,"R.R.H.H"},
                    {2, "COMPRAS"},
                    {3, "VENTAS"},
                    {4,"SISTEMAS"},

                    {5,"LEGALES"}
    };
    eMenu menues[TAM_MENUES] =  {

        {1, "Sopa",100},
        {2, "Ensalada" ,150},
        {3, "Milaneasa" ,95},

    };

    eAlmuerzo almuerzos[] = {
        {0001, 1, 1001, {02, 11 , 2012}},
        {0002, 2, 1002, {04, 12, 2014}},
        {0003, 3, 1003, {30, 7, 2019}}


    };

    char salir = 'n';

   // inicializarSector(sectores, TAM_SEC);
   // inicializarMenues(menues, TAM_MENUES);
    //inicializarEmpleados(empleado , TAM_EMP);

    do{
        switch(menuEmpleado()){

            case 1:
                altaEmpleado(empleado, TAM_EMP , sectores , TAM_SEC);
                system("pause");
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
                system("pause");

            break;

            case 5:
                listarEmpleadosPorSector(empleado, TAM_EMP, sectores, TAM_SEC);
                system("pause");
            break;

            case 6:
                listadoMenuPorEmpleado(empleado , menues, almuerzos, TAM_EMP, TAM_MENUES );
                system("pause");

            break;

            case 7:
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


        puts("-------------------------EMPLEADOS-----------------------------\n");
        puts("1- Alta Empleado");
        puts("2- Baja Empleado");
        puts("3- Modificar Empleado");
        puts("4- Listar Empleados");
        puts("5- Listar Empleado Por Sector");
        puts("6- Listar Menu Por Empleados");
        puts("7- Salir\n\n\n");

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
                strlwr(empleado[indice].nombre);

                printf("Ingrese Apellido ");
                fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
                empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';

                while(strlen(empleado[indice].apellido) > 51){

                    printf("Error No de ser mas de 51 caracteres\n");
                    printf("Ingrese Nombre ");
                    fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
                    empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';

                }
                strlwr(empleado[indice].apellido);

                printf("Ingrese Sexo m/f");
                setbuf(stdin, NULL);
                empleado[indice].sexo = getchar();
                empleado[indice].sexo = tolower(empleado[indice].sexo);

                while(!(empleado[indice].sexo == 'm' || empleado[indice].sexo == 'f')){

                    printf("Error: ingrese solo [m]/[f]\n");
                    printf("Ingrese Sexo ");
                    setbuf(stdin, NULL);
                    empleado[indice].sexo = getchar();
                    empleado[indice].sexo = tolower(empleado[indice].sexo);
                }

                printf("Ingrese Salario ");
                scanf("%f", &empleado[indice].salario);

                while(empleado[indice].salario <= 0){

                    printf("ERROR SALARIO DEBE SER MAYOR A 0\n");
                    printf("Ingrese Salario ");
                    scanf("%f", &empleado[indice].salario);

                }
                puts("\nIngrese sector de trabajo");
                puts("1- RRHH, 2- COMPRAS, 3- VENTAS, 4- SISTEMAS, 5- LEGALES");

                scanf("%d", &empleado[indice].idSector);

                while(empleado[indice].idSector < 1 || empleado[indice].idSector > 5){
                   printf("Error sector no valido, Intente de nuevo ");
                   scanf("%d", &empleado[indice].idSector);

                }


                printf("\n\nIngrese Fecha de ingreso\n");

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

    int legajo = 1000;



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

/*void pause(){

        printf("Press any key to continue. . .");
        setbuf(stdin , NULL);
        getchar();

}*/

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

    puts("-------------------------MODIFICAR EMPLEADOS-----------------------------\n");
    puts("1- Modificar Nombre");
    puts("2- Modificar Apellido");
    puts("3- Modificar Salario");
    puts("4- Modificar Sexo");
    puts("5- Modificar Fecha De Ingreso");
    puts("6- Modificar Sector");
    puts("7- Salir\n\n");

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
       fflush(stdin);
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

            printf("Se ha cambiado el nombre del empleado %d\n", legajo);
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
       fflush(stdin);
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

        printf("Ingrese Sexo: m/f");
        fflush(stdin);
        scanf(" %c", &sexo);
        sexo = tolower(sexo);

        while(!(sexo == 'm' || sexo == 'f')){

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

    setbuf(stdin, NULL);
    salir = getche();
 //   salir = getchar();

    salir = tolower(salir);

    while(!(salir == 's' || salir == 'n')){

        printf("\n\n");
        printf("Error Ingrese una opcion valida\n");
        printf("Ingrese una opcion");

        salir = getche();
        //salir = getchar();
        salir = tolower(salir);
        printf("\n\n");

    }
    printf("\n\n");
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

void listarEmpleadosPorSector(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector){

    system("clear");
    for(int i = 0 ; i < tamSector; i++){

            printf("Sector: %s\n\n",sector[i].descripcion);
        for(int j = 0 ; j < tamEmpleado; j++ ){
            if(empleado[j].isEmpty == 0 && empleado[j].idSector == sector[i].id){

                printf("  %d   %s   %s\n\n",empleado[j].legajo, empleado[j].nombre, empleado[j].apellido);
            }
        }
    }

}

void listadoMenuPorEmpleado ( eEmpleado empleados[], eMenu menues[], eAlmuerzo almuerzos[], int tamEmpleados, int tamMenues )
{
    int i, j, k;

    printf("\n****** LISTADO DE MENU POR EMPLEADOS ******\n\n");


  for( i = 0; i < tamMenues; i++)
  {
        for( j = 0; j < (tamEmpleados * tamMenues); j++ ) // recorro los almuerzos
        {
         if( menues[i].codigoMenu == almuerzos[j].codigoMenu )  // busco la interseccion
         {
			for( k = 0; k < tamEmpleados; k++ ){ // recorro los empleados
				if( empleados[k].isEmpty == 0 && almuerzos[j].legajoEmpleado == empleados[k].legajo ){
					printf("%d %s %s\n", empleados[k].legajo, empleados[k].nombre, menues[i].descripcion );
				}

			}
         }
        } //Cierre 2do for
  } // cierre 1er for

}

