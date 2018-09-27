#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#include "pantalla.h"
typedef struct {
    int id;
    char nombreVideo[50];
    int idPantalla;
    int cuil;
    int dias;
    int isEmpty;
}Contratacion;

int initContrataciones(Contratacion* cc, int length, int valor);
int altaContratacion(Contratacion* cc, int length, int idPantalla);
int getIndiceVacioContratacion(Contratacion* cc,int length);
void cont_alta_forzada(Contratacion* cc, int len, char* nombreVideo, int idPantalla, int cuil, int dias);
void listarPantallasCliente(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, Pantalla* pantallas, int lenPantallas);
int buscarPorCuitEIdP(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, int idPantalla);
int modificarContratacion(Contratacion* contrataciones,int lenContrataciones, int indexCont);
int bajaContratacion(Contratacion* contrataciones,int len, int indexCont);
int consultaFacturacion(Contratacion* contrataciones,int lenContrataciones, int cuitCliente, Pantalla* pantallas, int lenPantallas);
int imprimirContrataciones(Contratacion* contrataciones,int lenContrataciones, Pantalla* pantallas, int lenPantalla);
#endif // CONTRATACION_H_INCLUDED
