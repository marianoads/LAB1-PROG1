#include <stdio.h>
#include <stdlib.h>

//void muestra(int *x, int y);

int main()
{
    /*int x ,y;

    printf("Ingrese \n");
    scanf("%d", &x);

    printf("Ingrese \n");
    scanf("%d", &y);

    muestra(&x, y);

    printf("x : %d , Y: %d",x , y);*/

     int nro;
     int *n; // declarando un puntero

     nro = 3;
     n = &nro;

     printf("%d \n",nro);
     printf("%p \n", n);
     printf("%d \n", *n);


    return 0;
}

/*void muestra(int *x , int y)
{
    *x = y;
    printf("x %d Y %d \n", x ,y);

}*/
