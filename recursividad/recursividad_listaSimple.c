#include "../librerias/listaEnlazada.h"
#include "../librerias/persona.h"

void mostrarRecursivo(nodo* iterador)
{
    if(iterador != NULL)
    {
        mostrarNodo(iterador);
        mostrarRecursivo(iterador->siguiente);
    }
}

nodo* insertarFinalRecursivo(nodo* iterador, nodo* nuevoNodo)
{
    if(iterador == NULL)
    {
        iterador = nuevoNodo;
    }
    else if(iterador->siguiente == NULL)
    {
        iterador->siguiente = nuevoNodo;
    }
    else
    {
        insertarFinalRecursivo(iterador->siguiente, nuevoNodo);
    }

    return iterador;
}

nodo* buscarUltimoRecursivo(nodo* iterador)
{
    if(iterador == NULL)
        printf("la lista esta vacia");

    else if(iterador->siguiente == NULL)
        return iterador;

    else
        return buscarUltimoRecursivo(iterador->siguiente);
}

void ejemplo_listaSimpleRecursiva()
{
    nodo* lista = inicLista();
    mostrarNodo(buscarUltimoRecursivo(lista));

    lista = agregarPpio(lista, crearNodo((persona){"nombre", 10}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre1", 20}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre2", 30}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre3", 40}));

    lista = insertarFinalRecursivo(lista, crearNodo((persona){"ultimo", 60}));

    mostrarRecursivo(lista);
}
