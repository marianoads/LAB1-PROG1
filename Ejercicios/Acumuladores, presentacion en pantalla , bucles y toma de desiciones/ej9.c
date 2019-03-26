#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char letra;
    int contA = 0;
    int contE = 0;
    int contI = 0;
    int contO = 0;
    int contU = 0;

    for(int i = 0; i < 20; i++)
    {
        printf("Ingresa un caracter \n");
        //fflush(stdin);
        scanf(" %c", &letra);
        letra = tolower(letra);

        switch(letra)
        {
        case 'a':
            contA++;
        break;

        case 'e':
            contE++;
        break;

        case 'i':
            contI++;
        break;

        case 'o':
            contO++;
        break;

        case 'u':
            contU++;
        break;

        }


    }

        printf("Se ingresaron %d letras A \n", contA);
        printf("Se ingresaron %d letras E \n", contE);
        printf("Se ingresaron %d letras I \n", contI);
        printf("Se ingresaron %d letras O \n", contO);
        printf("Se ingresaron %d letras U \n", contU);

    return 0;
}
