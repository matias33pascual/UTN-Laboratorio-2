#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"

typedef struct
{
     nodo2* inicio;
     nodo2* fin;
} Fila;

void inicFila(Fila* fila);

void mostrar(Fila* fila);

void agregar(Fila* fila, int dato);

int extraer(Fila* fila);

void leer(Fila* fila);

int primero(Fila* fila);

int filaVacia(Fila* fila);

#endif // FILA_H_INCLUDED
