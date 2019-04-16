#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros = 0;
    int acumulador =0;

    for(int i = 0; i < 100 ; i++)
    {
        numeros++;
        if( numeros % 3 == 0)
        {
            acumulador = acumulador + numeros;
            printf("%d \n", numeros);
        }
    }

    printf("La suma total es: %d", acumulador);

}
