// funcion promedio recursivo de un arreglo
#include "../librerias/lista.h"

float clase_03_promedioRecursivo(int A[], int validos, int i)
{
    float prom=0;

    if(i<validos)
    {
        prom = ((float)A[i]/(float)validos)+clase_03_promedioRecursivo(A, validos, i+1);
    }

    return prom;
}

/// 1 Calcular el factorial de un número en forma recursiva
int clase_03_factorial (int x)
{
    int rta;
    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_03_factorial(x-1);
    }
    return rta;
}

///2 Calcular la potencia de un número en forma recursiva
int clase_03_potencia(int x, int factor)
{
    int rta;
    if(factor==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_03_potencia(x,factor-1);
    }
    return rta;
}

int clase_03_menorRecursivo(int A[], int i, int cant)
{
    int m;
    /// cuando llego al final del arreglo, retorno ese valor
    /// para comparar con los de las etapas recursivas anteriores
    if(i==cant)
    {
        m=A[cant-1];
    }
    else
    {
        m=clase_03_menorRecursivo(A, i+1, cant);
        if(m>A[i])
        {
            m = A[i];
        }
    }
    return m;
}

/// TRABAJO PRACTICO 4.3 ---------------

/*
1. Recorrer una lista y mostrarla en forma invertida.
*/

void mostrarListaInvertidaR(nodo * lista)
{
    if(lista!=NULL)
    {
        mostrarListaInvertidaR(lista->siguiente);
        mostrar(lista);
    }
}

/*
2. Sumar los elementos de una lista.
*/

int sumaContenidoListaR(nodo *lista)
{
    int rta=0;

    if(lista!=NULL)
    {
        rta=lista->dato+sumaContenidoListaR(lista->siguiente);
    }

    return rta;
}

/*
3. Mostrar los elementos de una lista ubicados en un lugar par.
*/

void muestraPosParR (nodo *lista, int pos)
{
    if(lista!=NULL)
    {
        if(pos%2==0)
        {
            mostrar(lista);
        }
        muestraPosParR(lista->siguiente, pos+1);
    }
}

/*
4. Invertir una lista cambiando los vínculos.
*/

nodo * invertirRecursivo (nodo * lista)
{
    /*
        si esta vacia, retorno NULL
        si tiene un solo nodo, retorna lista
        si tiene mas de un nodo, tomo el 1er nodo, invierto lo que sigue y
        lo agrego al final de la lista invertida

        nos vamos a ayudar con la funcion agregar al final

        primero tengo que desvicular al nodo de la lista
        OJO no perder las referencias...
    */

    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=lista;  // guardo el primero nodo
        lista=lista->siguiente;   // avanzo en la lista
        primero->siguiente=NULL;  // desvinculo el primero nodo
        lista=agregarFinal(invertirRecursivo(lista),primero);
    }
    return lista;

}

/*
5. Borrar un nodo de una lista.
*/

nodo * borrarNodoR( nodo * lista, int dato)
{
    nodo * aBorrar =NULL;

    if(lista!=NULL)
    {
        if(lista->dato==dato)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente=borrarNodoR(lista->siguiente,dato);
        }
    }
    return lista;
}











