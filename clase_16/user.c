#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

static int isValidName(char* name);
static int isValidEmail(char* email);

User* user_new()
{
    return malloc(sizeof(User));
}

User* user_newParametros(char* name, char* email)
{
    User* this = user_new();
    if( this == NULL ||
        user_setName(this, name) ||
        user_setEmail(this, email))
    {
        user_delete(this);
        this = NULL;
    }
    return this;
}

void user_delete(User* this)
{
    free(this);
}

int user_setName(User* this, char* name)
{
    int retorno = -1;
    if(this != NULL && isValidName(name))
    {
        strcpy(this->name, name);
        retorno = 0;
    }
    return retorno;
}

int user_getName(User* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        strcpy(name, this->name);
        retorno = 0;
    }
    return retorno;
}

static int isValidName(char* name)
{
    return 1;
}

int user_setEmail(User* this, char* email)
{
    int retorno = -1;
    if(this != NULL && isValidEmail(email))
    {
        strcpy(this->email, email);
        retorno = 0;
    }
    return retorno;
}

int user_getEmail(User* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        strcpy(email, this->email);
        retorno = 0;
    }
    return retorno;
}

static int isValidEmail(char* email)
{
    return 1;
}

void user_print(User* this)
{
    printf("\n%s - %s - %d", this->name, this->email, this->userId);
}
