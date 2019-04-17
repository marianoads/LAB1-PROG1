#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cont = 0;
    int sumaPositivos = 0;
    int bandera = 0;
    int productoNegativos;


    while(cont < 10 )
    {
        printf("Digite un numero: \n");
        scanf("%d", &numero);

        while(numero == 0)
        {
            printf("Numero Invalido \n \n");
            printf("Digite un numero distinto de cero: \n");
            scanf("%d", &numero);
        }

        if(numero > 0)
        {
            sumaPositivos += numero;
        }

        if(numero < 0)
        {
            if(bandera == 0)
            {
                productoNegativos = numero;
                bandera = 1;
            }
            else
            {
                productoNegativos *= numero;
            }

        }

        cont++;

    }

    printf("-----Productos de los negativos: %d \n", productoNegativos);
    printf("-----Suma total de los positivos:%d \n", sumaPositivos);

}
