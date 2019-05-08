#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Digite un numero: \n");
    scanf("%d",&numero);

    if(numero > 0)
    {
        printf("El numero es positivo \n");
    }
    else if(numero == 0)
    {
        printf("El numero es cero \n");
    }
    else
    {
        printf("El numero es negativo \n");
    }

    return 0;
}
