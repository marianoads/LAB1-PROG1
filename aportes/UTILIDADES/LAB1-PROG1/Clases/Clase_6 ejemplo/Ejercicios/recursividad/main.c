#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main()
{
    printf("Recursividad\n");
    int numero;

    printf("Digite un numero:\n");
    scanf("%d",&numero);

    int result = factorial(numero);
    printf("\nEl resultado es: %d", result);

    return 0;
}

int factorial(int n)
{
    printf("Entra a la funcion factorial, n vale: %i \n", n);

    if(n > 1)
    {
        printf("la funcion se llamara asi misma otra vez \n");
        return n * factorial(n - 1);
    }
    else
    {
        printf("n es igual a 1 , termina la recursividad \n");
        return 1;

    }

}

