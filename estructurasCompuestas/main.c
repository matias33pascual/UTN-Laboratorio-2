#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "utilidades.h"
#include "registroArchivo.c"
#include "lista.h"


typedef struct {
    int idMateria;
    char materia[40];
}stMateria;

typedef struct {
    stMateria m;
    nodo* listaDeNotas;
}stCelda;

int buscaPosMateria(stCelda adl[], stMateria m, int validos);
int agregar(stCelda adl[], stMateria m, int validos);
int alta (stCelda adl[], stMateria m, stNotaAlumno n, int validos);
int archivo2adl(stCelda adl[], int validos, int dim);
void mostrarADL(stCelda adl[], int validos);
void guardarAprobDesaprob(stCelda adl[],int validos);

int main()
{
    //stCelda* adl = (stCelda*) malloc(sizeof(stCelda)*cuentaRegistros(arRegistro,sizeof(stRegistroArchivo)));
    stCelda adl[20];
    int validos=0;
    int dim = 20;
   // generaArchivoRandom(100);
   // mostrarRegistros(arRegistro);
    printf("\nPasando de archivo a ADL\n");
    validos  = archivo2adl(adl,validos,dim);
    printf("\nHello world!\n");
    mostrarADL(adl,validos);
    guardarAprobDesaprob(adl,validos);
    printf("\n <<< Archivo de Aprobados >>> \n");
    printf("\n Total: %d \n",cuentaRegistros(arRegAprob,sizeof(stRegistroArchivo)));
    mostrarRegistros(arRegAprob);
    printf("\n <<< Archivo de Desaprobados >>> \n");
    printf("\n Total: %d \n",cuentaRegistros(arRegDesAp,sizeof(stRegistroArchivo)));
    mostrarRegistros(arRegDesAp);
    return 0;
}


/// busca posicion
int buscaPosMateria(stCelda adl[], stMateria m, int validos){
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta==-1)){
        if(strcmp(adl[i].m.materia, m.materia)==0){
     ///   if(adl[i].m.idMateria == m.idMateria){
            rta=i;
        }
        i++;
    }
    return rta;
}

/// agrega stCelda
int agregar(stCelda adl[], stMateria m, int validos){
    adl[validos].m = m;
    adl[validos].listaDeNotas = inicLista();
    validos++;
    return validos;
}

/// alta en el adl
int alta (stCelda adl[], stMateria m, stNotaAlumno n, int validos){
    nodo* aux = crearNodo(n);
    int pos = buscaPosMateria(adl,m,validos);
    if(pos==-1){
        validos=agregar(adl,m,validos);
        pos=validos-1;
    }
    adl[pos].listaDeNotas=agregarFinal(adl[pos].listaDeNotas, aux);
    return validos;
}
/// Lee el archivo y carga el arreglo de listas
int archivo2adl(stCelda adl[], int validos, int dim){
    FILE* arch=fopen(arRegistro, "rb");
    if(arch){
        stRegistroArchivo rg;
        stMateria m;
        stNotaAlumno n;
        while((fread(&rg,sizeof(stRegistroArchivo),1,arch)>0)&&(validos<dim)){
            m.idMateria=rg.idMateria;
            strcpy(m.materia,rg.materia);
            n.legajo = rg.legajo;
            strcpy(n.apeNom,rg.apeNom);
            n.nota = rg.nota;
            validos = alta(adl,m,n,validos);
        }
        fclose(arch);
    }
    return validos;
}
/// Muestra el arreglo de listas
void mostrarADL(stCelda adl[], int validos){
    printf("\nMostrando el arreglo de listas: \n");
    int i=0;
    while(i<validos){
        printf("\n\nMateria %d: %s",adl[i].m.idMateria, adl[i].m.materia);
        printf("\nListado de alumnos: %d\n",cuentaAlumnos(adl[i].listaDeNotas));
        replicante('-',50);
        recorrerYmostrar(adl[i].listaDeNotas);
        i++;
    }
}
/// Recorre el arreglo de listas y guarda los aprobado en el archivo de aprobados y los desaprobados en el de desaprobados
void guardarAprobDesaprob(stCelda adl[],int validos){
    stRegistroArchivo r;
    for(int i=0;i<validos;i++){
        r.idMateria = adl[i].m.idMateria;
        strcpy(r.materia,adl[i].m.materia);

        nodo * seg=adl[i].listaDeNotas;

        while(seg){
            r.legajo = seg->n.legajo;
            r.nota = seg->n.nota;
            strcpy(r.apeNom,seg->n.apeNom);
            /**
            if(adl[i].seg->n.nota>=6){
                guardaRegistroArchivo(arRegAprob,r);
            }else{
                guardaRegistroArchivo(arRegDesAp,r);
            }
            */
            (seg->n.nota>=6)?guardaRegistroArchivo(arRegAprob,r):guardaRegistroArchivo(arRegDesAp,r);
            seg=seg->siguiente;
        }
    }
}
