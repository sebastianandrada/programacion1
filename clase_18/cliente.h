#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[60];
    char apellido[60];
}Cliente;

Cliente* cliente_new();
int cliente_setNombre(Cliente* aux, char* nom);
int cliente_buscarLugarVacio(Cliente** array, int len);
int cliente_inicializarArray(Cliente** array, int len);
int cliente_buscarPorId(Cliente** array, int len, int idCliente);

#endif // CLIENTE_H_INCLUDED
