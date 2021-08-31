/**
    reciba como parámetros de entrada un arreglo de enteros y su dimensión

    y tres parámetros de salida
        tres números enteros que representen:
            valor máximo, -> arreglo, validos [retornar | por referencia]
            valor mínimo y
            promedio.

    Se debe usar pasaje de parámetros por referencia.
*/

#include <stdio.h>
#include <stdlib.h>

void clase_01_fMayor(int arreglo[], int dimension, int* maximo)
{
    *maximo = arreglo[0];

    for(int i = 1; i < dimension; i++)
    {
        if(arreglo[i] > *maximo)
            *maximo = arreglo[i];
    }
}

void fMenor(int arreglo[], int dimension, int* menor)
{
    *menor = arreglo[0];

    for(int i = 1; i < dimension; i++)
    {
        if(arreglo[i] < *menor)
            *menor = arreglo[i];
    }
}

void clase_01_fPromedio(int arreglo[], int dimension, float* promedio)
{
    int suma = 0;

    for(int i = 0; i < dimension; i++)
    {
        suma += arreglo[i];
    }

    *promedio = (float) suma / dimension;
}


void clase_01_max_min_prom(int arreglo[], int dimension, int* maximo, int* minimo, float* promedio)
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

/**

int main()
{
    int maximo;
    int minimo;
    float promedio;

    int dimension = 10;
    int arreglo[dimension];

    max_min_prom(arreglo, dimension, &maximo, &minimo, &promedio);

    return 0;
}

*/
