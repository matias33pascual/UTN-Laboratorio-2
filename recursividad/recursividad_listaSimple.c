/*
#include "../librerias/listaEnlazada.h"
#include "../librerias/persona.h"

void mostrarRecursivo(nodo* seg)
{
    if(seg!= NULL)
    {
        mostrarNodo(seg);
        mostrarRecursivo(seg->siguiente);
    }
}

nodo* buscarUltimoRecursivo(nodo* iterador)
{
    if(iterador->siguiente == NULL)
        return iterador;

    else
        return buscarUltimoRecursivo(iterador->siguiente);
}

void ejemplo_listaSimpleRecursiva()
{
    nodo* lista = inicLista();
    //mostrarNodo(buscarUltimoRecursivo(lista));

    lista = agregarPpio(lista, crearNodo((persona){"nombre", 10}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre1", 20}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre2", 30}));
    lista = agregarPpio(lista, crearNodo((persona){"nombre3", 40}));

//    lista = insertarFinalRecursivo(lista, crearNodo((persona){"ultimo", 60}));

    mostrarRecursivo(lista);
}
*/
