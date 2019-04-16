#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int aux;


    printf("Digite un numero: (num1) ");
    scanf("%d",&num1);

    printf("Digite un numero:(num2) ");
    scanf("%d",&num2);

    aux = num1;
    num1 = num2;
    num2 = aux;

    printf("Num1 : %d y Num2 : %d",num1, num2);

    return 0;
}
