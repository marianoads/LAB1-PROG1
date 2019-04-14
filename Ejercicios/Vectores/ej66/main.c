#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int obtenerNumero(void);

int main()
{
    int edad[TAM];
    char sexo[TAM];
    int legajo[TAM];

    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese edad: \n");
        edad[i] = obtenerNumero();

    }
    return 0;
}

int obtenerNumero(void)
{
        int input, temp, status;                            // input	user input -- hopefully a number
                                                        // temp		used to collect garbage characters
                                                        // status	did the user enter a number?

    printf("Ingrese un numero: ");
    status = scanf("%d", &input);

    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Numero invalido ingrese un numero: ");
        status = scanf("%d", &input);
    }

    return input;
}
