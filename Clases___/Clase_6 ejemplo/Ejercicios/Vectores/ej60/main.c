#include <stdio.h>
#include <stdlib.h>

#define TAM_VEC 20

int main()
{
    int vec[20] = {1,6,8,3,7,9,11,565,562,334,211,34,678,57,577,32,463,3,45,111};
    int aux;

    for(int i = 0; i < TAM_VEC; i++){

        printf("%d\n", vec[i]);

    }

    for(int i = 0; i < TAM_VEC-1; i++)
    {
        for(int j = i+1 ; j < TAM_VEC; j++)
        {
            if(vec[i]  < vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

        printf("\n\n vector ordenado \n\n");
    for(int i = 0; i < TAM_VEC; i++){
        printf("%d\n", vec[i]);

    }
    return 0;
}
