#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "venta.h"
typedef struct {
    int id;
    char nombre[32];
    char apellido[32];
    int cuit;
    int isEmpty;
}Cliente;

/** \brief Indicar que la posicion esta vacia, indicando isEmpty == TRUE
*
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \param valor int valor a grabar en isEmpty
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int initClientes(Cliente* clientes, int len, int valor);
/** \brief Imprime la lista cliente con cada uno de sus campos
*
*/
void imprimirClientes(Cliente* clientes, int len);

int altaCliente(Cliente* clientes, int len);
int modificarCliente(Cliente* clientes, int len, int id);
int eliminarCliente(Cliente* clientes, int len, int id);
void cargaForzadaCliente(Cliente* clientes, int len, char* nombre, char* apellido, int cuit);
int getClienteById(Cliente* clientes, int len, int id);
void imprimirCliente(Cliente c);
void imprimirClientesConVentas(Cliente* clientes, int lenC, Venta* ventas, int lenV);
int esClienteValido(Cliente* clientes, int len, int idCliente);
#endif // CLIENTE_H_INCLUDED
