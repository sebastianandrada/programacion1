#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
}Empleado;

Empleado* Empleado_new();
void Empleado_delete();
Empleado* Empleado_newConParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);

int em_calcularSueldo(void* p);
int em_printEmpleado(void* p);

#endif // EMPLEADO_H_INCLUDED
