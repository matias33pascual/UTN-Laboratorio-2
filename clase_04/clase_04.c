#include <stdlib.h>
#include <stdio.h>

/// estructura
typedef struct
{
    int dato;
    struct nodo* siguiente;
} nodo;

/// funciones
nodo* inicLista()
{
    return NULL;
}

/// ejemplo de como modificar el valor de un nodo
void inicLista2(nodo** lista)
{
    *lista = NULL;
}

nodo* crearNodo(int dato)
{
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

//    printf("F &nuevoNodo = %X \n", &nuevoNodo);
//    printf("F nuevoNodo = %X \n", nuevoNodo);

    return nuevoNodo;
}

nodo* agregarPrincipio(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
        lista = nuevoNodo;

    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    /*

    otra forma de hacer lo mismo

    if(lista != NULL)
        nuevoNodo->siguiente = lista;

    lista = nuevoNodo;

    */

    return lista;
}

nodo* buscarUltimo(nodo* lista)
{
    /// seg es seguidor, iterador, buscador, aux, etc.
    nodo* seg = lista;

    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }

    return seg;
}

void mostrarNodos(nodo* lista)
{
    nodo* seg = lista;
    while(seg != NULL)
    {
        mostrarUnNodo(seg);
        seg = seg->siguiente;
    }
}

void mostrarUnNodo(nodo* nodo)
{
    printf("dato: %i \n", nodo->dato);
}

void cambio(nodo* lista)
{
    lista = NULL;
}

/// ejemplo
void clase_04_ejemplo()
{
    //clase_04_ejemplo1();
    clase_04_ejemplo2();
}

void clase_04_ejemplo1()
{
    nodo* lista;
    printf("&lista = %X \n", &lista);

    inicLista(lista);
    printf("lista = %X \n", lista);

    /// almaceno el valor que tenia el nodo dentro
    /// de la funcion. Es decir, la direccion de
    /// memoria de la variable anonima creada
    /// dentro de la funcion
    nodo* nuevoNodo = crearNodo(10);

    printf("&nuevoNodo = %X \n", &nuevoNodo);
    printf("nuevoNodo = %X \n", nuevoNodo);

    /// ahora lista apunta a la variable anonima
    lista = agregarPrincipio(lista, nuevoNodo);
    printf("lista = %X \n", lista);
}

void clase_04_ejemplo2()
{
    nodo* lista;
    lista = inicLista();

    //inicLista2(lista); error, no se modifica el valor de lista
    //inicLista2(&lista);
    //printf("lista: %X \n", lista);

    lista = agregarPrincipio(lista, crearNodo(10));
    lista = agregarPrincipio(lista, crearNodo(20));
    lista = agregarPrincipio(lista, crearNodo(30));
    lista = agregarPrincipio(lista, crearNodo(40));

    mostrarNodos(lista);

    nodo* ultimoNodo = buscarUltimo(lista);
    printf("valor del ultimo nodo: %d \n", ultimoNodo->dato);
}
