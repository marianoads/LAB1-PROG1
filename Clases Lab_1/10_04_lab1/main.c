#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct datosPersonales
{

    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
    int codigoPostal;

};


int main()
{
    struct datosPersonales agenda;
    /*   tipo de dato */   /*variable*/

    /*strcpy(agenda.nombre , "Yanina");
    strcpy(agenda.apellido , "Scudero");
    strcpy(agenda.calle , "Avenida Mitre");
    agenda.numero = 750;

    printf("El nombre es: %s", agenda.nombre);
    printf("\nEl apellido es: %s ",agenda.apellido);
    printf("calle: %s",agenda.calle);*/


    /*printf("Ingrese el nombre\n");
    gets(agenda.nombre);
    //scanf("%s",agenda.nombre);
    fflush(stdin);

    printf("Ingrese el apellido\n");
    gets(agenda.apellido);
    fflush(stdin);

    printf("Ingrese la calle\n");
    gets(agenda.calle);
    fflush(stdin);

    printf("Ingrese el numero\n");
    scanf("%d", &agenda.numero);
    //fflush(stdin);

    printf("Ingrese el codigo postal: \n");
    scanf("%d", &agenda.codigoPostal);
    //fflush(stdin);

    printf("\nNombre: %s \n", agenda.nombre);
    printf("Apellido: %s \n", agenda.apellido);
    printf("Calle: %s \n",agenda.calle);
    printf("Numero: %d \n", agenda.numero);
    printf("Codigo Postal: %d \n",agenda.codigoPostal);*/

    struct datosPersonales vecAgenda[3], vecContactos[3], vecAmigos[3];
    int i;

    for(i =0 ; i < 3 ; i++)
    {

        printf("Ingrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngresw calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero");
        scanf("%d",&vecAgenda[i].numero);
        printf("\n\n");
        fflush(stdin);

    }



    return 0;
}
