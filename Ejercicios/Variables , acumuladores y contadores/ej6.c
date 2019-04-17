#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorPositivo = 0;
    int contadorNegativo = 0;

    for(int i = 0 ; i < 10; i++)
    {
        printf("Digite un numero: \n");
        scanf("%d", &numero);

        if(numero >= 0)
        {
            contadorPositivo++;
        }
        else
        {
            contadorNegativo++;
        }

    }

    printf("Se ingresaron %d numeros mayores que cero y %d numeros menores que cero",contadorPositivo,contadorNegativo);

    return 0;
}
