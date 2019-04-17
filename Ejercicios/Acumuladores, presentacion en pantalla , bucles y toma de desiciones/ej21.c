#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int multiplos =0;
    int cont = 0;

    printf("Digite un numero:  ");
    scanf("%d", &numeroIngresado);

    while(cont < numeroIngresado)
    {
        ++multiplos;
        if(multiplos % 3 == 0)
        {
            printf("%d \n",multiplos);
        }
        cont++;
    }

    return 0;
}
