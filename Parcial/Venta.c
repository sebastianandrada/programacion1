
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 Venta* Venta_new()
{
     Venta* this;
    this=malloc(sizeof( Venta));
    return this;
}

void Venta_delete( Venta* this)
{
    free(this);
}

 Venta* Venta_newConParametros(char* strid,char* fechaVenta,char* codigo,char* strcantidad,char* strprecioUnitario,char* cuit)
{
     Venta* this;
    this=Venta_new();

    if(
    !Venta_setId(this,atoi(strid))&&
    !Venta_setFechaVenta(this,fechaVenta)&&
    !Venta_setCodigo(this,codigo)&&
    !Venta_setCantidad(this,atoi(strcantidad))&&
    !Venta_setPrecioUnitario(this, atof(strprecioUnitario))&&
    !Venta_setCuit(this,cuit))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setId( Venta* this,int id)
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

int Venta_getId( Venta* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaVenta( Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaVenta( Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigo( Venta* this,char* codigo)
{
    int retorno=-1;
    if(this!=NULL && codigo!=NULL)
    {
        strcpy(this->codigo,codigo);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigo( Venta* this,char* codigo)
{
    int retorno=-1;
    if(this!=NULL && codigo!=NULL)
    {
        strcpy(codigo,this->codigo);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad( Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad( Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnitario( Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnitario( Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuit( Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuit( Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

int venta_printVenta(void* p)
{
    int retorno = -1;
    int auxId;
    char auxFecha[128];
    char auxCodigo[128];
    int auxCantidad;
    float auxPrecio;
    char auxCuit[128];
    if(p != NULL)
    {
        Venta* auxVenta = (Venta*)p;
        Venta_getId(auxVenta, &auxId);
        Venta_getFechaVenta(auxVenta, auxFecha);
        Venta_getCodigo(auxVenta, auxCodigo);
        Venta_getCantidad(auxVenta, &auxCantidad);
        Venta_getPrecioUnitario(auxVenta, &auxPrecio);
        Venta_getCuit(auxVenta, auxCuit);
        printf("%d - %s - %s - %d - %f - %s\n", auxId, auxFecha, auxCodigo, auxCantidad, auxPrecio, auxCuit);
        retorno = 1;
    }
    return retorno;
}

int venta_totalesVendidas(void* p)
{
    int retorno = -1;
    int auxCantidad;
    Venta* auxVenta = (Venta*)p;
    if(p != NULL)
    {
        Venta_getCantidad(auxVenta, &auxCantidad);
        retorno = auxCantidad;
    }

    return retorno;
}

int venta_ventasMayorA10000(void* p)
{
    int retorno = 0;
    Venta* auxVenta = (Venta*)p;
    float auxPrecioU;
    float auxMontoTotal;
    int auxCantidad;
    if(p != NULL)
    {
        Venta_getPrecioUnitario(auxVenta, &auxPrecioU);
        Venta_getCantidad(auxVenta, &auxCantidad);
        auxMontoTotal = auxPrecioU * auxCantidad;

        retorno = auxMontoTotal > 10000;
    }
    return retorno;
}

int venta_ventasMayorA20000(void* p)
{
    Venta* auxVenta = (Venta*)p;
    float auxPrecioU;
    float auxMontoTotal;
    int auxCantidad;
    Venta_getPrecioUnitario(auxVenta, &auxPrecioU);
    Venta_getCantidad(auxVenta, &auxCantidad);
    auxMontoTotal = auxPrecioU * auxCantidad;

    return auxMontoTotal > 20000;
}

int venta_ventasTvLCDs(void* p)
{
    int retorno = -1;
    Venta* auxVenta = (Venta*)p;
    char auxCodigo[128];
    Venta_getCodigo(auxVenta, auxCodigo);
    int auxCant;

    if(strcmp(auxCodigo, "LCD_TV") == 0)
    {
        Venta_getCantidad(auxVenta, &auxCant);
        retorno = auxCant;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
