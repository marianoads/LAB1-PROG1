#include <stdio.h>
#include <stdlib.h>

int x = 30;

void f1(int *num);

int main()
{
    //printf("%d \n", x);
    int x = 20;

    f1(&x);

    printf("%d \n", x);


    return 0;
}

void f1(int* num)
{
    *num = 30;

}
