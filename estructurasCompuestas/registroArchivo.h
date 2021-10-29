#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "utilidades.h"

#define arRegistro "registroArchivo.dat"
#define arRegAprob "registroAprobados.dat"
#define arRegDesAp "registroDesaprobados.dat"

typedef struct {
   int nota;
   int legajo;
   char apeNom[40];
   char materia[40];
   int idMateria;
} stRegistroArchivo;

/*
void ingresarRegistros();
stRegistroArchivo ingresarUnRegistro();
void agregarRegistro(stRegistroArchivo r);
void mostrarUnRegistro(stRegistroArchivo r);
void mostrarRegistros(char archivo[]);
void getNombre(char n[]);
void getApellido(char a[]);
int getMateria(char m[]);
void getApellidoYNombre(char an[]);
int getLegajo();
int getNota();
stRegistroArchivo cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stRegistroArchivo r);
void generaArchivoRandom(int cantidad);
int cuentaRegistros(char nombreArchivo[], int tamStruct);
*/
#endif // REGISTROARCHIVO_H_INCLUDED
