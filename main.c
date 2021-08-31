#include <stdio.h>
#include <stdlib.h>
#include "librerias/listaEnlazada.h"
#include "librerias/persona.h"

int main()
{
//    nodo* lista = inicLista();
//    nodo* lista2 = inicLista();
//
//    lista = agregarPpio(lista, crearNodo((persona){"a", 10}));
//    lista = agregarPpio(lista, crearNodo((persona){"c", 30}));
//    lista = agregarPpio(lista, crearNodo((persona){"e", 50}));
//
//    lista2 = agregarPpio(lista, crearNodo((persona){"b", 20}));
//    lista2 = agregarPpio(lista, crearNodo((persona){"d", 40}));
//    lista2 = agregarPpio(lista, crearNodo((persona){"f", 60}));
//
//    nodo* listaFinal = inicLista();
//    listaFinal = intercalarListas(lista, lista2, listaFinal);
//
//    recorrerYmostrar(listaFinal);

    nodo* listaA = inicLista();
    nodo* listaB = inicLista();
    nodo* listaC = inicLista();


    listaC = SubprogramaIntercalarDosListas(listaA, listaB, listaC);





    return 0;
}
