#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    int valor;

    valor = verifica();

    system("cls");

    if(valor == 1){
        printf("Selecciono 'S'");
    }
    else{
        printf("Selecciono 'N'");
    }

    return 0;
}
