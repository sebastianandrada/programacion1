#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    float altura;
    /*------------------------------------*/
    int idEmpleado;
}Empleado;

Empleado* empleado_new();
Empleado* empleado_newParametros(char* nombre, char* apellido, float altura);
void empleado_delete(Empleado* this);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_getNombre(Empleado* this, char* nombre); //puntero a donde va a poner el nombre
int empleado_setApellido(Empleado* this, char* apellido);
int empleado_getApellido(Empleado* this, char* apellido); //direccion de memoria donde va a poner el apellido
int empleado_setAltura(Empleado* this, float altura);
int empleado_getAltura(Empleado* this, float* altura);
void empleado_print(Empleado* this);
int empleado_compareNombre(void* thisA, void* thisB);
#endif // EMPLEADO_H_INCLUDED
