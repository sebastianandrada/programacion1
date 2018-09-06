#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1

int mostrarArray(int* pArray[], int limite);

int main()
{

    int edades[CANTIDAD_EMPLEADOS];
    // salario -> devuelve la direccion de memoria del primer elemento array de salario => &salario[0]
    int i;
    int maximo;

    /*for(i=0;i<CANTIDAD_EMPLEADOS;i++){
        if(utn_getEntero(&edades[i], 2, "\nEdad", "\nEdad fuera de rango", 0, 200 ) == -1)
        {
            edades[i] = -1;
        }
    }*/
    //mostrarArray(edades, CANTIDAD_EMPLEADOS);

    //mostrarArray(edades+2, CANTIDAD_EMPLEADOS-2);

    //calcularMaximo(edades, CANTIDAD_EMPLEADOS, &maximo);

    initArray(edades, CANTIDAD_EMPLEADOS, 50);
    mostrarArray(edades, CANTIDAD_EMPLEADOS);

    //printf("\nMaximo: %d", maximo);

    return 0;
}

int initArray(int* pArray, int limite, int valor)
{
    int retorno = -1;
    if(pArray != NULL && limite>0)
    {
        int i;
        for(i=0; i<limite; i++)
        {
            pArray[i] = valor;
        }
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

int calcularMaximo(int* pArray[], int limite, int* pMaximo){
    int retorno;
    int i;
    int auxMaximo = pArray[0];
    int flagPrimerMaximo = false
    /*
    for(i=1; i< limite-1; i++)
    {
        if(pArray[i] > auxMaximo)
        {
            auxMaximo = pArray[i];
        }
    }*/
    for(i=0;i<limite;i++){
        if(pArray[i] != DATO_INVALIDO){
            if(flagPrimerMaximo == false)
            {
                auxMaximo = pArray[i];
            }
            else if(pArray[i]>auxMaximo){
                auxMaximo = pArray[i];
            }
        }
    }

    //*pMaximo = auxMaximo;
    return 0;
}

