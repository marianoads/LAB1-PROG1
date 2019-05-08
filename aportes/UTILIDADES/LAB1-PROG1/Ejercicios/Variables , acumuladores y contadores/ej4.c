#include <stdio.h>
#include <stdlib.h>


int main()
{
    float nro1;
    float nro2;
    float resta;

    printf("Digite un numero: \n");
    scanf("%f", &nro1);
    printf("Digite un numero:\n");
    scanf("%f", &nro2);

    resta = nro1 - nro2;

    if(resta < 0)
    {
        printf("resultado negativo \n");

    }
    else if(resta > 0)
    {
        printf("resultado positivo \n");
    }
    else
    {
        printf("resultado cero \n");

    }



    return 0;
}
