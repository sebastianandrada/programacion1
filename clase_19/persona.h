#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    char id[1024];
    char nombre[1024];
    char apellido[1024];
}Persona;

Persona* persona_new();
void persona_delete();
Persona* persona_newConParametros(char* id,char* nombre,char* apellido);

int persona_setId(Persona* this,char* id);
int persona_getId(Persona* this,char* id);

int persona_setNombre(Persona* this,char* nombre);
int persona_getNombre(Persona* this,char* nombre);

int persona_setApellido(Persona* this,char* apellido);
int persona_getApellido(Persona* this,char* apellido);

#endif // PERSONA_H_INCLUDED
