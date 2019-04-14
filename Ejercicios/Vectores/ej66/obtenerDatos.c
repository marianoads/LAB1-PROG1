#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int obtenerNumero(void)
{
        int input, temp, status;                            // input	user input -- hopefully a number
                                                        // temp		used to collect garbage characters
                                                        // status	did the user enter a number?
    status = scanf("%d", &input);

    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Numero invalido ingrese un numero: ");
        status = scanf("%d", &input);
    }

    return input;
}

char obtenerSexo(void)
{
    char sexo;
    int status;

    /*setbuf(stdin, NULL);
    sexo = getchar();
    sexo = toupper(sexo);*/

    setbuf(stdin, NULL);

    status = scanf("%c", &sexo);

    if(sexo == 'f' || sexo == 'm')
    sexo = toupper(sexo);

    while(status != 1 || !(sexo == 'F' || sexo == 'M'))
    {
        setbuf(stdin, NULL);
        printf("Error sexo no valido ingrese un sexo [F]/[M]?\n");
        status = scanf("%c", &sexo);
       /* sexo = getchar();
        sexo = toupper(sexo);*/
        if(sexo == 'f' || sexo == 'm')
        sexo = toupper(sexo);
        setbuf(stdin, NULL);
    }


    return sexo;
}
