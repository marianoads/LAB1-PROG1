#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //int i;

    //i = 0;

    /*while(i < 10)
    {
      i++;
      printf("%d \n",i);
    }*/


    /*do
    {
        i++;
        printf("%d \n",i);
    }
    while(i < 10);*/


    /*for(i=0; i<10 ; i++)
    {
        printf("%d \n",(i+1));
    }*/



    /*EN C SWITCH NO TOMA EL UNA CADENA DE CARACTERES*/


    //int valor;

    //printf("Hora: ");
    //scanf("%d",&valor);

    /*switch(valor)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("A dormir");
        break;

        case 7:
        case 8:
        case 9:
            printf("Buenos Dias");
        break;

        default:
            if(valor >= 10 && valor <= 23)
            {
                printf("Es de noche");
            }
            else
            {
                printf("Hora invalida");
            }
        break;

    }*/

    /*char hora;
    printf("Hora: ");
    fflush(stdin);
    scanf("%c",&hora);


    switch(hora)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            printf("A dormir");
        break;

        case '7':
        case '8':
            printf("Buenos Dias");
        break;

        default:
            if(hora >= '9' && hora <= '23')
            {
                printf("Es de noche");
            }
            else
            {
                printf("Hora invalida");
            }
        break;


    }*/

    /*int valor, min,max,flag = 0;

    char rta;


        do{
        printf("ingrese un valor \n");
        scanf("%d", &valor);

        if(flag == 0 || valor )
        {
          max = valor;
        }

        if(flag == 0 || valor < min)
        {
            min = valor;
            flag = 1;
        }

        printf('s/n');
        fflush(stdin);
        scanf("%c", &rta);
        rta = toupper(rta);
        while(rta != 'S' && rta != 'N');

        }while(rta == 'S');
*/

    /*float resultado;
    int n1,n2;
    n1 = 5;
    n2 = 2;


    resultado = (float)n1/n2;
    printf("numero: %.1f", resultado);*/



    return 0; //el 0 significa finalización fué exitosa en una función

}
