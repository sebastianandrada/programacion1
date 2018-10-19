#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

static int isValidNombre(char* nom);

Cliente* cliente_new(void)
{
    return (Cliente*)malloc(sizeof(Cliente));
}

int cliente_setNombre(Cliente* this, char* nom)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nom))
    {
        strncpy(this->nombre, nom, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nom)
{
    return 1;
}

int cliente_getNombre(Cliente* this, char* nom)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nom, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cliente_buscarLugarVacio(Cliente** array, int len)
{
    int i;
    int ret = -1;
    if(array != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(array[i] == NULL)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int cliente_inicializarArray(Cliente** array, int len)
{
    int i;
    int ret = -1;
    for(i=0;i<len;i++)
    {
        array[i] = NULL;
        ret = 0;
    }
    return ret;
}

int cliente_buscarPorId(Cliente** array, int len, int idCliente)
{
    int ret = -1;
    int i;
    for(i=0;i<len; i++)
    {
        if( array[i] != NULL && array[i]->id == idCliente)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int cliente_deleteCliente(Cliente* this)
{
    int ret = -1;
    if(this != NULL)
    {
        free((void*)this);
        ret = 0;
    }
    return ret;
}


