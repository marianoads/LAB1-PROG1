#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    int numero1;
    int numero2;
    int producto;
    int cuadrado;
    char respuesta;

    printf("Ingrese un numero \n");
    scanf("%d",&numero1);

    printf("Ingrese un numero \n");
    scanf("%d",&numero2);

    while(numero1 == 0 || numero2 == 0)
    {
        printf("Numeros Invalidos \n");
        printf("Ingrese otro numero \n");
        scanf("%d",&numero1);

        printf("Ingrese otro numero \n");
        scanf("%d",&numero2);
    }

    producto = numero1 * numero2;
    cuadrado = producto * producto;


    printf("El producto es: %d y el cuadrado es: %d \n", producto, cuadrado);

    printf("-------------Limpiar pantalla? [S/N]?----------- \n");

    fflush(stdin);
    scanf("%c", &respuesta);

    if(respuesta == 'S' || respuesta == 's')
    {
        system("clear");
        printf("Has limpiado con exito tu pantalla \n");
    }
    else
    {
        printf("No limpiaste tu pantalla \n");
    }

    return 0;
}


