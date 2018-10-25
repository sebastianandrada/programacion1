#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
//chmod -w archivo
//rwx x-> ejecutable
int main()
{
    /*char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    FILE *pArchivo;*/
    /*pArchivo = fopen("archivo.txt", "w");
    if(pArchivo != NULL)
    {
        //stdout -> lo escribe en la consola
        fprintf(pArchivo,"%d, %s, %s\n", id, nombre, apellido);
        fprintf(pArchivo,"%d, %s, %s\n", id+1, nombre, apellido);
        fprintf(pArchivo,"%d, %s, %s\n", id+2, nombre, apellido);
        fclose(pArchivo);
    }
    else {
        printf("El archivo no existe");
    }*/
/*
    pArchivo = fopen("archivo.txt", "r");
    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            strcpy(bufferApellido, "-------*-------");
            fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido);
            printf("%s - %s - %s\n", bufferId, bufferNombre, bufferApellido);
        }
        fclose(pArchivo);
    }
    else {
        printf("El archivo no existe");
    }*/

    FILE* pArchivoPersonas;
    pArchivoPersonas = fopen("personas.txt", "w");

    Persona* arrayPersonas[10];
    int i;
    int qtyEmpleados = 0;
    char auxId[100];
    Persona* auxPersona;
    auxPersona = persona_newConParametros("1", "PEdro", "Perez");
    for(i=0;i<10;i++)
    {
        sprintf(auxId, "%d", i);
        arrayPersonas[i] = persona_newConParametros(auxId, "Juan", "Gomez");
        qtyEmpleados++;
    }
    printf("cantiad emp %d", qtyEmpleados);
    if(pArchivoPersonas != NULL)
    {
        for(i=0;i<qtyEmpleados;i++)
        {
            //fprintf(pArchivoPersonas, "%s", arrayPersonas[i]->apellido);
            //fclose(pArchivoPersonas);
            grabarPersona(pArchivoPersonas, arrayPersonas[i]->apellido);
        }
        //fprintf(pArchivoPersonas, "%s", auxPersona->apellido);
        fclose(pArchivoPersonas);
    }
    else {
        printf("El archivo no existe");
    }

    return 0;
}

void grabarPersona(FILE* file, char* text)
{
    fprintf(file, "%s", text);

}
