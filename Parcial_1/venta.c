#include <stdio.h>
#include "venta.h"
#include "utn.h"
#include <string.h>

static int generarID(void);
static int getIndiceVacioVentas(Venta* ventas,int len);


int initVentas(Venta* ventas, int len, int valor)
{
    int i;
    int retorno = -1;
    if(len > 0)
    {
        for(i=0; i<len; i++)
        {
            ventas[i].aCobrar = valor;
            retorno = 0;
        }
    }
    return retorno;
}

int altaVenta(Venta* ventas, int len)
{
    int retorno = -1;
    int auxCantidadAfiches;
    int auxIdCliente;
    int auxZona;
    char auxNombreArchivo[128];

    int index = getIndiceVacioVentas(ventas, len);
    if(utn_getInt(&auxIdCliente, 5, "Ingrese id del cliente", "Id invalido", 0, 100) == 0)
    {
        if (len >= 0 && utn_getInt(&auxCantidadAfiches, 5, "Ingrese cantidad de afiches: \n", "Dato invalido\n", 1, 100000) == 0)
        {
            if (utn_getString(auxNombreArchivo, 5, "Ingrese nombre del archivo: \n", "Dato invalido\n", 128) == 0)
            {
                if (utn_getInt(&auxZona, 5, "Ingrese la zona (1-CABA, 2-ZONA SUR, 3-ZONA OESTE)\n", "Dato invalido\n", 0, 4) == 0)
                {
                    ventas[index].idCliente = auxIdCliente;
                    ventas[index].id = generarID();
                    ventas[index].aCobrar = 1;
                    ventas[index].zona = auxZona;
                    strncpy(ventas[index].nombreArchivo, auxNombreArchivo, 128);
                    retorno = 0;
                    printf("\nCarga Exitosa! Venta id: %d\n", ventas[index].id);
                }
            }
        }
    }
    return retorno;
}

void imprimirVentas(Venta* ventas, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(ventas[i].aCobrar == 1)
        {
            imprimirVenta(ventas[i]);
        }
    }
}

int altaDeVenta(Venta* ventas, int len, int idCliente)
{
    int retorno = -1;
    int auxCantidadAfiches;
    int auxIdCliente;
    int auxZona;
    char auxNombreArchivo[128];

    int index = getIndiceVacioVentas(ventas, len);
        if (len >= 0 && utn_getInt(&auxCantidadAfiches, 5, "Ingrese cantidad de afiches: \n", "Dato invalido\n", 1, 100000) == 0)
        {
            if (utn_getString(auxNombreArchivo, 5, "Ingrese nombre del archivo: \n", "Dato invalido\n", 128) == 0)
            {
                if (utn_getInt(&auxZona, 5, "Ingrese la zona (1-CABA, 2-ZONA SUR, 3-ZONA OESTE)\n", "Dato invalido\n", 0, 4) == 0)
                {
                    ventas[index].idCliente = idCliente;
                    ventas[index].id = generarID();
                    ventas[index].aCobrar = 1;
                    ventas[index].zona = auxZona;
                    strncpy(ventas[index].nombreArchivo, auxNombreArchivo, 128);
                    retorno = 0;
                    printf("\nCarga Exitosa! Venta id: %d\n", ventas[index].id);
                }
            }
        }

    return retorno;
}

void imprimirVenta(Venta v)
{
    if(v.aCobrar == 1)
    {
        printf("\nid: %d\nId cliente: %d\nCantidad afiches: %d\nNombre archivo: %s\nzona: %d\nA Cobrar: %d\n",
            v.id,
            v.idCliente,
            v.cantidadAfiches,
            v.nombreArchivo,
            v.zona,
            v.aCobrar
            );
    } else
    {
        printf("La venta con id %d no esta en estado a cobrar\n", v.id);
    }
}

int modificarVenta(Venta* ventas, int len, int id)
{
    int retorno = -1;
    int index = getVentaById(ventas, len, id);
    int auxCantAfiches;
    int auxZona;
    if (utn_getInt(&auxCantAfiches, 5, "Ingrese cant afiches: \n", "Dato invalido\n", 0, 10000) == 0)
    {
        if (utn_getInt(&auxZona, 5, "Ingrese la zona (1-CABA, 2-ZONA SUR, 3-ZONA OESTE)\n", "Dato invalido\n", 0, 4) == 0)
        {
            ventas[index].cantidadAfiches = auxCantAfiches;
            ventas[index].zona = auxZona;
            retorno = 0;
        }
    }
    return retorno;
}

void cargaForzadaVenta(Venta* ventas, int len, int idCliente, int cantAfiches, char* nombreArchivo, int zona)
{
    int index = getIndiceVacioVentas(ventas, len);
    ventas[index].id = generarID();
    ventas[index].idCliente = idCliente;
    ventas[index].cantidadAfiches = cantAfiches;
    ventas[index].zona = zona;
    ventas[index].aCobrar = 1;
    strncpy(ventas[index].nombreArchivo, nombreArchivo, 128);
}

int cobrarVenta(Venta* ventas, int len, int id)
{
    int retorno = -1;
    int index = getVentaById(ventas, len, id);
    if(len>0 && id >= 0)
    {
        ventas[index].aCobrar = 0;
        retorno = 0;
    }
    return retorno;
}

int getCantidadVentasPorCliente(Venta* ventas, int len, int idCliente)
{
    int cantVtas = 0;
    int i;
    for(i=0; i<len;i++)
    {
        if(ventas[i].idCliente == idCliente && ventas[i].aCobrar)
        {
            cantVtas++;
        }
    }
    return cantVtas;
}

int eliminarVentasDeCliente(Venta* ventas, int len, int idCliente)
{
    int retorno = -1;
    int i;
    for(i=0; i<len;i++)
    {
        if(ventas[i].idCliente == idCliente)
        {
            ventas[i].aCobrar = 1;
            retorno = 0;
        }
    }
    return retorno;
}

/*************estaticas************************/
static int getIndiceVacioVentas(Venta* ventas,int len)
{
    int i;
    int retorno=-1;
    for (i=0; i<len; i++)
    {
        if(ventas[i].aCobrar==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int getVentaById(Venta* ventas, int len, int id)
{
    int retorno = -1;
    int i;
    for (i = 0; i < len; i++)
    {
        if (ventas[i].id == id && ventas[i].aCobrar == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

static int generarID(void)
{
    static int contID=-1;
    return ++contID;
}
