#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "libreria.c"



int main()
{
    int nro1;
    int nro2;
    int nro3;
    int maximo;

    printf("Digite un numero: \n");
    scanf("%d",&nro1);

    printf("Digite un numero: \n");
    scanf("%d",&nro2);

    printf("Digite un numero: \n");
    scanf("%d",&nro3);

    maximo = obtenerMaximo(nro1, nro2 , nro3);

    printf("El maximo es: %d \n", maximo);

    return 0;
}
