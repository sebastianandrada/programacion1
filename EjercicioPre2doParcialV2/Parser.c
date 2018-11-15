#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char *fileName, LinkedList *listaEmpleados)
{
    int flagOnce = 1;
    int retorno = -1;
    Empleado *auxEmpleado;
    char *bufferStr;
    FILE* pFile;

    char* bufferId;
    char* bufferName;
    char* bufferHorasTrabajadas;

    pFile = fopen(fileName, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        return -1;
    }
    else
    {
        while (!feof(pFile))
        {
            if (flagOnce)
            {
                fscanf(pFile, "%s\n", bufferId);
                flagOnce = 0;
            }
            if (fscanf(pFile, "%[^,],%[^,],%[^\n]\n",
                       bufferId,
                       bufferName,
                       bufferHorasTrabajadas) == 3)
            {
                auxEmpleado = Empleado_newConParametros(
                    bufferId,
                    bufferName,
                    bufferHorasTrabajadas,
                    "0");

                if (auxEmpleado != NULL)
                {
                    ll_add(listaEmpleados, auxEmpleado);
                    retorno = 0;
                }
            }
        }
    }

    fclose(pFile);

    return retorno; // OK
}

/* {
        //bufferStr = 
        bufferStr = fgets(bufferStr, 128, pFile);
        while(bufferStr != NULL)
        {
            
        }
    }
 */