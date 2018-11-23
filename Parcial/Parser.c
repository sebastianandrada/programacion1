#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include <string.h>

int parser_parseVentas(char *fileName, LinkedList *listaVentas)
{
    int retorno = -1;
    Venta *auxVenta;
    FILE *pFile;

    char* bufferId;
    char* bufferFecha;
    char* bufferCodigo;
    char* bufferCantidad;
    char* bufferPrecio;
    char* bufferCuit;
    char* delim = " , ";
    char* delim2 = "\n";
    int valueFila;
    int contadorEntradas = 0;
    char line[1024];

    pFile = fopen(fileName, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        return -1;
    }

    fscanf(pFile, "%[^\n]\n", line);
    while(!feof(pFile))
    {
        valueFila = fscanf(pFile, "%[^\n]\n",line);
        if(valueFila != 1)
        {
            break;
        }
        bufferId = strtok(line, delim);
        bufferFecha = strtok(NULL, delim);
        bufferCodigo = strtok(NULL, delim);
        bufferCantidad = strtok(NULL, delim);
        bufferPrecio = strtok(NULL, delim);
        bufferCuit = strtok(NULL, delim2);
        auxVenta = Venta_newConParametros(bufferId, bufferFecha, bufferCodigo, bufferCantidad, bufferPrecio, bufferCuit);
        if(auxVenta != NULL)
        {
            contadorEntradas++;
            ll_add(listaVentas, auxVenta);
            retorno = 1;
        }
    }
    printf("Se cargaron %d ventas. \n", contadorEntradas);

    fclose(pFile);
    return retorno; // OK
}
