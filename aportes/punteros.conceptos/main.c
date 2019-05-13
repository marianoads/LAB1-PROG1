#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*int* a;
   int b,c;

   b = 15;

   a = &b;

   c = *a; // a esta retorna el valor de la variable a la que esta apuntando

   printf("El valor de c es: %d", c);*/

  /* int* a;
   int* b;

   int c = 19;

   a = &c;

   b = a; // b recibe la direccion de memoria contenida en e a

   printf("la direccion del puntero b es %p\n", b);
   printf("la direccion del puntero a es %p\n\n", a);

   printf("el valor del puntero b es %d\n", *b);
   printf("el valor del puntero a es %d\n\n", *a);*/



   /* int* punteroA;
    int* punteroB;

    int auxiliarC, auxiliarD;

    punteroA = &auxiliarC;

    punteroB = &auxiliarD;

    printf("puntero A: %p , puntero B: %p\n\n", punteroA, punteroB);

    if(punteroA < punteroB)
        printf("el puntero A aunta a una direccion mas baja que el punteroB\n");
    else if(punteroA > punteroB)
        printf("el punteroB apunta a una direccion mas baja que el punteroA\n");*/


        /* aritmetica en punteros*/

    int* a;

    int varInt = 9;


    a = &varInt;
    printf("Dir memoria antes del incremento: %p\n", a);
        // incremento
    a++;
    printf("Dir memoria a despues del incremento: %p\n", a);


    // decremento

   /* a = a - (num * sizeof(int));
    b = b - (num * sizeof(float));
    c = c - (num * sizeof(char));*/


    printf("\n\n Vectores y punteros\n\n");

    int arrayInt[5] = { 1, 2 ,3, 4, 5};
    int* p1;
    int* p2;
    int* p3;

    p1 = &arrayInt[4];
    p2 = &arrayInt[0];
    p3 = arrayInt; // indexando un puntero con una array

    printf("Dir de memoria de p1: %p\n", p1);
    printf("Dir de memoria de p2: %p\n\n", p2);

    printf("Valor de indice 3 %d", p3[2] );

    // definir un array de variables de tipo puntero

    int var = 120;
    int* x[10];


    x[2] = &var; // asignar el valor al tercer elemento del arrat

    printf("\n\nel tercer elemento del array x: %d\n\n", *x[2]);

    int x3 = 1200;
    int* punteroInt;
    int** punteroPuntero;

    punteroInt = &x3;

    punteroPuntero = &punteroInt;

    printf("Accediendo al valor de x3 (forma habitual): %d\n", x3);
    printf("Accediendo al vslor de x3 (a traves de puntero) %d\n", *punteroInt);
    printf("Accediendo al valor de x3 (a traves del puntero puntero) %d\n", **punteroPuntero);


   return 0;
}
