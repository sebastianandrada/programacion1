#include <stdio.h>
#include "utn.h"
#include "contratacion.h"
#include <string.h>
#include "pantalla.h"

static int generarID(void);
static int getCantidadDeContrataciones(Contratacion* contrataciones, int len, int cuil);

int initContrataciones(Contratacion* cc, int length, int valor)
{
    int i;
    int retorno = -1;
    if(length > 0)
    {
        for(i=0; i<length; i++)
        {
            cc[i].isEmpty = valor;
            retorno = 0;
        }
    }

    return retorno;
}


int altaContratacion(Contratacion* cc, int length, int idPantalla)
{
    int retorno = -1;
    int index = getIndiceVacioContratacion(cc, length);
    char auxNombre[50];
    int auxCuil;
    int auxDias;
    if(length > 0 && (utn_getLetras(auxNombre, 50, 5, "\narchivo de video: ", "nombre invalido\n") == 0))
    {
        if(utn_getEntero(&auxCuil, 5, "\nIngrese el cuil: ", "no!", 0, 99999999) == 0)
        {
            if(utn_getEntero(&auxDias, 3, "\ncantidad dias contratacion: ", "no!", 0, 99999999))
            {
                cc[index].cuil = auxCuil;
                cc[index].dias = auxDias;
                cc[index].idPantalla = idPantalla;
                strncpy(cc[index].nombreVideo, auxNombre, 50);
                cc[index].id = generarID();
                cc[index].isEmpty = 0;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int getIndiceVacioContratacion(Contratacion* cc,int length)
{
    int i;
    int retorno=-1;
    for (i=0;i<length;i++)
    {
        if(cc[i].isEmpty==1)
        {
            retorno=i;
            break;

        }
    }
    return retorno;
}


void cont_alta_forzada(Contratacion* cc, int len, char* nombreVideo, int idPantalla, int cuil, int dias)
{
    int index = getIndiceVacioContratacion(cc, len);
    if(index >= 0)
    {
        cc[index].idPantalla = idPantalla;
        cc[index].cuil = cuil;
        cc[index].dias = dias;
        cc[index].isEmpty = 0;
        strncpy(cc[index].nombreVideo, nombreVideo, 50);
        cc[index].id = generarID();
    }
}


void listarPantallasCliente(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, Pantalla* pantallas, int lenPantallas)
{
    int i;
    for(i=0; i < lenContrataciones; i++)
    {
        if(contrataciones[i].cuil == cuitCliente && contrataciones[i].isEmpty != 1)
        {
            int p = buscarPantallaPorId(pantallas, lenPantallas, contrataciones[i].idPantalla);
            imprimirPantalla(pantallas[p], p);
        }
    }
}

int buscarPorCuitEIdP(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, int idPantalla)
{
    int retorno = -1;
    int i;
    for(i =0; i<lenContrataciones;i++)
    {
        if(contrataciones[i].cuil == cuitCliente && contrataciones[i].idPantalla == idPantalla)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int modificarContratacion(Contratacion* contrataciones,int lenContrataciones, int indexCont)
{
    int retorno = -1;
    int dias;
    if(utn_getEntero(&dias, 3, "\nModificar dias: ", "no!", 0, 99999990) == 0)
    {
        contrataciones[indexCont].dias = dias;
        retorno = 0;
    }

    return retorno;
}

int bajaContratacion(Contratacion* contrataciones,int len, int indexCont)
{
    contrataciones[indexCont].isEmpty = 1;
    return 0;
}

int consultaFacturacion(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, Pantalla* pantallas, int lenPantallas)
{
    float accTotal = 0;
    int i;
    for(i = 0; i<lenContrataciones; i++)
    {
        if(contrataciones[i].cuil == cuitCliente && contrataciones[i].isEmpty == 0)
        {
            int p = buscarPantallaPorId(pantallas, lenPantallas, contrataciones[i].idPantalla);
            accTotal += (pantallas[p].precio * contrataciones[i].dias);

            printf("Contratacion :%d, importe $%.2f\n", contrataciones[i].id, (pantallas[p].precio * contrataciones[i].dias) );
        }
    }
    return accTotal;
}

int imprimirContrataciones(Contratacion* contrataciones,int lenContrataciones, Pantalla* pantallas, int lenPantalla)
{
    int retorno= -1;
    int i;
    for(i = 0; i< lenContrataciones;i++)
    {
        if(contrataciones[i].isEmpty != 1)
        {
            printf("\nContratacion nº: %d\n", i);
            //int p = buscarPantallaPorId(pantallas, lenPantalla, contrataciones[i].idPantalla);
            printf("nombre de la pantalla: %s\n", pantallas[i].nombre);
            printf("nombre video: %s\n", contrataciones[i].nombreVideo);
            printf("cantidad de dias: %d\n", contrataciones[i].dias);
            printf("cuil cliente: %d\n", contrataciones[i].cuil);
            retorno = 0;
        }
    }
    return retorno;
}

void listarContratacionesPorCliente(Contratacion* contrataciones, int lenC, Pantalla* pantallas, int lenP)
{
    int i;
    int cant;
    for(i = 0; i<lenC;i++)
    {
        if(contrataciones[i].isEmpty == 0)
        {
            cant = getCantidadDeContrataciones(contrataciones, lenC, contrataciones[i].cuil);
            printf("Cliente %d\n", contrataciones[i].cuil);
            printf("Cantidad de contrataciones: %d\n", cant);
        }
    }
}

static int getCantidadDeContrataciones(Contratacion* contrataciones, int len, int cuil)
{
    int cont = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if(contrataciones[i].cuil == cuil  && contrataciones[i].isEmpty == 0)
        {
            cont++;
        }
    }
    return cont;
}

/*int getClienteConMayorImporte(Contratacion* c, int lenC, Pantalla* p, int lenP)
{

}*/




static int generarID(void)
{
    static int contID=-1;
    return ++contID;
}
