#include <stdio.h>
#include <stdlib.h>

int sumar(int x , int y); //prototipo

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero \n");
    scanf("%d",&num1);

    printf("Ingrese otro numero \n");
    scanf("%d", &num2);

    resultado = sumar(num1 , num2); //llamada. ..

    printf("La suma es %d \n", resultado);
    return 0;
}

int sumar(int num1, int num2)
{
    int suma;     /*desarrollo*/
    suma = num1 + num2;
    return suma;
}

/*int sumar2(int x, int y)
{
    int suma;     /*desarrollo
    suma = x + y;
    return suma;
}*/