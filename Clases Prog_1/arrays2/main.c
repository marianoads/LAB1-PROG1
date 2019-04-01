#include <stdio.h>
#include <stdlib.h>

int buscarChar( char caracter, char vec[], int tam);

int main()
{
    char x[5]= { 'a', 'e', 'i', 'o', 'u'};


    int esta;

    esta = buscarChar('a', x, 5);

    if( esta == -1){
        printf("No esta\n");
    }
    else{
        printf("El caracter esta en el indice %d\n", esta);

    }





    return 0;
}


 int buscarChar( char caracter,  char vec[], int tam){

 int indice = -1;

 for(int i=0; i < tam; i++){


    if( caracter == vec[i]){
        indice = i;
        break;
    }

 }


 return indice;

 }
