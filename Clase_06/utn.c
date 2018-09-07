#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int getInt(int* pResultado);
static int esNumero(char* pCadena);


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
