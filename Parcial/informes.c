#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include <string.h>

int generarArchivoInformes(char* fileName,LinkedList* listaVentas)
{
    FILE* pArchivo = fopen(fileName, "w");
    int retorno = -1;
    int cantVendidasTotales = 0;
    int cantidadMayorA10000 = 0;
    int cantidadMayorA20000 = 0;
    int cantidadDeLCDs = 0;

    cantVendidasTotales = ll_count(listaVentas, venta_totalesVendidas);
    cantidadMayorA10000 = ll_count(listaVentas, venta_ventasMayorA10000);
    cantidadMayorA20000 = ll_count(listaVentas, venta_ventasMayorA20000);
    cantidadDeLCDs = ll_count(listaVentas, venta_ventasTvLCDs);

    if(pArchivo != NULL)
    {
        fprintf(pArchivo, "**************************\n");
        fprintf(pArchivo, "INFORME DE VENTAS\n");
        fprintf(pArchivo, "**************************\n");
        fprintf(pArchivo, "- Cantidad de unidades vendidas totales: %d\n", cantVendidasTotales);
        fprintf(pArchivo, "- Cantidad de ventas por un monto mayor a $10000: %d\n", cantidadMayorA10000);
        fprintf(pArchivo, "- Cantidad de ventas por un monto mayor a $20000: %d\n", cantidadMayorA20000);
        fprintf(pArchivo, "- Cantidad de TVs LCD vendidas: %d\n", cantidadDeLCDs);
        fprintf(pArchivo, "**************************\n");
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;
}
