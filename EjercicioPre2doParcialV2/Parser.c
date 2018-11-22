#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char *fileName, LinkedList *listaEmpleados)
{
    int retorno = -1;
    Empleado *auxEmpleado;
    FILE *pFile;

    char *bufferId;
    char *bufferName;
    char *bufferHorasTrabajadas;
    char* delim = " , ";
    char* delim2 = "\n";
    int valueF;
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
        valueF = fscanf(pFile, "%[^\n]\n",line);
        if(valueF != 1)
        {
            break;
        }
        bufferId = strtok(line, delim);
        bufferName = strtok(NULL, delim);
        bufferHorasTrabajadas = strtok(NULL, delim2);
        auxEmpleado = Empleado_newConParametros(bufferId, bufferName, bufferHorasTrabajadas, "0");
        if(auxEmpleado != NULL)
        {
            contadorEntradas++;
            ll_add(listaEmpleados, auxEmpleado);
            retorno = 1;
        }
    }
    printf("Se cargaron %d empleados. \n", contadorEntradas);

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