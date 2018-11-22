#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,atoi(idStr))&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,atoi(horasTrabajadasStr))&&
    !Empleado_setSueldo(this,atoi(sueldoStr)))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int em_calcularSueldo(void* p)
{
    /** Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/
    //int n,s;
    //int i,j = n, s = 1;
    int retorno;
    Empleado* auxEmpleado;
    auxEmpleado = (Empleado*)p;
    int horasTrabajadas;
    int sueldo;
    Empleado_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
    if(horasTrabajadas < 121)
    {
        sueldo = horasTrabajadas * 180;
        retorno = 1;
    } else if(horasTrabajadas > 120 && horasTrabajadas < 161)
    {
        sueldo = horasTrabajadas *240;
        retorno = 1;
    } else if(horasTrabajadas > 160 && horasTrabajadas < 241)
    {
        sueldo = horasTrabajadas * 350;
        retorno = 1;
    }
    Empleado_setSueldo(auxEmpleado, sueldo);
    return retorno;
}

int em_printEmpleado(void* p)
{
    int retorno = -1;
    Empleado* auxEmpleado;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[128];
    auxEmpleado = (Empleado*) p;

    if(p != NULL)
    {
        Empleado_getId(auxEmpleado, &auxId);
        Empleado_getNombre(auxEmpleado, auxNombre);
        Empleado_getHorasTrabajadas(auxEmpleado, &auxHoras);
        Empleado_getSueldo(auxEmpleado, &auxSueldo);
        printf("%d - %s - %d - %d\n", auxId, auxNombre, auxHoras, auxSueldo);
        retorno = 1;
    }
    return retorno;
}