#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMinimo;
    int numeroMaximo;

    printf("Ingrese un numero: \n");
    scanf("%d", &numeroUno);

    numeroMinimo = numeroUno;
    numeroMaximo = numeroUno;

    printf("Ingrese otro: \n");
    scanf("%d", &numeroDos);
    printf("Ingrese otro: \n");
    scanf("%d", &numeroTres);

    if(numeroDos > numeroMaximo)
    {
        numeroMaximo = numeroDos;
    }
    else if(numeroDos < numeroMinimo)
    {
        numeroMinimo = numeroDos;
    }

    if(numeroTres > numeroMaximo)
    {
        numeroMaximo = numeroTres;
    }
    else
    {
        if(numeroTres < numeroMinimo)
        {
            numeroMinimo = numeroTres;
        }
    }

    if(numeroUno > numeroMinimo && numeroUno < numeroMaximo)
    {
        printf("El numero del medio es %d \n", numeroUno);
    }
    else if(numeroDos > numeroMinimo && numeroDos < numeroMaximo)
    {
        printf("El numero del medio es %d \n", numeroDos);
    }
    else if(numeroTres > numeroMinimo && numeroTres < numeroMaximo)
    {
        printf("El numero del medio es %d \n", numeroTres);
    }
    else
    {
        printf(" No existe un numer entre medio \n");
    }

    printf("el minimo es: %d \n", numeroMinimo);
    printf("el maximo es: %d \n", numeroMaximo);*/

    int numeroIngresado;
    int numMin;
    int numMax;
    int acum;
    float prom;
    int i;
    acum = 0;

    for(i=0; i<5; i++){
     printf("Ingrese un numero: \n");
     scanf("%d", &numeroIngresado);
     acum = acum + numeroIngresado;
        if(i == 0){
            numMin = numeroIngresado;
            numMax = numeroIngresado;
        } else {
            if(numeroIngresado > numMax){
                numMax = numeroIngresado;
            } else if(numeroIngresado < numMin){
                numMin = numeroIngresado;
            }
        }
    }
    prom = (float)acum / 5;
    printf("El minimo es: %d: y el maximo es %d:", numMin, numMax);
    printf("\nLa suma total es: %d", acum);
    printf("\nEl promedio es : %.2f", prom);
    printf("poner sarasa");

    return 0;
}
