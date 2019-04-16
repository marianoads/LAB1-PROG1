/*Estructuras - Carga de Datos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;
};

int main()
{
 struct datosPersonales agenda, contactos;

        printf("Ingrese el Nombre ");
        gets(agenda.nombre);
        fflush(stdin);

        printf("\nIngrese el apellido ");
        gets(agenda.apellido);
        fflush(stdin);

        printf("\nIngrese calle ");
        gets(agenda.calle);
        fflush(stdin);

        printf("\nIngrese numero de calle ");
        scanf("%d",&agenda.numero);

        contactos = agenda;

        //Mostrar datos
        printf("\nDatos Personales");
        printf("\n%s", contactos.nombre);
        printf("\n%s", contactos.apellido);
        printf("\n%s", contactos.calle);
        printf("\n%d", contactos.numero);



    return 0;
}
