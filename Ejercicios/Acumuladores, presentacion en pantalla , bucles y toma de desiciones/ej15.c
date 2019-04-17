#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros = 0;

    for(int i = 0; i < 101 ; i++)
    {
        if(numeros % 6 == 0)
        {
          printf("%d \n", numeros);
        }

        numeros++;
    }
}
