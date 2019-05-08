#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros = 0;

    for(int i = 0; i < 100 ; i++)
    {
        numeros++;

        if(numeros % 2 == 0)
        {
            printf("%d \n", numeros);
        }
    }

    return 0;
}
