#include "utilidades.h"
#include "lista.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stNotaAlumno n){
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->n = n;
    aux->siguiente = NULL;
    return aux;
}

nodo* agregarPpio(nodo* lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;

    return lista;
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo* buscarNodo(nodo* lista, int nota){
    nodo* seg;
    seg = lista;

    while ((seg != NULL) && (seg->n.nota!=nota)){
        seg=seg->siguiente;
    }

    return seg;
}

nodo* agregarFinal(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL){
        lista = nuevoNodo;
    }
    else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo* borrarNodoBuscado(nodo* lista, int nota){
    nodo* seg;
    nodo* ante;
    if((lista != NULL) && (lista->n.nota==nota)){
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else{
        seg = lista;
        while((seg != NULL) && (seg->n.nota!=nota)){
            ante = seg;
            seg = seg->siguiente;
        }

        if(seg!=NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }
    else{

        if(nuevoNodo->n.nota < lista->n.nota){
            lista = agregarPpio(lista, nuevoNodo);
        }
        else{
            nodo* ante = lista;
            nodo* seg = lista;
            while(seg != NULL && nuevoNodo->n.nota > seg->n.nota){
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }
    return lista;
}

nodo* borrarTodaLaLista(nodo* lista){
    nodo* proximo;
    nodo* seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo* borrarPrimerNodo(nodo* lista){
    nodo* aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

nodo* borrarUltimoNodo(nodo* lista){
    nodo* aux=lista;
    nodo* ante;
    while(aux->siguiente!=NULL){
        ante=aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}
/// Suma notas de manera iterativa
int sumarNotasLista(nodo* lista){
    int suma = 0;
    nodo* seg = lista;
    while (seg)
    {
        suma = suma + seg->n.nota;
        seg = seg->siguiente;
    }
    return suma;
}
/// Suma notas de manera recursiva
int sumarNotasListaRecursivo(nodo* lista){
    int suma=0;
    if(lista){
        suma=lista->n.nota + sumarNotasListaRecursivo(lista->siguiente);
    }
    return suma;
}
/// Suma notas de manera recursiva con un operador ternario
int sumarNotasListaRecursivoTernario(nodo* lista){
    return (lista)?lista->n.nota + sumarNotasListaRecursivoTernario(lista->siguiente):0;
}

void mostrarUnNodo(nodo* aux){
   mostrarUnaNota(aux->n);
}

void mostrarUnaNota(stNotaAlumno n){
    printf("\n Legajo.........: %d ",n.legajo);
    printf("\n Alumno.........: %s ",n.apeNom);
    printf("\n Nota...........: %d \n",n.nota);
    //replicante('_',50);
}

void recorrerYmostrar(nodo* lista){
    nodo* aux=lista;
    while(aux!=NULL){
        mostrarUnNodo(aux);
        puts("\n");
        aux=aux->siguiente;
    }
}
/// Cuenta la cantidad de alumnos de una lisa de manera recursiva con un operador ternario
int cuentaAlumnos(nodo* lista){
    return (lista)?1+cuentaAlumnos(lista->siguiente):0;
}
