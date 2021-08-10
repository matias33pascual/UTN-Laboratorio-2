/**

CLASE 1:
        * REVISION DE CONTENIDOS DE LABORATORIO 1
        * FUNCIONES y MODULARIZACION
        * VARIABLES LOCALES A LA FUNCION
        * DIAGRAMA DE ESTRUCTURAS: cohesion y acoplamiento
        * PUNTEROS
        * PUNTEROS DOBLES
        * ESTRUCTURAS DE DATOS ESTATICAS y DINAMICAS
        * ARREGLOS PARALEOS
        * AREGLOS DE REGISTROS
        * ALGORITMOS DE ORDENACION:
            . busqueda de un elemento
            . busqueda del mayor
            . busqueda del menor
            . ordenamiento por seleccion
            . ordenamiento por insercion
*/

/// ------------------------------------------------------------

#include <time.h>

//{ para utilizar en la explicacion de acoplamiento
int variableGlobal = 10;
//}

/// ------------------------------------------------------------

/** REPASO DE FUNCIONES */

//{ TIPOS DE FUNCIONES

/// sin retorno y sin parametros
void funcionSaludar()
{
    printf("hola mundo! \n");
}

/// con retorno y sin parametros
int funcionDevolverRandom()
{
    srand(time(NULL));

    int random = rand() % 10;

    return random;
}

/// sin retorno y con parametros
void funcionMostrarSuma(int numeroA, int numeroB)
{
    int resultado = numeroA + numeroB;

    printf("%d + %d = %d", numeroA, numeroB, resultado);
}

/// con retorno y con parametros
int funcionDevolverSuma(int numeroA, int numeroB)
{
    return numeroA + numeroB;
}
//}

/// ------------------------------------------------------------

/** REPASO DE PUNTEROS */
void repasandoPunteros()
{

/// EJEMPLOS DEL USO DE PUNTEROS

    int variableA = 20; /// declaro una variable
    int* puntero;       /// declaro un puntero

    puntero = &variableA;   /// le asigno a puntero la direccion de memoria de
    /// la variableA

    /// mostrando por pantalla...
    printf("&puntero: %X \n", &puntero); /// direccion de memoria de puntero

    printf("valor de puntero: %X \n", puntero); /// valor del puntero

    printf("&variableA: %X \n", &variableA); /// direccion de memoria de variableA

    printf("valor variableA: %d \n", variableA); /// valor de la variableA

    /// valor que se encuentra en la direccion a la que apunta el puntero
    printf("valor en la direccion a la que apunta puntero: %d", *puntero);

/// ------------------------------------------------------------
}

/** FUNCIONES y PUNTEROS */
void cambiandoValor(int* variable)
{
    *variable = 10;
}

/// PUNTERO DOBLE
void mostrandoDatos(int* variable)
{
    printf("&variable: %X \n", &variable); /// direccion de memoria de variableA

    printf("valor variable: %d \n\n", variable); /// valor de la variableA

    /// valor que se encuentra en la direccion a la que apunta la variable
    printf("valor en la direccion a la que apunta variable: %d \n", *variable);
}
