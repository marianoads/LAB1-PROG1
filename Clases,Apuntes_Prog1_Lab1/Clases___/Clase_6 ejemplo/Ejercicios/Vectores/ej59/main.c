#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[20] = {1, 50,2 ,3 ,4, 5, 6 ,7 , 8, 9 ,10 ,11 ,12 ,13 , 14 ,15 ,16 ,17 ,18 , 20}; //hard coding
    int mayor;
    int flag = 0;

    for(int i = 0; i < 20 ; i++)
    {
        printf("%d en el indice %i\n", vec[i], i);

        if(flag == 0 || vec[i]> mayor)
        {
            mayor = vec[i];
            flag = 1;
        }


    }


    printf("el mayor es : %d \n",mayor);
    return 0;
}
