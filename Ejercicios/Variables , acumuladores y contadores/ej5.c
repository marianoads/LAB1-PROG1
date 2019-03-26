#include <stdio.h>
#include <stdlib.h>


int main()
{
    int nro;
    int cuadrado;
    printf("Digite un numero \n");
    scanf("%d",&nro );

    cuadrado = nro * nro;

    if(nro >= 0)
    {

        printf("resultado es: %d", cuadrado);

    }
    else
    {

        printf("ERROR , El numero debe ser mayor que cero \n");
    }





    return 0;
}
