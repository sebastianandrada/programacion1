#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int isFloat(char* pBuffer)
{
    return 1;
}

static int getInt(int* pResultado);
static int esNumero(char* pCadena);
static int getString();

int funcion(void)
{
    static int i=9;

    i++;
    return i;
}



int utn_getEntero(int* pEdad,int reintentos,char* msg,
                  char*msgErr,int min, int max)
{



    int retorno = -1;
    int auxiliarEdad;

    for(; reintentos > 0; reintentos--)
    {
        printf(msg);

        //if(scanf("%d",&auxiliarEdad) == 1)
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}


static int getInt(int* pResultado)
{
    char cadena[64];
    scanf("%s", cadena);
    int aux;
    int ret = -1;
    if(esNumero(cadena) == 0)
    {
        aux = atoi(cadena);
        *pResultado = aux;
        ret = 0;
    }
    return ret;
}

static int esNumero(char* pCadena)
{
    int i=0;
    char aux;
    int retorno = 0;

    aux = pCadena[i];
    while(aux != 0){
        if(aux < 48 || aux > 57)
        {
            retorno = -1;
            break;
        }
        i++;
        aux = pCadena[i];
    }
    return retorno;


        /*for(i=0; i<strlen(pCadena); i++)
    {
        aux = pCadena[i];
        if(aux < 48 || aux > 57)
        {
            retorno = -1;
        }

    }*/

}

static int getFloat(float* pBuffer)
{
    char bufferString[5];
    int retorno = -1;

    if(getString(bufferString) == 0 && isFloat(bufferString))
    {
        *pBuffer = atof(bufferString);
        retorno = 0;
    }
    return retorno;
}

static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    /*if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferString, sizeof(bufferString), stdin);
        if(bufferString[strlen(bufferString)-1] == '\n')
        {
            bufferString[strlen(bufferString)-1] = '\0';
        }
        if(strlen(b) <= limite)
        {
            strncpy(pBuffer, bufferString, limite)
            retorno = 0;
        }

    }*/

    return retorno;
}

int utn_getFloat(float* pFloat, char* msg, char msgErr[], float min, float max, int reintentos)
{
    int retorno = -1;
    float buffer;
    if(pFloat != NULL && msg != NULL && msgErr != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", msg);
            if(getFloat(&buffer) == 0 && buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pFloat = buffer;
                break;
            }
            else
            {
                printf("%s", msgErr);
            }
        }while(reintentos >= 0);

    }
    return retorno;

}

int utn_getNombre(char* pNombre, char* msg, char msgErr[])
{
    //int retorno = -1;
    char buffer[4096];
//    getString(buffer);
    return 0;
    //return retorno;
}
