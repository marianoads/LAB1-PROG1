#include <stdio.h>
#include <stdlib.h>

int main()
{

     float num1;
     float num2;
     float sum;

    printf("Ingrese un numero: \n");
    scanf("%f", &num1);
    printf("Ingrese otro numero: \n");
    scanf("%f",&num2);

    sum = num1 + num2;

    printf("Suma: %.3f", sum);

    return 0;
}
