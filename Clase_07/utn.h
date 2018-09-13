#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max);
int utn_getFloat(float* pFloat, char* msg, char msgErr[], float min, float max, int reintentos);

int utn_getNombre(char* pNombre, char* msg, char msgErr[]);

#endif // UTN_H_INCLUDED
