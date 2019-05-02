#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    printf("%s",message);
    scanf("%d", input);

    while(*input < lowLimit || *input > hiLimit){
        printf("%s", eMessage);
        scanf("%d", input);

    }


    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    printf("%s",message);
    scanf("%f", input);

    while(*input < lowLimit || *input > hiLimit){
        printf("%s",eMessage);
        scanf("%f", input);
    }
    return 0;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    fflush(stdin);
    printf("%s", message);
    scanf("%c", input);

    fflush(stdin);
    *input = tolower(*input);

    while(!(*input == lowLimit || *input == hiLimit)){
        printf("%s", eMessage);
        scanf(" %c", input);

    }
    return 0;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

   printf("%s",message);
   fgets(input, 53, stdin);
   input[strlen(input)-1] = '\0';

   while(strlen(input) < lowLimit || strlen(input) > hiLimit){
           printf("%s ",eMessage);
           fgets(input, 53, stdin);
           input[strlen(input)-1] = '\0';

   }



    return 0;
}
