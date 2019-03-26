#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    float peso;
    int cantPesoMayor80 = 0;
    int cantPesoHasta80 = 0;
    char respuesta;

    do
    {
        printf("Ingrese el peso: \n ");
        scanf("%fw",&peso);


        while(peso <= 0  )
        {
            printf("Peso invalido ingrese otra vez: ");
            scanf("%f",&peso);
        }




        if(peso <= 80)
        {
            cantPesoHasta80++;
        }
        else
        {
            cantPesoMayor80++;
        }


        fflush(stdin);
        printf("Desea continuar?\nPulse [N] Para finalizar sino pulse cualquier tecla\n");
        scanf("%c",&respuesta);

        respuesta = toupper(respuesta);

    }
    while(respuesta != 'N');


    printf("Empleados que pesan hasta 80kg %d\n", cantPesoHasta80);
    printf("Empleados que pesan mas de 80kg %d\n",cantPesoMayor80);
    return 0;
}
