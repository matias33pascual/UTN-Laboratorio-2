/**
    REPASO DE CONTENIDOS
*/

#include <stdio.h>
#include <stdlib.h>


/// PUNTERO DOBLE
void _clase_01_punteroDoble()
{
    int variableA = 10;
    int* pVariableA = &variableA;
    int** ppVariableA = &pVariableA;

    printf("&variable A: %X \n", &variableA);
    printf("valor de variable A: %i \n\n", variableA);

    printf("&puntero a variable A: %X \n", &pVariableA);
    printf("valor de puntero de variable A: %X \n\n", pVariableA);
    printf("valor almacenado donde apunta puntero A: %i \n\n", *pVariableA);

    printf("PUNTERO DOBLE \n\n");
    printf("el valor almacenado a donde apunta el puntero que apunto", **ppVariableA);
}

/// EJERCICIO RESUELTO
/**
    reciba como parámetros de entrada un arreglo de enteros y su dimensión

    y tres parámetros de salida
        tres números enteros que representen:
            valor máximo, -> arreglo, validos [retornar | por referencia]
            valor mínimo y
            promedio.

    Se debe usar pasaje de parámetros por referencia.
*/

void _clase_01_fMayor(int arreglo[], int dimension, int* maximo)
{
    *maximo = arreglo[0];

    for(int i = 1; i < dimension; i++)
    {
        if(arreglo[i] > *maximo)
            *maximo = arreglo[i];
    }
}

void _clase_01_fMenor(int arreglo[], int dimension, int* menor)
{
    *menor = arreglo[0];

    for(int i = 1; i < dimension; i++)
    {
        if(arreglo[i] < *menor)
            *menor = arreglo[i];
    }
}

void _clase_01_fPromedio(int arreglo[], int dimension, float* promedio)
{
    int suma = 0;

    for(int i = 0; i < dimension; i++)
    {
        suma += arreglo[i];
    }

    *promedio = (float) suma / dimension;
}


void _clase_01_max_min_prom(int arreglo[], int dimension, int* maximo, int* minimo, float* promedio)
{
    /**
        fMayor(arreglo, dimension, maximo);
        fMinimo(arreglo, dimension, minimo);
        fPromedio(arreglo, dimension, promedio);
    */

    int suma = 0;
    for(int i = 0; i < dimension; i++)
    {
        suma += arreglo[i];

        if(arreglo[i] < *minimo)
            *minimo = arreglo[i];

        if(arreglo[i] > *maximo)
            *maximo = arreglo[i];
    }

    *promedio = (float) suma / dimension;
}
