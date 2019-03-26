#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros = 100;

    for(int i = 0; i < 101; i++)
    {
        printf("%d \n", numeros);
        numeros--;
    }
    return 0;
}
