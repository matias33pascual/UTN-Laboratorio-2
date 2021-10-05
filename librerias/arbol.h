#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;

} nodoArbol;

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, int dato)
{
    if(arbol==NULL)
        arbol = crearNodoArbol(dato);
    else
    {
        if(dato>arbol->dato)
            arbol->der = insertar(arbol->der, dato);
        else
            arbol->izq = insertar(arbol->izq, dato);
    }

    return arbol;
}

void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("%d ", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}
void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        printf("%d ", arbol->dato);
        inorder(arbol->der);
    }
}
void postorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%d ", arbol->dato);
    }
}

nodoArbol * buscar(nodoArbol * arbol, int dato)
{
    nodoArbol * rta=NULL;

    if(arbol!=NULL)
    {
        if(dato == arbol->dato)
            rta = arbol;

        else if(dato>arbol->dato)
            rta = buscar(arbol->der, dato);

        else
            rta = buscar(arbol->izq, dato);
    }

    return rta;
}

#endif // ARBOL_H_INCLUDED
