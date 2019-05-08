#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleados.h"


#define TAM_SEC 5
#define TAM_EMP 3
#define TAM_MENUES 3
#define TAM_ALMUERZOS (TAM_EMP * TAM_MENUES)


int main()
{

    eEmpleado empleado[TAM_EMP];
    eSector sectores[TAM_SEC];
    eMenu menues[TAM_MENUES];

    eAlmuerzo almuerzos[TAM_ALMUERZOS];

    char salir = 'n';

    inicializarSector(sectores, TAM_SEC);
    inicializarMenues(menues, TAM_MENUES);
    inicializarAlmuerzos(almuerzos, TAM_ALMUERZOS);
    inicializarEmpleados(empleado , TAM_EMP);

    do{
        switch(menuComedor()){

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
                altaAlmuerzo(empleado, TAM_EMP, menues, TAM_MENUES, almuerzos, TAM_ALMUERZOS,sectores, TAM_SEC);
                system("pause");
            break;


            case 7:
                listarMenues(menues, TAM_MENUES);
                system("pause");
            break;

            case 8:
                listadoMenuPorEmpleado(empleado , menues, almuerzos, TAM_EMP, TAM_MENUES );
                system("pause");

            break;
            case 9:
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
