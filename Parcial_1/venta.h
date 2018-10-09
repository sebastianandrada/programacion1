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

/** \brief Indicar que las posiciones estan vacias, indicando isEmpty == TRUE
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array de ventas
* \param valor a asignar en isEmpty
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int initVentas(Venta* ventas, int len, int valor);
//int altaVenta(Venta* ventas, int len);

/** \brief Crea una nueva venta, para el cliente idCliente, 
*       a partir de los datos solicitados al usuario 
* \param ventas puntero a array de ventas 
* \param len tamaño del array
* \param idCliente id del cliente que al que se le vendió
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int altaDeVenta(Venta* ventas, int len, int idCliente);

/** \brief Modifica una venta, permitiendo modificar cantidad de afiches y zona
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param id int de la venta
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int modificarVenta(Venta* ventas, int len, int id);

/** \brief Se cambia estado de la venta a "Cobrado" (aCobrar == FALSE)
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param id int de la venta
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int cobrarVenta(Venta* ventas, int len, int id);

/** \brief Se recorren todas las ventas, y se eliminan si coinciden con el idCliente
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param idCliente id del cliente
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int eliminarVentasDeCliente(Venta* ventas, int len, int idCliente);

/** \brief Recorre todas las ventas y retorna la cantidad que se corresponden con el idCliente
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param idCliente id del cliente
* \return int Return (-1) si hubo error - Cantidad de ventas para el idCliente
*
*/
int getCantidadVentasPorCliente(Venta* ventas, int len, int idCliente);

/** \brief Busca el indice de la venta con el id
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param id de la venta
* \return int Return (-1) si hubo error - indice del id
*
*/
int getVentaById(Venta* ventas, int len, int id);

/** \brief Imprimir ventas con todos sus datos
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
*
*/
void imprimirVentas(Venta* ventas, int len);

/** \brief Imprime una venta con todos sus datos
* 
* \param venta
*
*/
void imprimirVenta(Venta venta);

/** \brief Carga una nueva venta de manera forzada, sin pedir los datos al usuario
* 
* \param ventas puntero a array de ventas
* \param len tamaño del array
* \param idCliente
* \param cantAfiches int
* \param nombreArchivo char*
* \param zona
*/
void cargaForzadaVenta(Venta* ventas, int len, int idCliente, int cantAfiches, char* nombreArchivo, int zona);
#endif // VENTA_H_INCLUDED
