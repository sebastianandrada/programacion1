#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct {
    int id;
    int tipo;
    char nombre[32];
    float precio;
    int isEmpty;
}Pantalla;

int initPantallas(Pantalla* pp, int length, int valor);
void imprimirPantallas(Pantalla* pp, int length);
int getIndiceVacio(Pantalla* pp,int length);
int altaPantalla(Pantalla* pp,int indice,int length);
int modificarPantalla(Pantalla* pp, int indice, int len);
int bajaPantalla(Pantalla* pp, int len, int id);
int buscarPantallaPorId(Pantalla* pp, int len, int id);
void pan_alta_forzada(Pantalla* pp, int len, char* nombre, int tipo, float precio);
void imprimirPantalla(Pantalla p, int indice);
void sortPantallasPorPrecio(Pantalla* pp, int len, int orden);
void sortPantallasPorNombre(Pantalla* pp, int len, int orden);

#endif // PANTALLA_H_INCLUDED
