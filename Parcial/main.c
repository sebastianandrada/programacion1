#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"
#include "Parser.h"
#include "informes.h"


int generarArchivoInformes(char* fileName,LinkedList* listaVentas);

int main()
{
    LinkedList* listaVentas;

    listaVentas = ll_newLinkedList();

    if(parser_parseVentas("data.csv",listaVentas)==1)
    {
        // Generar archivo de salida
        if(generarArchivoInformes("informes.txt",listaVentas)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo ventas\n");

    ll_map(listaVentas, venta_printVenta);

    return 0;
}

