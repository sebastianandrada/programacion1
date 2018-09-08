#include <stdio_ext.h>
#include <stdlib.h>
/*
int getEdad(int *edad);

int main()
{
    int edad;

    getEdad(&edad);
    printf("La edad ingresada es : %d", edad);
    return 0;
}

int getEdad(int *edad)
{
    int auxEdad;
    printf("Ingrese una edad \n");
    scanf("%d", &auxEdad);
    if(auxEdad > 0 && auxEdad < 199)
    {
        *edad = auxEdad;
    }
    else
    {
        printf("Ingrese una edad valida \n");
        scanf("%d", &auxEdad);
    }

}
*/
/*int validarEdad(int edad,int rangoInf, int rangoSup){
    if(edad > rangoInf && edad < rangoSup){
        return 0;
    }else{
        return -1;
    }
}*/

/**Resol*/
int getEdad(int* pEdad);

int main()
{
    int edad;
    if(getEdad(&edad) == 0)
    {
        printf("La edad ingresada es : %d", edad);
    }
    return 0;
}

int getEdad(int* pEdad)
{
    int retorno = -1;
    int auxEdad;
    int reintentos = 3;

    for(reintentos=3; reintentos>0; reintentos--)
    {
        printf("Ingrese una edad \n");
        if(scanf("%d", &auxEdad) == 1)
        {
            if(auxEdad >= 0 && auxEdad < 199)
            {
                *pEdad = auxEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf("\nLa edad es de 0 a 199");
            }
        }
        else
        {
            printf("\nLa edad es numerica");
            __fpurge(stdin);
        }
        return retorno;
    }

}
