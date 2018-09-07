#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //void fun(int pA[], int i)
    //void fun(int* pA[], int i)
    //aux = pA[] === aux = *(pA+1)

    int edad;
    //if(getEdad(&edad) == 0)
    if(utn_getEntero(&edad,3,"edad?:","error",0,199) == 0)
    {
        printf("La edad es: %d",edad);
    }



    return 0;
}
