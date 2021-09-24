#include "Pila.h"

void inicPila (Pila * pila)
{
    (*pila)=inicLista();
}

int pilavacia (Pila* pila)
{
    int rta=0;
    if ((*pila)==NULL)
    {
        rta = 1;
    }

    return rta;
}

int tope (Pila* pila)
{
    int rta=0;
    if((*pila)!=NULL)
    {
       rta=verPrimero(*pila);
    }
    return rta;
}

int desapilar (Pila* pila)
{
    int rta;
    if((*pila)!=NULL)
    {
        rta = verPrimero(*pila);
        *pila=borrarPrimerNodo(*pila);
    }

    return rta;
}

void apilar (Pila * pila, int dato)
{
    nodo * aux= crearNodo(dato);
    *pila=agregarPpio(*pila,aux);
}

void leerPila (Pila * pila)
{
    nodo *aux = SubprogramaIngresarNuevoDato();
    (*pila)=agregarPpio(*pila,aux);
}

void mostrarPila (Pila * pila)
{
    //nodo * seg = (*pila);
    printf("\nTope ");
    recorrerYmostrar(*pila);
    printf("Base\n");
}
