#include "../librerias/arbol.h"
#include <stdio.h>

void arbol_ejemplo1()
{
    nodoArbol* arbol = inicArbol();

    arbol = insertar(arbol, 10);
    arbol = insertar(arbol, 20);
    arbol = insertar(arbol, 15);

    printf("inorder: ");
    inorder(arbol);

    printf("\n\n");

    printf("postorder: ");
    postorder(arbol);

    printf("\n\n");

    printf("preorder: ");
    preorder(arbol);

    printf("\n");
}
