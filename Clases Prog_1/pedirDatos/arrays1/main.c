#include <stdio.h>
#include <stdlib.h>


int pedirDato(int min, int max, int* valor, int intentos, char* mensaje, char* msjError);

int main()
{
    int x;
    int ok;

    ok = pedirDato(0, 10, &x, 3, "Ingrese nota", "Error. La nota debe estar ");

    if (ok == 1){

         printf("Usted ingreso el numero %d\n\n", x);

    }
    else{

        printf("No se pudo obtener el dato");
    }


    return 0;
}


int pedirDato(int min, int max, int* valor, int intentos,  char* mensaje, char* msjError){


int edad;
int todoOk = 0;
int cont = 0;

printf("%s entre %d y %d: ", mensaje,  min, max);
scanf("%d", &edad);

while( (edad < min || edad > max) && cont < intentos  ){

        cont++;

        if( cont == intentos){
            break;
        }
        printf("%s entre %d y %d: ", msjError, min, max);
        scanf("%d", &edad);
}

if(cont < intentos){

    *valor = edad;
     todoOk = 1;

}

return todoOk;

}
