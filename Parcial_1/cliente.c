#include <stdio.h>
#include "cliente.h"
#include "utn.h"
#include <string.h>
#include "venta.h"

static int generarID(void);
int getClienteById(Cliente* clientes, int len, int id);

int initClientes(Cliente* clientes, int len, int valor)
{
    int i;
    int retorno = -1;
    if(len > 0)
    {
        for(i=0; i<len; i++)
        {
            clientes[i].isEmpty = valor;
            retorno = 0;
        }
    }

    return retorno;
}

void imprimirClientes(Cliente* clientes, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            imprimirCliente(clientes[i]);
        }
    }
}

void imprimirCliente(Cliente c)
{
    if(c.isEmpty == 0)
    {
        printf("\nid: %d\nNombre: %s\nApellido: %s\ncuit: %d\nisEmpty: %d\n",

               c.id,
               c.nombre,
               c.apellido,
               c.cuit,
               c.isEmpty
              );
    }
    else
    {
        printf("El cliente con id %d no esta cargado \n", c.id);
    }
}

int getIndiceVacio(Cliente* clientes,int len)
{
    int i;
    int retorno=-1;
    for (i=0; i<len; i++)
    {
        if(clientes[i].isEmpty==1)
        {
            retorno=i;
            break;

        }
    }
    return retorno;
}

int altaCliente(Cliente* clientes, int len)
{
    int retorno = -1;
    char auxNombre[32];
    char auxApellido[32];
    int auxCuit;
    int index = getIndiceVacio(clientes, len);
    if (len >= 0 && utn_getString(auxNombre, 5, "Ingrese nombre: \n", "Dato invalido\n", 32) == 0)
    {
        if (utn_getString(auxApellido, 5, "Ingrese un apellido: \n", "Dato invalido\n", 32) == 0)
        {
            if (utn_getInt(&auxCuit, 5, "Ingrese el cuit\n", "Dato invalido\n", 0, 403702290) == 0)
            {
                clientes[index].id = generarID();
                clientes[index].isEmpty = 0;
                clientes[index].cuit = auxCuit;
                strncpy(clientes[index].nombre, auxNombre, 32);
                strncpy(clientes[index].apellido, auxApellido, 32);
                retorno = 0;
                printf("\nCarga Exitosa! Cliente: \n");
                imprimirCliente(clientes[index]);
            }
        }
    }
    return retorno;
}

int modificarCliente(Cliente* clientes, int len, int id)
{
    int retorno = -1;
    char auxNombre[32];
    char auxApellido[32];
    int auxCuit;
    int index = getClienteById(clientes, len, id);

    if (len >= 0 && utn_getString(auxNombre, 5, "Ingrese nuevo nombre a: \n", "Dato invalido\n", 32) == 0)
    {
        if (utn_getString(auxApellido, 5, "Ingrese nuevo apellido: \n", "Dato invalido\n", 32) == 0)
        {

            if (utn_getInt(&auxCuit, 5, "Ingrese cuit: \n", "Dato invalido\n", 0, 4037022902) == 0)
            {
                clientes[index].id = generarID();
                clientes[index].isEmpty = 0;
                clientes[index].cuit = auxCuit;
                strncpy(clientes[index].nombre, auxNombre, 32);
                strncpy(clientes[index].apellido, auxApellido, 32);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int eliminarCliente(Cliente* clientes, int len, int id)
{
    int retorno = -1;
    int index = getClienteById(clientes, len, id);
    if (index != -1)
    {
        clientes[index].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

void cargaForzadaCliente(Cliente* clientes, int len, char* nombre, char* apellido, int cuit)
{
    int index = getIndiceVacio(clientes, len);
    clientes[index].id = generarID();
    clientes[index].isEmpty = 0;
    clientes[index].cuit = cuit;
    strncpy(clientes[index].nombre, nombre, 32);
    strncpy(clientes[index].apellido, apellido, 32);
}

void imprimirClientesConVentas(Cliente* clientes, int lenC, Venta* ventas, int lenV)
{
    int i;
    for(i=0; i<lenC; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            imprimirCliente(clientes[i]);
            int cantVtasCliente = getCantidadVentasPorCliente(ventas, lenV, clientes[i].id);
            printf("Cantidad de ventas a cobrar: %d\n", cantVtasCliente);
        }
    }
}

int esClienteValido(Cliente* clientes, int len, int idCliente)
{
    int retorno = -1;
    int i;
    for(i=0; i <len; i++)
    {
        if(clientes[i].id == idCliente)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/***********estaticas****************/
int getClienteById(Cliente* clientes, int len, int id)
{
    int retorno = -1;
    int i;
    for (i = 0; i < len; i++)
    {
        if (clientes[i].id == id && clientes[i].isEmpty == 0)
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
