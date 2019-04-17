#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio;
    float diametro;
    float longitud;
    float area;

    printf("Ingrese el radio de un circulo \n");
    scanf("%f",&radio);

    diametro = radio * radio;

    area = 3.1415 * diametro;

    longitud = 2 * 3.1415 * radio;


    printf("El area es: %f, y la longitud: %f", area , longitud);


}


