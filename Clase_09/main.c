/*
1)Definir un tipo de dato que represente un producto.
El producto tiene un nombre, una descripcion y un precio.

2) Definir un array de 200 productos, indicar
de alguna manera que la info no esta cargada.

3)Realizar una funcion que reciba el array,
un indice,y le permita al usuario cargar los datos en el item de
la posicion especificada por el indice.

4)Realizar una funcion que reciba el array
y un indice e imprima los datos del producto de la
posicion del indice.

5)Hacer una funcion que devuelva el indice de un item vacio
(sin cargar)

6) Realizar un programa con un menu de dos opciones :
a)cargar un producto
b)imprimir lista de producto

7)Agregar el tipo de dato el campo ID que
represente un identificador unico
Modificar el codigo anterior para el que ID se genere
automaticamente
Se debera cargar el ID automaticamente al cargar un producto y debera imprimir
al imprimir la lista

*/
#include <stdio.h>
#include <stdlib.h>
#include"producto.h"
#include <string.h>
#include"UTN.h"
#define MAX 200
int main()
{
    Producto p[MAX];
//    int i;
    /*for (i=0;i<MAX;i++)
    {
      p[i].isEmpty=1;
    }*/
    //arrayInit(p,MAX,1);

    /*strcpy(p[5].nombre,"Cocina");
    strcpy(p[5].descripcion,"asdjasdklsadasldjasd");
    p[5].precio=4554.2;
    p[5].isEmpty=0;

    for (i=0;i<MAX;i++)
    {
      if(p[i].isEmpty==1)
      {
        printf(" NO Esta cargado el producto nro: %d\n",i);
      }
    }*/
    //altaProducto(p,0,MAX);
    //altaProducto(p,100,MAX);

    //imprimirProducto(p,100);
    //printf("EL indice vacio es %d",getIndiceVacio(p,MAX));
    menuProducto(p);
    return 0;
}