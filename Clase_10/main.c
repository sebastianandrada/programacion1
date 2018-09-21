#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "pantalla.h"
#define CANT_PANTALLAS 100
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

    //imprimirPantallas(pantallas, CANT_PANTALLAS);

    /*printf("El proximo indice vacio es: %d", getIndiceVacio(pantallas, CANT_PANTALLAS));

    altaPantalla(pantallas, 12, CANT_PANTALLAS);
    altaPantalla(pantallas, 25, CANT_PANTALLAS);

    imprimirPantallas(pantallas, CANT_PANTALLAS);*/

    int opcion;
    int id;
    int index;
    do
    {
        utn_getEntero(&opcion, 50, "\n1)alta\n2)modificacion\n3)listar\n4)baja\n5)salir\n", "no!\n",1,5);
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
        }

    }
    while(opcion != 5);

    return 0;
}
