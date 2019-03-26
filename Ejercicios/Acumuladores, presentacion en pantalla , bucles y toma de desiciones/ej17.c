#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Digite un numero \n");
    scanf("%d", &numero);

    if(numero % 2 == 0)
    {
        printf("El numero es par \n");

    }
    else
    {
        printf("El numero es impar \n");
    }
    return 0;
}
