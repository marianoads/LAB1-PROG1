#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numero1;
    int suma = 0;
    int cont = 0;


    printf("Digite un numero \n");
    scanf("%d",&numero);

    numero1 = numero;


    while(cont < numero)
    {
        numero1--;
        suma = suma + numero1;

        cont++;
    }


    printf("la suma es: %d", suma);

    return 0;
}
