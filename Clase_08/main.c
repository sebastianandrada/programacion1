#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_EMPLEADOS 5

//typedef int Persona;
/*struct S_Persona
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
};
typedef struct S_Persona Persona;*/
typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
}Persona;

void printPersona(Persona* p);

int main()
{
    Persona p;
    p.edad = 33;
    p.altura = 1.90;
    //p.nombre = "juan"; //NOO
    //fgets(p.nombre, 70, stdin);
    strncpy(p.nombre, "Juan", 70);
    strncpy(p.dni, "37000123", 20);
    printPersona(&p);
}

void printPersona(Persona* p)
{

    printf("\nnombre: %s", p->nombre);
    printf("\nedad: %d", p->edad);
    printf("\ndni: %s", p->dni);
    printf("\naltura: %.2f", p->altura);

    //p->edad = 99; //SI
    //p.edad = 99 //NO
}

void altaPersona(Persona* per)
{
	char nombreAux[70];
	int edadAux;
	float alturaAux;

	if(utn_getNombre(nombreAux, ... ) == 0)
	{
		if(utn_getEntero(&edadAux, ...) == 0)
		{
			if(utn_getFloat(&alturaAux, ...) == 0)
			{
				//cargo la struct
				per->altura = alturaAux;
				per->edad = edadAux;
				strncpy(per->nombre, nombreAux, 70);				
			}
		}
	}

}

    /*
    int edades[CANTIDAD_EMPLEADOS];
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = -1;
        }
    }
    mostrarArray(edades, CANTIDAD_EMPLEADOS);
    printf("\n------------------------------");
    insertion(edades, CANTIDAD_EMPLEADOS, 1);
    mostrarArray(edades, CANTIDAD_EMPLEADOS);*/

/** menor a mayor = 0, mayor a menor = 1*/
void insertion(int data[],int len, int mayorMenor)
{
    int i,j;
    int temp;
    for(i=1; i<len; i++)
    {
        temp = data[i];
        j=i-1;
        while(j>=0 && ( (mayorMenor == 0 && temp<data[j]) || (mayorMenor == 1 && temp>data[j]) ) ) // temp<data[j] o temp>data[j]
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1]=temp; // inserción
    }
}

int mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}
