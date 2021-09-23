#include <stdio.h>
#include <stdlib.h>

/** FUNCIONES PARA PRACTICAR CORRECCION DE FUNCIONES */
/*
/// que esta mal en esta funcion?
int inicPila (Pila pila)
{
    (*pila)=inicLista(pila);
}

errores:
    valor de retorno: deberia void
    inicLista no lleva parametros
    el parametro Pila debe ir como puntero

    corrrecion:
        void inicPila (Pila* pila)
        {
            (*pila)=inicLista();
        }







/*





/// que hace esta funcion?
int f(Pila* pila)
{
    int rta=0;
    if ((*pila)==NULL)
    {
        rta = 1;
    }

    return rta;
}
*/



#include "librerias/Pila.h"


/// que error tiene esta funcion? escribir la funcion correcta
int otroTope (Pila *pila)
{
    int rta=0;
    if((*pila)!=NULL)
    {
        rta=verPrimero(*pila);
    }

    return rta;
}

int main()
{
    int a = 10;
    {
        int b = 20;
        a = 20;
        {
            b = 30;
            int c = 40;
            {
                b = 60;
            }
        }

//        c = 50;
    }

    printf("%i", a);



}





/*








/// esta funcion deberia crear un nodo, pero funciona mal. Corregirla
void crearNodo(nodo* unNodo)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = unNodo;

    return aux;
}

/// esta funcion deberia crear un nodo doble, pero funcion mal.
aux * crearNodo2(nodo* unNodo)
{
    nodo2* aux = (nodo2 *)malloc(sizeof(nodo2));
    aux->dato=dato;
    aux->ste=NULL;

    return aux;
}

int main()
{



    return 0;
}


















int tope (Pila * pila)
{
    int rta=0;
    if((*pila)!=NULL)
    {
       rta=verPrimero(*pila);
    }
    return rta;
}
*/
