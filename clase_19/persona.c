
#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidId(char* id);
static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);

Persona* persona_new()
{
    Persona* this;
    this=malloc(sizeof(Persona));
    return this;
}

void persona_delete(Persona* this)
{
    free(this);
}

Persona* persona_newConParametros(char* id,char* nombre,char* apellido)
{
    Persona* this;
    this=persona_new();

    if(
    !persona_setId(this,id)&&
    !persona_setNombre(this,nombre)&&
    !persona_setApellido(this,apellido))
        return this;

    persona_delete(this);
    return NULL;
}

int persona_setId(Persona* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && isValidId(id))
    {
        strcpy(this->id,id);
        retorno=0;
    }
    return retorno;
}

static int isValidId(char* id)
{
    return 1;
}

int persona_getId(Persona* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        strcpy(id,this->id);
        retorno=0;
    }
    return retorno;
}

int persona_setNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

int persona_getNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int persona_setApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

int persona_getApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

