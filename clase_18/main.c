#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define CLIENTES 100
/**
 estatico: Cuando el sistema se inicia se reserva memoria
 dinamico: Se asigna la memoria durante el programa
*/
/*
int function(void)
{
    return 7;
}

void funcionRecibeF(int (*pepe)(void))
{
    printf("puntero desde funcion: %p\n", pepe);
    printf("Devolvio: %d\n", pepe());
}*/

int main()
{
    /*printf("%p\n", function);
    funcionRecibeF(function);*/
    Cliente* aux;
    Cliente* arrayClientes[CLIENTES];

    cliente_inicializarArray(arrayClientes, CLIENTES);


    //ALTA
    int indexVacio;
    aux = cliente_new();
    indexVacio = cliente_buscarLugarVacio(arrayClientes, CLIENTES);
    if(aux != NULL && indexVacio >= 0)
    {
        cliente_setNombre(aux, "Juan");
        arrayClientes[indexVacio] = aux;
    }

    return 0;
}
