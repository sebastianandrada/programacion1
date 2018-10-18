#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidAltura(float altura);

Empleado* empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* empleado_newParametros(char* nombre, char* apellido, float altura)
{
    Empleado* this = empleado_new();
    if( this == NULL ||
        empleado_setNombre(this, nombre) ||
        empleado_setApellido(this, apellido) ||
        empleado_setAltura(this, altura))
    {
        empleado_delete(this);
        this = NULL;
    }

    return this;
}

void empleado_delete(Empleado* this)
{
    free(this);
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

int empleado_compareNombre(void* thisA, void* thisB)
{
    Empleado* A = thisA;
    Empleado* B = thisB;
    return strcmp(A->nombre, B->nombre);
}

int empleado_setApellido(Empleado* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}
int empleado_getApellido(Empleado* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

int empleado_setAltura(Empleado* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}
int empleado_getAltura(Empleado* this, float* altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        *altura = this->altura;
        retorno = 0;
    }
    return retorno;
}

static int isValidAltura(float altura)
{
    return 1;
}

void empleado_print(Empleado* this)
{
    printf("\n%s - %s - %.2f - %d", this->nombre, this->apellido, this->altura, this->idEmpleado);
}
