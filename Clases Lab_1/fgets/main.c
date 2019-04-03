#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;

    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);

    cantidad = strlen(buffer); //cantidad de elementos de una cadena

    buffer[cantidad-1] = '\0';

    printf("%s", buffer);

    return 0;
}
