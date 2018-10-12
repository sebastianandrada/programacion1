#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void mostrarOpciones();
void mostrarInforme(Cliente* clientes, int lenC, Venta* ventas, int lenV);
int clienteConMasACobrar(Cliente* clientes, int lenC, Venta* ventas, int lenV);
int clienteConMasAfiches(Cliente* clientes, int lenC, Venta* ventas, int lenV);
#endif // INFORMES_H_INCLUDED
