#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "service.h"
#include "user.h"
/*
biblioteca de validaciones (cuit, nombre)
*/
void ordenar(void* lista[], int limite, int (*comparar)(void*, void*));

int main()
{
    Empleado* listaEmpleados[1000];
    int qtyEmpleados = 0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar, "Juan_%d", i);
        listaEmpleados[i] = empleado_newParametros(auxiliar, "Perez", 1.75);
        qtyEmpleados++;
    }
    listaEmpleados[i] = empleado_newParametros("AAAAAAA", "Perez", 1.75);
    qtyEmpleados++;

    ordenar(listaEmpleados, qtyEmpleados, empleado_compareNombre);

    for(i=0;i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }
/*
    Service* services[500];
    int qtyServices = 0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar, "Mensaje_%d", i);
        services[i] = service_newParametros(20, auxiliar);
        qtyServices++;
    }

    for(i=0;i<qtyServices;i++)
    {
        service_print(services[i]);
    }

    User* listaUsers[1000];
    int qtyUsers = 0;
    int i;
    char auxiliar[50];

    for(i=0;i<100;i++)
    {
        sprintf(auxiliar, "Juan_%d", i);
        listaUsers[i] = user_newParametros(auxiliar, "juan@gmail.com");
        qtyUsers++;
    }

    for(i=0;i<qtyUsers;i++)
    {
        user_print(listaUsers[i]);
    }
    */
    return 0;
}

void ordenar(void* lista[], int limite, int (*comparar)(void*, void*))
{
    int flagSwap;
    int i;
    void* auxiliarEmpleado;
    do
    {
        flagSwap = 0;
        for(i=0;i<limite-1;i++)
        {
            if(comparar(lista[i], lista[i+1]) > 0)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = auxiliarEmpleado;
                flagSwap = 1;
            }
        }
    }while(flagSwap);
}
