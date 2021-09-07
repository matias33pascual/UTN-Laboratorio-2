#include "Fila.h"

void inicFila(Fila* fila)
{
    fila->inicio=inicLista();
    fila->fin=inicLista();
}

void mostrar(Fila* fila)
{
    printf("inicio ");
    recorrerYmostrar(fila->inicio);
    printf(" fin\n");
}

/// agrega al final de la fila
void agregar(Fila* fila, int dato)
{
    nodo2 * nuevo = crearNodo(dato);

    fila->fin=agregarAlFinal(fila->fin, nuevo);

    if(fila->inicio==NULL)
    {
        fila->inicio=fila->fin;
    }
    fila->fin=nuevo;
}


int extraer(Fila* fila)
{
    int resp;

    if(fila->inicio!=NULL)
    {
        resp=verPrimero(fila->inicio);

        fila->inicio=borrarPrimero(fila->inicio);

        if(fila->inicio==NULL)
            fila->fin=inicLista();
    }
    return resp;
}

void leer(Fila* fila)
{
    int a;
    printf("Ingrese un valor:");
    scanf("%d", &a);
    agregar(fila, a);
}

int primero(Fila* fila)
{
    int resp;
    if(fila->inicio!=NULL)
    {
        resp=verPrimero(fila->inicio);
    }
    return resp;
}

int filaVacia(Fila* fila)
{
    int resp=0;
    if(fila->inicio==NULL)
        resp=1;
    return resp;
}

