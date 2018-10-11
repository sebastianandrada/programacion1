#include <stdio.h>
#include "venta.h"
#include "cliente.h"
#include "utn.h"
#include <string.h>
#include "informes.h"
#define CANT_INFOC 1000

static int clienteConMasCobradas(Cliente* clientes, int lenC, Venta* ventas, int lenV);
static int clienteConMasVentas(Cliente* clientes, int lenC, Venta* ventas, int lenV);


void mostrarOpciones()
{
    printf("\n1)Cliente con mas ventas a cobrar");
    printf("\n2)Cliente con mas ventas cobradas");
    printf("\n3)Cliente con mas ventas");
    printf("\n4)Cliente con mas afiches a cobrar");
    printf("\n5)Cliente que compro mas afiches");
    printf("\n6)Zona con menos afiches vendidos");
    printf("\n7)Cantidad de clientes que compraron menos de 1000 afiches");
    printf("\n8)Cantidad de afiches vendidos por cada una de las 3 zonas");
    printf("\n9)Listar ventas ordenadas por zona");
    printf("\n10)Cantidad de afiches vendidos promedio por cliente. (suma de afiches/ suma clientes");
    printf("\n0)Salir");
}

void mostrarInforme(Cliente* clientes, int lenC, Venta* ventas,int  lenV)
{

    int opcion;
    int indexCliente;
    int ctdadVentas;
    int ctdadAfiches;
    //int index;
    do
    {
        mostrarOpciones();
        utn_getInt(&opcion, 5, "\nElija una opcion:", "Elige una opcion valida ", 0, 11);
        switch(opcion)
        {
            case 1:
                indexCliente = clienteConMasACobrar(clientes, lenC, ventas, lenC);
                imprimirCliente(clientes[indexCliente]);
                ctdadVentas = getCantidadVentasPorCliente(ventas, lenV, clientes[indexCliente].id);
                printf("Cantidad de ventas a cobrar: %d\n", ctdadVentas);
            break;
            case 2:
                indexCliente = clienteConMasCobradas(clientes, lenC, ventas, lenC);
                imprimirCliente(clientes[indexCliente]);
                ctdadVentas = getCantidadVentasCobradasPorCliente(ventas, lenV, clientes[indexCliente].id);
                printf("Cantidad de ventas cobradas: %d\n", ctdadVentas);
                break;
            case 3:
                indexCliente = clienteConMasVentas(clientes, lenC, ventas, lenC);
                imprimirCliente(clientes[indexCliente]);
                ctdadVentas = getCantidadVentasPorClienteTotal(ventas, lenV, clientes[indexCliente].id);
                printf("Cantidad de ventas: %d\n", ctdadVentas);
                break;
            case 4:
                indexCliente = clienteConMasAfiches(clientes, lenC, ventas, lenC);
                imprimirCliente(clientes[indexCliente]);
                ctdadAfiches = getCantidadDeAfichesACobrar(ventas, lenV, clientes[indexCliente].id);
                printf("Cantidad de afiches: %d\n", ctdadAfiches);
                break;
        }
    }
    while(opcion != 0);
}


int clienteConMasACobrar(Cliente* clientes, int lenC, Venta* ventas, int lenV)
{
    int i;
    int indexMaxACobrar;
    int maxVtasACobrar;
    int auxCantVtasCliente;
    if(lenC > 0)
    {
        indexMaxACobrar = 0;
        maxVtasACobrar = getCantidadVentasPorCliente(ventas, lenV, clientes[0].id);
        for(i=1;i<lenC;i++)
        {
            auxCantVtasCliente = getCantidadVentasPorCliente(ventas, lenV, clientes[i].id);
            if(auxCantVtasCliente > maxVtasACobrar)
            {
                maxVtasACobrar = auxCantVtasCliente;
                indexMaxACobrar = i;
            }
        }
    } else {
        indexMaxACobrar = 0;
    }
    return indexMaxACobrar;
}

static int clienteConMasCobradas(Cliente* clientes, int lenC, Venta* ventas, int lenV)
{
    int i;
    int indexMaxCobradas;
    int maxVtasCobradas;
    int auxCantVtasCliente;
    if(lenC > 0)
    {

        maxVtasCobradas = getCantidadVentasCobradasPorCliente(ventas, lenV, clientes[0].id);
        for(i=1;i<lenC;i++)
        {
            auxCantVtasCliente = getCantidadVentasCobradasPorCliente(ventas, lenV, clientes[i].id);
            if(auxCantVtasCliente > maxVtasCobradas)
            {
                maxVtasCobradas = auxCantVtasCliente;
                indexMaxCobradas = i;
            }
        }
    } else {
        indexMaxCobradas = 0;
    }
    return indexMaxCobradas;
}

static int clienteConMasVentas(Cliente* clientes, int lenC, Venta* ventas, int lenV)
{
    int i;
    int indexMaxACobrar;
    int maxVtasCliente;
    int auxCantVtasCliente;
    if(lenC > 0)
    {
        maxVtasCliente = getCantidadVentasPorClienteTotal(ventas, lenV, clientes[0].id);
        indexMaxACobrar = 0;
        for(i=1;i<lenC;i++)
        {
            auxCantVtasCliente = getCantidadVentasPorClienteTotal(ventas, lenV, clientes[i].id);
            if(auxCantVtasCliente > maxVtasCliente)
            {
                maxVtasCliente = auxCantVtasCliente;
                indexMaxACobrar = i;
            }
        }
    } else {
        indexMaxACobrar = 0;
    }
    return indexMaxACobrar;
}

int clienteConMasAfiches(Cliente* clientes, int lenC, Venta* ventas, int lenV)
{
    int i;
    int indexConMasAfiches;
    int maxCantidadAfiches;
    int auxCantVtasCliente;
    if(lenC > 0)
    {
        indexConMasAfiches = 0;
        maxCantidadAfiches = getCantidadDeAfichesACobrar(ventas, lenV, clientes[0].id);
        for(i=1;i<lenC;i++)
        {
            auxCantVtasCliente = getCantidadDeAfichesACobrar(ventas, lenV, clientes[i].id);
            if(auxCantVtasCliente > maxCantidadAfiches)
            {
                indexConMasAfiches = i;
            }
        }
    } else {
        indexConMasAfiches = 0;
    }
    return indexConMasAfiches;
}
