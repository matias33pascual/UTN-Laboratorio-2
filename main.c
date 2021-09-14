#include <stdio.h>
#include <stdlib.h>

    /*
        si esta vacia, retorno NULL
        si tiene un solo nodo, retorna lista
        si tiene mas de un nodo, tomo el 1er nodo, invierto lo que sigue y
        lo agrego al final de la lista invertida

        nos vamos a ayudar con la funcion agregar al final

        primero tengo que desvicular al nodo de la lista
        OJO no perder las referencias...
    */
nodo * invertirRecursivo (nodo * lista)
{
    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=lista;  // guardo el primero nodo
        lista=lista->siguiente;   // avanzo en la lista
        primero->siguiente=NULL;  // desvinculo el primero nodo
        lista=agregarFinal(invertirRecursivo(lista),primero);
    }
    return lista;

}
int main()
{
    int i = 0;
    int j = 0;

    i = ++i;
    j = j++;


    printf("++i: %i \n", i);
    printf("j++: %i \n", j);


    return 0;
}
