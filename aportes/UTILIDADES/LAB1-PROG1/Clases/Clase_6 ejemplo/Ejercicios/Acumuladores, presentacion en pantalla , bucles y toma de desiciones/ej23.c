#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro1;
    int nro2;
    int nro3;
    int mayor;

    printf("Digite un numero:\n");
    scanf("%d", &nro1);

    printf("Digite un numero:\n");
    scanf("%d", &nro2);

    printf("Digite un numero:\n");
    scanf("%d", &nro3);

    if(nro1 >= nro2 && nro1 >= nro3)
    {
        mayor = nro1;
    }
    else if(nro2 >= nro1 && nro2 >= nro3)
    {
       mayor = nro2;
    }
    else
    {
        mayor = nro3;
    }


    printf("El numero mayor es: %d", mayor);

    return 0;
}
