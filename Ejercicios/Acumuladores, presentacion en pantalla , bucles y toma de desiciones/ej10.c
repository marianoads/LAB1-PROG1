#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numeros = 0;
    int contadorImpar = 0;

    for(int i = 0; i < 100; i++)
    {
        if(numeros % 2 != 0)
        {
            printf("%d \n", numeros);
            contadorImpar++;
        }
        numeros++;
    }

    printf("Hay %d numeros impares desde el cero hasta el cien \n",contadorImpar);

}
