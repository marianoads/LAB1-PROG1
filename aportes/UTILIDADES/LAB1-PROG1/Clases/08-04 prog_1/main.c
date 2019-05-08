#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *strlwr(char *str);

int main()
{

    char nombre[20] = {"jUan carlos"};
    char apellido[20] = {"peREZ"};
    char nombreCompleto[41];
    int i = 0;

    /*printf("Ingrese su nombre; \n");
    printf("Ingrese su apellido; \n");*/

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for( i = 0; i < strlen(nombreCompleto); i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i + 1] = toupper(nombreCompleto[i + 1]);
        }
    }

    puts(nombreCompleto);
    return 0;
}

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}
