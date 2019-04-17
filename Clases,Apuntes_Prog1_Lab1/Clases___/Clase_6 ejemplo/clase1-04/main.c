#include <stdio.h>
#include <stdlib.h>

int pedirDatos(int min , int max, int* valor );

int main()
{
    int x;

    pedirDatos(8 , 10 ,&x);

    printf("usted ingreso el numero %d", &x);

    return 0;



}

int pedirDatos(int min , int max, int* valor )
{
    int edad;
    int todoOK = 0;

    printf("Ingrese una edad entre %d y %d: ",min,max);
    scanf("%d", &edad);

    while(edad < min || edad > max)
    {
        printf("Error ingrese una edad entre %d y %d: ",min, max);
        scanf("%d ",&edad);
    }

    todoOK = 1;

    return ;
}
