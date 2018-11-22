#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Compra.h"

int parser_parseCompras(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    Compra *auxCompra;
    FILE *pFile;

    char* bufferName;
    char* bufferId;
    char* bufferPrecio;
    char* bufferUnidades;
    char* bufferIva;
    char* delim = " , ";
    char* delim2 = "\n";
    int valueFila;
    int contEntradas = 0;
    char line[1024];

    pFile = fopen(fileName, "r");
    if(pFile == NULL)
    {
        printf("El archivo no puede ser abierto");
        return retorno;
    }

    fscanf(pFile, "%[^\n]\n", line);
    while(!feof(pFile))
    {
        valueFila = fscanf(pFile, "%[^\n]\n", line);
        if(valueFila != 1)
        {
            break;
        }
        bufferName = strtok(line, delim);
        bufferId = strtok(NULL, delim);
        bufferPrecio = strtok(NULL, delim);
        bufferUnidades = strtok(NULL, delim);
        bufferIva = strtok(NULL, delim2);
        auxCompra = Compra_newConParametros(bufferName, bufferId, bufferPrecio, bufferUnidades, bufferIva, "0");
        if(auxCompra != NULL)
        {
            contEntradas++;
            ll_add(lista, auxCompra);
            retorno = 1;
        }
    }
    printf("Se cargaron %d compras. \n", contEntradas);

    fclose(pFile);    
    return 1; // OK
}

