#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "service.h"

static int isValidMensaje(char* mensaje);
static int isValidGravedad(int gravedad);

Service* service_new()
{
    return malloc(sizeof(Service));
}

Service* service_newParametros(int gravedad, char* mensaje)
{
    Service* this = service_new();
    if( this == NULL ||
        service_setGravedad(this, gravedad) ||
        service_setMensaje(this, mensaje))
    {
        service_delete(this);
        this = NULL;
    }
    return this;
}

void service_delete(Service* this)
{
    free(this);
}

int service_setGravedad(Service* this, int gravedad)
{
    int retorno = -1;
    if(this != NULL && isValidGravedad(gravedad))
    {
        this->gravedad = gravedad;
        retorno = 0;
    }
    return retorno;
}

int service_getGravedad(Service* this, int* gravedad)
{
    int retorno = -1;
    if(this != NULL && gravedad != NULL)
    {
        *gravedad = this->gravedad;
        retorno = 0;
    }
    return retorno;
}

static int isValidGravedad(int gravedad)
{
    return 1;
}

int service_compareGravedad(Service* thisA, Service* thisB)
{
    return thisA->gravedad > thisB->gravedad;
}

int service_setMensaje(Service* this, char* mensaje)
{
    int retorno = -1;
    if(this != NULL && isValidMensaje(mensaje))
    {
        strcpy(this->mensaje, mensaje);
        retorno = 0;
    }
    return retorno;
}
int service_getMensaje(Service* this, char* mensaje)
{
    int retorno = -1;
    if(this != NULL && mensaje != NULL)
    {
        strcpy(mensaje, this->mensaje);
        retorno = 0;
    }
    return retorno;
}

static int isValidMensaje(char* mensaje)
{
    return 1;
}

int service_compareMensaje(Service* thisA, Service* thisB)
{
    return strcmp(thisA->mensaje, thisB->mensaje);
}

void service_print(Service* this)
{
    printf("\n%d - %s - %d", this->gravedad, this->mensaje, this->serviceId);
}
