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

#endif // PANTALLA_H_INCLUDED
