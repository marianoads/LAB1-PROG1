#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float superficie;

    printf("Digite la base: \n");
    scanf("%f", &base);
    printf("Digite la altura \n");
    scanf(" %f", &altura);

    superficie = (base * altura) / 2;

    printf("Superficie del triangulo: %.2f",superficie);

    return 0;
}
