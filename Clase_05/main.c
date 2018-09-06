#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5

int mostrarArray(int* pArray[], int limite);

int main()
{

    int edades[CANTIDAD_EMPLEADOS];
    // salario -> devuelve la direccion de memoria del primer elemento array de salario => &salario[0]
    int i;

    for(i=0;i<CANTIDAD_EMPLEADOS;i++){
        if(utn_getEntero(&edades[i], 2, "\nEdad", "\nEdad fuera de rango", 0, 200 ) == -1)
        {
            edades[i] = -1;
        }
    }
    mostrarArray(edades, CANTIDAD_EMPLEADOS);

    mostrarArray(edades+2, CANTIDAD_EMPLEADOS-2);
    return 0;
}

int initArray(int* pArray, int limite, int valor)
{
    int retorno = -1;
    if(pArray != NULL && limite>0)
    {

        retorno = 0;
    }
    return retorno;
}


int mostrarArray(int* pArray[], int limite)
{
    int i;
    for(i=0; i< limite; i++){
        printf("\nIndex: %d] - Value:%d -Add: %p", i, pArray[i], pArray+i);
    }
    return 0;
}

/*int calcularMaximo(int* pArray[], int limite, ){
    int maximo;
}*/

