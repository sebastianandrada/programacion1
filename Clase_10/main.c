#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#include "contratacion.h"
#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000
#define TIPO_LCD 0
#define TIPO_LED 1
/*
    contratacion:
    id, video, idPantalla, dias, cuit, isEmpty,
*/
int main()
{
    Pantalla pantallas[CANT_PANTALLAS];
    initPantallas(pantallas, CANT_PANTALLAS, 1);

    Contratacion contrataciones[CANT_CONTRATACIONES];
    initContrataciones(contrataciones, CANT_CONTRATACIONES, 1);

    pan_alta_forzada(pantallas, CANT_PANTALLAS, "Cabildo", 0, 123.4);
    pan_alta_forzada(pantallas, CANT_PANTALLAS, "Rosario", 1, 489.7);
    pan_alta_forzada(pantallas, CANT_PANTALLAS, "PuebloUno", 0, 222.2);
    pan_alta_forzada(pantallas, CANT_PANTALLAS, "Accenture", 1, 31.4);

    cont_alta_forzada(contrataciones, CANT_CONTRATACIONES, "Coca cola", 0, 11111, 21);
    cont_alta_forzada(contrataciones, CANT_CONTRATACIONES, "jumbomp4", 1, 11111, 40);
    //cont_alta_forzada(contrataciones, CANT_CONTRATACIONES, "asdaf", 1, 11111, 50);
    cont_alta_forzada(contrataciones, CANT_CONTRATACIONES, "telecentro", 2, 22222, 15);

    //imprimirPantallas(pantallas, CANT_PANTALLAS);

    /*printf("El proximo indice vacio es: %d", getIndiceVacio(pantallas, CANT_PANTALLAS));

    altaPantalla(pantallas, 12, CANT_PANTALLAS);
    altaPantalla(pantallas, 25, CANT_PANTALLAS);

    imprimirPantallas(pantallas, CANT_PANTALLAS);*/

    int opcion;
    int id;
    int idPantalla;
    int index;
    int cuitCliente;
    int indexCont;
    do
    {
        utn_getEntero(&opcion, 50, "\n1)alta\n2)modificacion\n3)listar\n4)baja\n5)Contratar publicidad\n6)Modificar contratacion\n7)Cancelar Contratacion\n8)Consulta Facturacion\n9)Listar Contrataciones\n10)Listar Contrataciones\n11)salir\n", "no!\n",1,18);

    switch(opcion)
    {
        case 1:
        index = getIndiceVacio(pantallas, CANT_PANTALLAS);
        if(index >= 0)
        {
            if(altaPantalla(pantallas, index, CANT_PANTALLAS) != 0)
            {
                printf("ingresaste cualquiera\n");
            }else {
                printf("alta exitosa\n");
            }
        }else {
            printf("no hay mas lugar\n");
        }
        break;
        case 2:
            utn_getEntero(&id,5,"Ingrese id de la pantalla a modificar", "no!", 0, CANT_PANTALLAS);
            if(modificarPantalla(pantallas, id, CANT_PANTALLAS) == 0)
            {
                printf("Modificacion exitosa!!!!!!");
            }
            break;
        case 3:
            imprimirPantallas(pantallas, CANT_PANTALLAS);
            break;
        case 4:
            utn_getEntero(&id,5,"Ingrese id de la pantalla a borrar", "no!", 0, CANT_PANTALLAS);
            if(bajaPantalla(pantallas, CANT_PANTALLAS, id)==0)
            {
                printf("Baja exitosa");
            }
            break;
        case 5:
            imprimirPantallas(pantallas, CANT_PANTALLAS);
            if(utn_getEntero(&idPantalla, 5, "Ingrese el Id de la pantalla a contratar\n", "Invalido\n", 0, CANT_PANTALLAS) == 0)
            {
                if(buscarPantallaPorId(pantallas, CANT_PANTALLAS, idPantalla) != -1)
                {
                    altaContratacion(contrataciones, CANT_CONTRATACIONES, idPantalla);
                    printf("Carga exitosa!\n");
                }
                else{
                    printf("%d id invalido!!", idPantalla);
                }
            }
            break;
        case 6:
            if(utn_getEntero(&cuitCliente, 5, "\nIngrese cuit: ", "error!\n", 0, 999999999)==0)
            {
                listarPantallasCliente(contrataciones, CANT_CONTRATACIONES, cuitCliente, pantallas, CANT_PANTALLAS);
                utn_getEntero(&idPantalla, 5, "\nid pantalla a modificar: ", "no!", 0, 999999);

                indexCont = buscarPorCuitEIdP(contrataciones, CANT_CONTRATACIONES, cuitCliente, idPantalla);
                printf("cantidad de dias contratados para pantalla %d: %d", indexCont , contrataciones[indexCont].dias);
                modificarContratacion(contrataciones, CANT_CONTRATACIONES, indexCont);
                printf("\nModificacion exitosa!\n");
                printf("cantidad de dias contratados para pantalla %d: %d\n", indexCont , contrataciones[indexCont].dias);
            }
            break;
        case 7:
            utn_getEntero(&cuitCliente, 5, "\nIngrese cuit: ", "error!\n", 0, 999999999);
            listarPantallasCliente(contrataciones, CANT_CONTRATACIONES, cuitCliente, pantallas, CANT_PANTALLAS);
            utn_getEntero(&idPantalla, 5, "\nid pantalla a cancelar: ", "no!", 0, 999999);

            indexCont = buscarPorCuitEIdP(contrataciones, CANT_CONTRATACIONES, cuitCliente, idPantalla);
            bajaContratacion(contrataciones, CANT_CONTRATACIONES, indexCont);
            printf("\nCancelacion exitosa!");
            break;
        case 8:
            utn_getEntero(&cuitCliente, 5, "\nIngrese cuit: ", "error!\n", 0, 999999999);
            float totalFacturacion = consultaFacturacion(contrataciones, CANT_CONTRATACIONES, cuitCliente, pantallas, CANT_PANTALLAS);
            printf("Total: $%.2f", totalFacturacion);
            break;
        case 9:
            imprimirContrataciones(contrataciones, CANT_CONTRATACIONES, pantallas, CANT_PANTALLAS);
            break;
        case 10:
            listarContratacionesPorCliente(contrataciones, CANT_CONTRATACIONES, pantallas, CANT_PANTALLAS);
            break;
        case 11:
            sortPantallasPorPrecio(pantallas, CANT_PANTALLAS, 1);
            imprimirPantallas(pantallas, CANT_PANTALLAS);
            break;
        case 12:
            sortPantallasPorNombre(pantallas, CANT_PANTALLAS, 0);
            imprimirPantallas(pantallas, CANT_PANTALLAS);
        }
    }
    while(opcion != 15);

    return 0;
}
