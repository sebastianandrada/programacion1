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

/** \brief Dar de alta un cliente, pidiendo los datos al usuario
* 
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int altaCliente(Cliente* clientes, int len);

/** \brief Modifica un cliente, permitiendo modificar nombre, apellido y cuit
* 
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \param id int del cliente
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int modificarCliente(Cliente* clientes, int len, int id);

/** \brief Elimina un cliente, indicando isEmpty = TRUE
* 
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \param id int del cliente
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
int eliminarCliente(Cliente* clientes, int len, int id);

/** \brief Dar de alta un cliente, sin pedir datos al usuario, pasando por parametros
* 
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \param nombre char* nombre del cliente
* \param apellido char* apellido del cliente
* \param cuit int cuit del cliente
* \return int Return (-1) si hubo error - (0) si esta Ok
*
*/
void cargaForzadaCliente(Cliente* clientes, int len, char* nombre, char* apellido, int cuit);

/** \brief Obtiene el indice del cliente a partir del id
* 
* \param clientes Cliente* puntero a array de clientes
* \param len int tamaño del array
* \param int id id del cliente
* \return int Return (-1) si hubo error - indice del  cliente, si lo encontró
*
*/
int getClienteById(Cliente* clientes, int len, int id);

/** \brief Imprime por consola un cliente, con todos sus datos
* 
* \param Cliente c
*
*/
void imprimirCliente(Cliente c);

/** \brief Imprime por consola un cliente con todos sus datos, y tambien cantidad de ventas a cobrar que posee
* 
* \param clientes Cliente* puntero a array de clientes
* \param lenC int tamaño del array de clientes
* \param ventas Venta*
* \param lenV tamaño del array de ventas
*
*/
void imprimirClientesConVentas(Cliente* clientes, int lenC, Venta* ventas, int lenV);

/** \brief Indica si el id del cliente, esta en el array de clientes
* 
* \param clientes Cliente* puntero a array de clientes
* \param len tamaño del array de clientes
* \param idCliente id que se buscara en el array de clientes
* \return int Return (-1) si hubo un error - (0) Si esta ok
*/
int esClienteValido(Cliente* clientes, int len, int idCliente);
#endif // CLIENTE_H_INCLUDED
