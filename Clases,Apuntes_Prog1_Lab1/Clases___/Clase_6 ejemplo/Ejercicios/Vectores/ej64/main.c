#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[20];
    int aux;


    for(int i = 0; i < 20 ; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&numeros[i]);

        while(numeros[i] == 0)
        {
            printf("ERROR: Ingrese un numero distinto de cero\n");
            scanf("%d",&numeros[i]);
        }

    }

    system("cls");

    /*printf("Vector SIN ORDENAR\n\n");
    for(int i = 0; i < 20 ; i++)
    {
        printf("%d\n",numeros[i]);
    }*/

    for(int i = 0 ; i < 19 ; i++)
    {
       for(int j = i+1 ; j < 20 ; j++)
       {
           if(numeros[i] > 0)
           {
               if(numeros[i] < numeros[j])
               {
                       aux = numeros[i];
                       numeros[i] = numeros[j];
                       numeros[j] = aux;
               }

           }
       }
    }

    for(int i = 0 ; i < 19 ; i++)
    {
       for(int j = i+1 ; j < 20 ; j++)
       {
           if(numeros[i] < 0)
           {
               if(numeros[i] < numeros[j])
               {
                       aux = numeros[i];
                       numeros[i] = numeros[j];
                       numeros[j] = aux;
               }

           }
       }
    }
    for(int i = 0; i < 20 ; i++)
    {
        printf("%d\n",numeros[i]);
    }





    return 0;
}
