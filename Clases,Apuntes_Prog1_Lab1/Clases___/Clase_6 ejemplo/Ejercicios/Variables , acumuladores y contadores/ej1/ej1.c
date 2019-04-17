#include <stdio.h>

int main()
{
    int numero;
    int sum = 0;
    int cont = 0;
    float media;

    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero:");
        scanf("%d", &numero);
        sum = sum + numero;
        cont++;

    }

    media = (float) sum / cont;
    printf("La media es: %f", media);
    return 0;
}
