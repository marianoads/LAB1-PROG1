#include <stdio.h>
#include <stdlib.h>

int factorial(int);


int main()
{
    int numero;
    int limite = 0;
    int contador = 0;
    int factorial;
    int flag = 0;

    printf("Digite un numero:\n");
    scanf("%d",&numero);

    while(numero < 0)
    {
        printf("Digite un numero:\n");
        scanf("%d",&numero);
    }

    while(numero > 0)
    {

        while(contador < numero)
        {
            limite++;

            if(flag == 0)
            {
                factorial = limite;
                flag = 1;
            }
            else
            {
                factorial *= limite;
            }
            contador++;

        }

    }

    printf("%d", multiplicacion);

    return 0;
}
