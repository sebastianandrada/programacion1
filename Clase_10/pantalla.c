#include <stdio.h>
#include "pantalla.h"
#include "utn.h"
#include <string.h>


static int generarID(void);

int initPantallas(Pantalla* pp, int length, int valor)
{
    int i;
    int retorno = -1;
    if(length > 0)
    {
        for(i=0; i<length; i++)
        {
            pp[i].isEmpty = valor;
            retorno = 0;
        }
    }

    return retorno;
}

void imprimirPantallas(Pantalla* pp, int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        if(pp[i].isEmpty == 0)
        {
            imprimirPantalla(pp[i], i);
        }
    }
}

void imprimirPantalla(Pantalla p, int indice)
{
    if(p.isEmpty == 0)
    {
        printf("\nPantalla %d\nNombre: %s\nId: %d\nTipo: %d\nprecio: %.2f\nisEmpty: %d\n",
        indice,
        p.nombre,
        p.id,
        p.tipo,
        p.precio,
        p.isEmpty
        );
        //if(p.tipo==TIPO_LCD)
    }else
    {
        printf("El producto %d no esta cargado \n", indice);
    }

}

int getIndiceVacio(Pantalla* pp,int length)
{
    int i;
    int retorno=-1;
    for (i=0;i<length;i++)
    {
        if(pp[i].isEmpty==1)
        {
            retorno=i;
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

int altaPantalla(Pantalla*pp,int indice,int length)
{
    int auxTipo;
    float auxPrecio;
    char auxNombre[32];
    if (indice<length)
    {

        utn_getLetras(auxNombre,50,2,"Ingrese el nombre: ","Error\n");
        utn_getEntero(&auxTipo, 50, "Ingrese el tipo(LED = 0, LCD = 1)", "no!", 0,1);
        utn_getFloat(&auxPrecio, 50, "Ingrese el precio", "Ingrese un precio valido", 0, 500000);
        strncpy(pp[indice].nombre, auxNombre, 32);
        pp[indice].tipo=auxTipo;
        pp[indice].isEmpty=0;
        pp[indice].precio=auxPrecio;
        pp[indice].id=generarID();
    }
    else
    {
        return -1;
    }
    return 0;
}

int buscarPantallaPorId(Pantalla* pp, int len, int id)
{
    int i;
    int ret = -1;
    for(i=0; i<len; i++)
    {
        if(pp[i].isEmpty==0 && pp[i].id == id)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int modificarPantalla(Pantalla* pp, int id, int len)
{
    int indice = buscarPantallaPorId(pp, len, id);
    int ret;
    int auxTipo;
    float auxPrecio;
    char auxNombre[32];
    if (indice<len)
    {

        utn_getLetras(auxNombre,50,2,"Ingrese el nombre: ","Error\n");
        utn_getEntero(&auxTipo, 50, "Ingrese el tipo(LED = 0, LCD = 1)", "no!", 0,1);
        utn_getFloat(&auxPrecio, 50, "Ingrese el precio", "Ingrese un precio valido", 0, 500000);
        strncpy(pp[indice].nombre, auxNombre, 32);
        pp[indice].tipo=auxTipo;

        ret = 0;
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int bajaPantalla(Pantalla* pp, int len, int id)
{
    int indice = buscarPantallaPorId(pp, len, id);
    int ret = -1;
    if(indice != -1)
    {
        pp[indice].isEmpty = 1;
        ret = 0;
    }
    return ret;

}

void pan_alta_forzada(Pantalla* pp, int len, char* nombre, int tipo, float precio)
{
    int index = getIndiceVacio(pp, len);
    if(index >= 0)
    {
        pp[index].tipo = tipo;
        pp[index].precio = precio;

        strncpy(pp[index].nombre, nombre, 32);

        pp[index].isEmpty = 0;
        pp[index].id = generarID();
    }
}


