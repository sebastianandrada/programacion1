#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
typedef struct {
    int idCliente;
    int id;
    int cantidadAfiches;
    char nombreArchivo[128];
    int zona;
    int aCobrar;
}Venta;

int initVentas(Venta* ventas, int len, int valor);
int altaVenta(Venta* ventas, int len);
int modificarVenta(Venta* ventas, int len, int id);
void imprimirVentas(Venta* ventas, int len);
void imprimirVenta(Venta venta);
void cargaForzadaVenta(Venta* ventas, int len, int idCliente, int cantAfiches, char* nombreArchivo, int zona);
int getVentaById(Venta* ventas, int len, int id);
int cobrarVenta(Venta* ventas, int len, int id);
int getCantidadVentasPorCliente(Venta* ventas, int len, int idCliente);
int eliminarVentasDeCliente(Venta* ventas, int len, int idCliente);
int altaDeVenta(Venta* ventas, int len, int idCliente);
#endif // VENTA_H_INCLUDED
