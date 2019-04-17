#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int numeroNatural = 0;

        printf("digite un numero: \n");
        scanf("%d", &numeroIngresado);
        while(numeroIngresado<= 0)
        {
            printf("Numero Invalido Ingrese solo Naturales: \n");
            scanf("%d", &numeroIngresado);
        }

        while(numeroNatural < numeroIngresado)
        {
            numeroNatural++;
            printf("\n%d\n", numeroNatural);

        }


    return 0;
}
