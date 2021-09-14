/*

#include "../librerias/lista.h"

nodo * intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C);
void   SubprogramaIntercalarDosListas(nodo *listaA, nodo *listaB, nodo *listaC);
nodo * SubprogramaIngresarDatosAlFinal(nodo * lista);
nodo * SubprogramaIngresarNuevoDato();
nodo * invertirLista(nodo * lista);

nodo * intercalarListas(nodo *lista_A, nodo *lista_B, nodo *lista_C)
{
    nodo * aux;

    while((lista_A!=NULL)&&(lista_B!=NULL))
    {
        if(lista_A->dato.edad < lista_B->dato.edad)
        {
            aux=lista_A;

            lista_A = lista_A->siguiente; // avanzo uno en la lista A...

            aux->siguiente=NULL;

            lista_C=agregarFinal(lista_C, aux); // agrego al final en lista C
        }
        else
        {
            aux=lista_B;

            lista_B=lista_B->siguiente; // avanzo uno en la lista b...

            aux->siguiente=NULL; // lo desvinculo

            lista_C=agregarFinal(lista_C, aux); // agrego al final en lista C
        }
    }

    // si quedara algo en la lista A
    if(lista_A!=NULL)
    {

        lista_C=agregarFinal(lista_C, lista_A); // agrego al final en lista C
    }

    // si quedara algo en la lista B
    else if(lista_B!=NULL)
    {

        lista_C=agregarFinal(lista_C, lista_B); // agrego al final en lista C
    }

    return lista_C;
}

void SubprogramaIntercalarDosListas(nodo * listaA, nodo * listaB, nodo * listaC)
{
    printf("Cargando Lista A\n");
    listaA=SubprogramaIngresarDatosAlFinal(listaA);

    printf("Cargando Lista B\n");
    listaB=SubprogramaIngresarDatosAlFinal(listaB);

    printf("Lista A\n");
    recorrerYmostrar(listaA);

    printf("Lista B\n");
    recorrerYmostrar(listaB);

    listaC=intercalarListas(listaA, listaB, listaC);

    listaA=NULL;
    listaB=NULL;

    printf("Lista C\n");
    recorrerYmostrar(listaC);

}

nodo * SubprogramaIngresarDatosAlFinal(nodo * lista)
//subprograma para ingresar los datos en una lista en forma de fila, o sea
//al final de la lista.
{
    nodo * nuevoNodo;
    char cont = 's';
    while (cont=='s')
    {
        //pide los datos por pantalla y crea un nuevo nodo.
        nuevoNodo = SubprogramaIngresarNuevoDato();
        // agrega a la fila un nuevo nodo al final.
        lista = agregarFinal(lista, nuevoNodo);
        printf("desea continuar s/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        printf("\n");
    }
    return lista;
}

nodo * SubprogramaIngresarNuevoDato()
{
    persona aux;
    nodo * nuevoNodo;
    aux=cargarPersona();
    nuevoNodo = crearNodo(aux);
    return nuevoNodo;
}

nodo * invertirLista(nodo * lista)
{
    /// la idea es extraer el primero de la lista original
    /// y luego agregarlo al principio de la nueva lista
    /// retornamos el puntero al inicio de la nueva lista
    /// para pisar la referencia del main

    nodo * listaInvertida=NULL;
    nodo * aux;
    while(lista!=NULL)
    {
        /// extraemos el primero (se puede modularizar)
        aux=lista;

        lista=lista->siguiente;

        aux->siguiente=NULL;

        /// lo agregamos al principio de la nueva lista invertida
        listaInvertida = agregarPpio(listaInvertida, aux);
    }

    return listaInvertida;
}

*/
