#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia;
    int mes;
    int anio;


}eFecha;

typedef struct{

    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;


}eEmpleado;

int main(){

    eEmpleado unEmpleado = {1234, "Juan", 'm', 3000,{01, 02 , 2015}};
    eEmpleado otroEmpleado = {2222, "Ana", 'f', 2000,{20, 02 , 2017}};


    //eEmpleado *punteroEmpleado;

    eEmpleado lista[] ={unEmpleado, otroEmpleado};

   // punteroEmpleado = &unEmpleado;

    /* cuando se tiene  el puntero de una estructura para acceder a los campos se usa la flecha ->*/

   // printf("anio; %d", punteroEmpleado->fechaIngreso.anio); // fecha ingreso no es una direccion de memoria por lo tanto se accede a sus campos mediante punto

  //  printf("\nnombre: %s\n", (*punteroEmpleado).nombre); // asi tambien se puede acceder a um campo de la estructura

  for( int i = 0 ; i < 2; i++){


    printf("%s\n", (lista + i)->nombre);
  }

    return 0;
}
