#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"
#include "input.h"




int menuComedor(){

        system("clear");
        int opcion;


        puts("\t\t****EMPLEADOS****\n");
        puts("1- Alta Empleado");
        puts("2- Baja Empleado");
        puts("3- Modificar Empleado");
        puts("4- Listar Empleados");
        puts("5- Listar Empleado Por Sector");
        puts("\t\t****Almuerzos****\n");
        puts("6- Alta Almuerzo");
        puts("7- Listar Menu");
        puts("8- Listar Menu Por Empleados\n");



        printf("Ingrese Una Opcion O Pulse 9 Para Salir ");
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

        {1, "Sopa", 120},
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

void inicializarAlmuerzos(eAlmuerzo almuerzo [], int tam){

    for(int i = 0; i < tam ; i++){
        almuerzo[i].isEmpty = 1;
    }
}


void altaEmpleado(eEmpleado empleado[] , int tamEmpleado, eSector sector[],int tamSector){

        //buscar lugar en el sistema o verctor


        int indice;


       // int input;

        indice = buscarEspacioEnElSistema(empleado , tamEmpleado);

        if(indice == -1){

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");

        }else{


                setbuf(stdin, NULL);

                //fgets(empleado[indice].nombre , sizeof(empleado[indice].nombre)-2, stdin);
                //empleado[indice].nombre[strlen(empleado[indice].nombre)-1] = '\0';
                getString(empleado[indice].nombre,"Ingrese Nombre: ", "ERROR: ingrese menos de 51 caracteres y mas de 3", 3, 51);

              /*  while(strlen(empleado[indice].nombre) > 51){

                    printf("Error No de ser mas de 51 caracteres\n");
                    printf("Ingrese Nombre ");
                    fgets(empleado[indice].nombre , sizeof(empleado[indice].nombre)-2, stdin);
                    empleado[indice].nombre[strlen(empleado[indice].nombre)-1] = '\0';

                }*/
                strlwr(empleado[indice].nombre);

               /* printf("Ingrese Apellido ");
                fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
                empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';*/

                getString(empleado[indice].apellido,"Ingrese Apellido: ", "Error: ingrese menos de 51 caracteres o mas de 3",3, 51);


                /*while(strlen(empleado[indice].apellido) > 51){

                    printf("Error No de ser mas de 51 caracteres\n");
                    printf("Ingrese Nombre ");
                    fgets(empleado[indice].apellido , sizeof(empleado[indice].apellido)-2, stdin);
                    empleado[indice].apellido[strlen(empleado[indice].apellido)-1] = '\0';

                }*/
                strlwr(empleado[indice].apellido);

              //  printf("Ingrese Sexo m/f");
                fflush(stdin);
              //  empleado[indice].sexo = getchar();
              //  empleado[indice].sexo = tolower(empleado[indice].sexo);

              getChar(&empleado[indice].sexo, "Ingrese sexo [m]/[f]: ", "Error: ingrese [m] o [f]: ",'m', 'f');


               /* while(!(empleado[indice].sexo == 'm' || empleado[indice].sexo == 'f')){

                    printf("Error: ingrese solo [m]/[f]\n");
                    printf("Ingrese Sexo ");
                    setbuf(stdin, NULL);
                    empleado[indice].sexo = getchar();
                    empleado[indice].sexo = tolower(empleado[indice].sexo);
                }*/

               /* printf("Ingrese Salario ");
                scanf("%f", &empleado[indice].salario);*/

                getFloat(&empleado[indice].salario, "Ingrese Salario: ", "Error: El salario tiene que ser mayor a cero", 0, 10000000);
             /*   while(empleado[indice].salario <= 0){

                    printf("ERROR SALARIO DEBE SER MAYOR A 0\n");
                    printf("Ingrese Salario ");
                    scanf("%f", &empleado[indice].salario);

                }*/

                printf("1- RRHH, 2- COMPRAS, 3- VENTAS, 4- SISTEMAS, 5- LEGALES\n");

                //scanf("%d", &empleado[indice].idSector);
                getInt(&empleado[indice].idSector, "Ingrese sector de trabajo: ", "Error: Ingrese un sector valido: ",1, 5);

               /* while(empleado[indice].idSector < 1 || empleado[indice].idSector > 5){
                   printf("Error sector no valido, Intente de nuevo ");
                   scanf("%d", &empleado[indice].idSector);

                }*/


                printf("\nIngrese Fecha de ingreso\n");

                getInt(&empleado[indice].fechaIngreso.dia, "Ingrese Dia: ", "Error: Ingrese un dia valido: ", 1, 31);
                getInt(&empleado[indice].fechaIngreso.mes, "Ingrese Mes: ", "Error: Ingrese un mes valido: ", 1, 12);
                getInt(&empleado[indice].fechaIngreso.anio, "Ingrese Anio: ", "Error: Ingrese un anio valido: ",1900, 2019);
               // printf("Ingrese dia ");
               /* scanf("%d", &empleado[indice].fechaIngreso.dia);
                while(empleado[indice].fechaIngreso.dia < 1 || empleado[indice].fechaIngreso.dia > 31){

                    printf("Error Dia no valido ");
                    scanf("%d", &empleado[indice].fechaIngreso.dia);

                }*

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
                }*/

               asignarLegajo(empleado , tamEmpleado, indice);
               empleado[indice].isEmpty = 0;

               system("cls");
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

        printf("No se ha encontrado un empleado con legajo %d\n\n",legajo);

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

   /* printf("Ingrese Legajo ");
    scanf("%d", &legajo);*/
    getInt(&legajo, "Ingrese Legajo: ", "ERROR: Ingrese un numero valido: ", 1001, 9999);

    indice = buscarEmpleado(empleado, tam , legajo);

    if(indice == -1){

        printf("No existe el empleado de legajo %d en el sistema \n",legajo);
    }else{

        puts("ID: 1 SECTOR: RRHH");
        puts("ID: 2 SECTOR: COMPRAS");
        puts("ID: 3 SECTOR: VENTAS");
        puts("ID: 4 SECTOR: SISTEMAS");
        puts("ID: 5 SECTOR: LEGALES");

       // printf("\n\nIngrese nro de Sector ");
       // scanf("%d", &idSector);
       getInt(&idSector,"Ingrese sector de trabajo: ", "ERROR: Ingrese sector de trabajo valido: ",1 , 5);

       /* while(idSector < 1 || idSector > 5){

            printf("ERROR: Ingrese un sector valido ");
            scanf("%d", &idSector);
        }*/

        getChar(&respuesta, "Esta seguro que quiere hacer la modificacion [s]/[n]: ", "ERROR: Opcion no invalida [s]/[n]: ", 's', 'n');
       /* printf("Esta seguro que quiere modificar el sector? s/n ");
        scanf("%c", &respuesta);

        while(!(respuesta == 's' || respuesta == 'n')){

            printf("Opcion no valida ingrese s/n ");
            scanf(" %c", &respuesta);
        }
*/
        if(respuesta == 's'){
            empleado[indice].idSector = idSector;

            printf("Se ha hecho la modificacion exitosamente \n\n");
        }else{

            printf("No se ha hecho ninguna modificacion\n");
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

void listarCantidadEmpleadosPorSector(eEmpleado empleado[], int tamEmpleado, eSector sector[], int tamSector){

    int cont;

    for(int i = 0 ; i < tamEmpleado ; i++){

        cont = 0;
        printf("Sector: %s: ", sector[i].descripcion);
        for(int j = 0; j < tamSector ; j++){

            if(empleado[j].idSector == sector[j].id && empleado[j].isEmpty == 0){
                cont++;
            }
        }
        printf("%d", cont);
    }


}

void altaAlmuerzo(eEmpleado empleado[], int tamEmpleado, eMenu menu[], int tamMenu, eAlmuerzo almuerzo[], int tamAlmuerzo, eSector sector[], int tamSector){

    int legajo;
    int ok;
    int indice;
    int codigoMenu;

        indice = buscarEspacionEnElRegistro(almuerzo, tamAlmuerzo);

        if(indice == -1){
            printf("No hay espacio en el sistema\n\n");
        }else{
            system("cls");
            listarEmpleados(empleado, tamEmpleado, sector, tamSector);

            printf("\n\nIngrese legajo: ");
            scanf("%d", &legajo);

            ok = buscarEmpleado(empleado, tamEmpleado , legajo);

            while(ok == -1){

                printf("No existe el empleado de legajo %d\n\n", legajo);
                printf("Ingrese legajo: ");
                scanf("%d", &legajo);
                ok = buscarEmpleado(empleado, tamEmpleado , legajo);
            }
            almuerzo[indice].legajoEmpleado = legajo;

            system("cls");
            printf("\n");
            listarMenues(menu, tamMenu);

            printf("Ingrese codigo de menu ");
            scanf("%d", &codigoMenu);

            ok = buscarMenu(menu, tamMenu, codigoMenu);

            while(ok == -1){
                printf("Error no existe el menu dicho codigo sea %d\n\n",codigoMenu);
                printf("Ingrese codigo de menu ");
                scanf("%d", &codigoMenu);
                ok = buscarMenu(menu, tamMenu, codigoMenu);
            }
            almuerzo[indice].codigoMenu = codigoMenu;


            printf("Ingrese Fecha: \n\n");
            printf("Ingrese Dia: ");
            scanf("%d", &almuerzo[indice].fecha.dia);

            while(almuerzo[indice].fecha.dia < 1 || almuerzo[indice].fecha.dia > 31){

                    printf("Error Dia no valido ");
                    scanf("%d", &almuerzo[indice].fecha.dia);

            }

            printf("Ingrese Mes: ");
            scanf("%d", &almuerzo[indice].fecha.mes);

            while(almuerzo[indice].fecha.mes < 1 || almuerzo[indice].fecha.mes > 12){

                    printf("Error mes no valido ");
                    scanf("%d", &almuerzo[indice].fecha.mes);

            }

            printf("Ingrese Anio ");
            scanf("%d", &almuerzo[indice].fecha.anio);
            while(almuerzo[indice].fecha.anio < 2012 ){

            printf("Anio no valido ");
            scanf("%d", &almuerzo[indice].fecha.anio);

           }
           asignarCodigoAlmuerzo(almuerzo, tamAlmuerzo, indice);
           almuerzo[indice].isEmpty = 0;

        }






}

void listarMenues(eMenu menu[], int tamMenu){

        printf("CODIGO\tDESCRIPCION\tIMPORTE\n\n");
    for(int i = 0 ; i < tamMenu; i++){

        printf("%d\t%10s\t%4d\n\n",menu[i].codigoMenu, menu[i].descripcion, menu[i].importe);
    }

}

int buscarMenu(eMenu menu[], int tamMenu, int codigoMenu){

    int ok = -1;
    for(int i = 0 ; i < tamMenu ; i++){

        if(codigoMenu == menu[i].codigoMenu){

            ok = 1;
            break;
        }

    }

    return ok;
}

void asignarCodigoAlmuerzo(eAlmuerzo almuerzo[], int tamAlmuerzo, int indice){

    int codigo = 0;

    for(int i = 0 ; i < tamAlmuerzo; i++){
        codigo++;
        if(indice == i){
                almuerzo[indice].codigoAlmuerzo = i;
                break;

        }

    }

}

int buscarEspacionEnElRegistro(eAlmuerzo almuerzo[], int tam){

    int indice = -1;

    for(int i = 0 ; i < tam ; i++){
        if(almuerzo[i].isEmpty == 1){

            indice = i;
            break;
        }
    }

    return indice;
}

