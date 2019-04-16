#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "obtenerDatos.h"

#define TAM 5



int main()
{
    int edad[TAM];
    char sexo[TAM];
    int legajo[TAM];
    int suma = 0;
    int flag = 0;
    int auxEdad;
    int auxSexo;
    int auxLegajo;
    int mujeres1978 = 0;



    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese edad:\n");
        edad[i] = obtenerNumero();
        printf("Ingrese un sexo: [F]/[M]?\n");
        sexo[i] = obtenerSexo();
        printf("Ingrese el legajo:\n");
        legajo[i] = obtenerNumero();


    }

    for(int i = 0 ; i < TAM ; i++)
    {
        suma += edad[i];

        if(flag == 0 || edad[i] > auxEdad)
        {
            auxEdad = edad[i];
            auxLegajo = legajo[i];
            auxSexo = sexo[i];
            flag = 1;
        }

        if(edad[i] == 41 && sexo[i] == 'F')
        {
            mujeres1978++;
        }

    }
    printf("EL promedio de las edades %d\n",suma/TAM);
    printf("Mayor edad, legajo: %d sexo %d\n",auxLegajo, auxSexo);
    printf("Mujeres que nacieron en el 78': %d\n", mujeres1978);



    return 0;
}

