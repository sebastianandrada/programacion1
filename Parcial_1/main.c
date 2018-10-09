#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "venta.h"
#define CANT_CLIENTES 100
#define CANT_VENTAS 1000
//#define CABA 0
//#define ZONA

int main()
{
    Cliente clientes[CANT_CLIENTES];
    initClientes(clientes, CANT_CLIENTES, 1);

    Venta ventas[CANT_VENTAS];
    initVentas(ventas, CANT_VENTAS, 0);

    cargaForzadaCliente(clientes, CANT_CLIENTES, "Juan", "Gigg", 1234568);
    cargaForzadaCliente(clientes, CANT_CLIENTES, "Maria", "Alvarez", 1234447);
    cargaForzadaCliente(clientes, CANT_CLIENTES, "Daniela", "Suarez", 123488);

    cargaForzadaVenta(ventas, CANT_VENTAS, 0, 200, "afiche0.jpg", 0);
    cargaForzadaVenta(ventas, CANT_VENTAS, 1, 100, "afiche1.jpg", 1);
    cargaForzadaVenta(ventas, CANT_VENTAS, 2, 300, "afiche2.jpg", 2);
    cargaForzadaVenta(ventas, CANT_VENTAS, 2, 45, "afiche3.jpg", 0);

    int opcion;
    int id;
    int quiereEliminar;

    do
    {
        utn_getInt(&opcion, 5, "\n1)Alta \n2)Modificar\n3)Baja cliente\n4)Venta afiche\n5)Editar afiche\n6)Cobrar venta\n7)Imprimir Clientes\n0)Salir\nElija una opcion ",
                   "Elige una opcion valida ", 0, 8);
        switch (opcion)
        {
            case 1:
                altaCliente(clientes, CANT_CLIENTES);
                break;
            case 2:
                utn_getInt(&id, 10, "Ingrese id de cliente a modificar ", "Id invalido", 0, CANT_CLIENTES);
                if(modificarCliente(clientes, CANT_CLIENTES, id)==0)
                {
                    printf("Baja exitosa!");
                }
                break;
            case 3:
                utn_getInt(&id, 10, "Ingrese id de cliente a borrar ", "Id invalido", 0, CANT_CLIENTES);
                utn_getInt(&quiereEliminar, 10, "Esta seguro/a? \n1)Si\n2)No\nElija una opcion: ", "Opcion invalida", 0, 2);
                if(quiereEliminar)
                {
                    eliminarCliente(clientes, CANT_CLIENTES, id);
                    eliminarVentasDeCliente(ventas, CANT_VENTAS, id);
                    printf("Baja exitosa!");
                }
                break;
            case 4:
                if(utn_getInt(&id, 10, "Ingrese id de cliente a borrar", "Id invalido", 0, CANT_CLIENTES) == 0 && !esClienteValido(clientes, CANT_CLIENTES, id))
                {
                    altaDeVenta(ventas, CANT_VENTAS, id);
                }
                //altaVenta(ventas, CANT_VENTAS);
                break;
            case 5:
                imprimirVentas(ventas, CANT_VENTAS);
                if(utn_getInt(&id, 10, "Ingrese id de la venta a editar ", "Id invalido", 0, CANT_VENTAS)==0 &&
                    !modificarVenta(ventas, CANT_VENTAS, id))
                {
                    printf("Modificacion exitosa!");
                }
                break;
            case 6:
                imprimirVentas(ventas, CANT_VENTAS);
                if(utn_getInt(&id, 10, "Ingrese id de la venta a cobrar ", "Id invalido", 0, CANT_VENTAS)==0)
                {
                    int indexVenta = getVentaById(ventas, CANT_VENTAS, id);
                    int indexCliente = getClienteById(clientes, CANT_CLIENTES, ventas[indexVenta].idCliente);
                    imprimirCliente(clientes[indexCliente]);
                    if(utn_getInt(&quiereEliminar, 5, "Desea cobrar venta? (1-Si, 0-No)", "Opcion invalida", 0, 3) == 0)
                    {
                        if(quiereEliminar && !cobrarVenta(ventas, CANT_VENTAS, id))
                            printf("Cobro exitoso");
                    }
                }
                break;
            case 7:
                imprimirClientesConVentas(clientes, CANT_CLIENTES, ventas, CANT_VENTAS);
                break;
        }
    } while(opcion != 0);

    return 0;
}
