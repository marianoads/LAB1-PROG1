#include <stdio.h>
#include <stdlib.h>

#define EMPLEADOS 100

int main()
{
    int legajo[EMPLEADOS];
    int salario[EMPLEADOS];
    int edad[EMPLEADOS];
    int sum = 0;
    float prom;



    for(int i = 0; i < EMPLEADOS; i++)
    {
        legajo[i] = i;
        printf("ingresar datos para el legajo %d\n",legajo[i]);
        printf("----Salario---- ");
        scanf("%d",&salario[i]);
        printf("----Edad---- ");
        scanf("%d",&edad[i]);
        printf("\n");
    }

    for(int i = 0; i < EMPLEADOS; i++)
        sum += edad[i];


        prom = sum / EMPLEADOS;


    printf("EL promedio de las edades: %.2f",prom);

    for(int i = 0; i < EMPLEADOS; i++)
    {
        if(edad[i] > prom)
        {
            printf("Legajo que supera el promedio: %d\n", legajo[i]);
        }
    }







    return 0;
}
