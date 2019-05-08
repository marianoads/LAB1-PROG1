/*Estructuras - Definicion y Declaracion
*/
#include <stdio.h>
#include <stdlib.h>
//Definición de Estructura
struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
};
int main()
{   //Declaracion de variable agenda de tipo datosPersonales
    struct datosPersonales agenda;
    return 0;
}
