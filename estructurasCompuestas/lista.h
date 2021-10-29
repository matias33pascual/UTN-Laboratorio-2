#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int legajo;
    char apeNom[40];
    int nota;
}stNotaAlumno;

typedef struct _nodo{
    stNotaAlumno n;
    struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stNotaAlumno n);
nodo* agregarPpio(nodo* lista, nodo* nuevoNodo);
nodo* buscarUltimo(nodo* lista);
nodo* buscarNodo(nodo* lista, int nota);
nodo* agregarFinal(nodo* lista, nodo* nuevoNodo);
nodo* borrarNodoBuscado(nodo* lista, int nota);
nodo* agregarEnOrden(nodo * lista, nodo* nuevoNodo);
nodo* borrarTodaLaLista(nodo* lista);
nodo* borrarPrimerNodo(nodo* lista);
nodo* borrarUltimoNodo(nodo* lista);
int sumarNotasLista(nodo* lista);
int sumarNotasListaRecursivo(nodo* lista);
int sumarNotasListaRecursivoTernario(nodo* lista);
void mostrarUnNodo(nodo* aux);
void mostrarUnaNota(stNotaAlumno n);
void recorrerYmostrar(nodo* lista);
int cuentaAlumnos(nodo* lista);


#endif // LISTA_H_INCLUDED
