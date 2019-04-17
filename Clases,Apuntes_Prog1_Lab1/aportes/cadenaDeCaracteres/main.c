#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //string

    char cadena[50];
                                                                        // en string al final esta el elemento \0
    //fflush(stdin);                                                      //49 letras
    //scanf("%s", cadena);  no te toma el espacio
    //gets(cadena); // no existe en linux , te tooma el espacio           // no se pone amperson sino el nombre del vector
    // no se recomienda el uso de gets
    //fgets(); // te añade un
    //printf("%s",cadena);                                               // cadena es la direccion de memoria del primer indice  //cadena == &cadena[10]


   /*
   fgets

   int c;                                                // en un vector char tengo un caracter
    printf("Ingrese un nombre: ");
    fgets(cadena , sizeof(cadena)-2, stdin);

    c = strlen(cadena);
    cadena[c-1] = '\0';

    printf("%s", cadena);*


    return 0;
}
