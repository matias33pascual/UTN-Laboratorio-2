#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// estructura
typedef struct
{
    int dato;
    struct nodo* siguiente;
} nodo;

/// funciones
nodo* clase_04_inicLista()
{
    return NULL;
}

/// ejemplo de como modificar el valor de un nodo
void clase_04_inicLista2(nodo** lista)
{
    *lista = NULL;
}

nodo* clase_04_crearNodo(int dato)
{
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

nodo* clase_04_agregarPrincipio(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
        lista = nuevoNodo;

    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    //otra forma de hacer lo mismo
    /*
    if(lista != NULL)
        nuevoNodo->siguiente = lista;

    lista = nuevoNodo;

    //*/

    return lista;
}

nodo* clase_04_buscarUltimo(nodo* lista)
{
    /// seg es seguidor, iterador, buscador, aux, etc.
    nodo* seg = lista;

    if(seg != NULL)
        while(seg->siguiente != NULL)
            seg = seg->siguiente;

    return seg;
}

void clase_04_mostrarUnNodo(nodo* nodo)
{
    printf("dato: %i \n", nodo->dato);
}

void clase_04_cambio(nodo* lista)
{
    lista = NULL;
}
