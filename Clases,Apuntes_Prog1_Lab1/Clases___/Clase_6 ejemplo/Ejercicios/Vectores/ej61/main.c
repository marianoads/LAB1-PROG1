#include <stdio.h>
#include <stdlib.h>

int main()
{
    int gastos[30];
    int flag = 0;
    int diaMayorGasto;
    int aux;

    for(int i = 0 ; i < 30 ; i++)
     gastos[i] = 0;

    for(int i = 0 ; i < 30 ; i++)
    {
        printf("Ingrese el gasto del dia %d ",i+1);
        scanf("%d",&gastos[i]);

        if(flag == 0 || aux < gastos[i] )
        {
            aux = gastos[i];
            diaMayorGasto = i+1;
            flag = 1;
        }


    }

    system("cls");
    printf("el dia de mayor gasto es el dia %d",diaMayorGasto);

    return 0;
}
