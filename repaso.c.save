/** REPASO DE FUNCIONES */

//{ TIPOS DE FUNCIONES
/// sin retorno y sin parametros
void saludar()
{
    printf("hola mundo! \n");
}

/// con retorno y sin parametros
int devolverRandom()
{
    srand(time(NULL));

    int random = rand() % 10;

    return random;
}

/// sin retorno y con parametros
void mostrarSuma(int numeroA, int numeroB)
{
    int resultado = numeroA + numeroB;

    printf("%d + %d = %d", numeroA, numeroB, resultado);
}

/// con retorno y con parametros
int devolverSuma(int numeroA, int numeroB)
{
   return numeroA + numeroB;
}
//}

/// ------------------------------------------------------------

/** REPASO DE PUNTEROS */

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

/** FUNCIONES y PUNTEROS */
void cambiarValor(int* variable)
{
    *variable = 10;
}

void mostrarDatos(int* variable)
{
    int* puntero = variable;

    printf("&puntero: %X \n", &puntero); /// direccion de memoria de puntero

    printf("valor de puntero: %X \n", puntero); /// valor del puntero

    printf("&variableA: %X \n", &variable); /// direccion de memoria de variableA

    printf("valor variableA: %d \n", variable); /// valor de la variableA

    /// valor que se encuentra en la direccion a la que apunta el puntero
    printf("valor en la direccion a la que apunta puntero: %d", *puntero);

    /// valor que se encuentra en la direccion a la que apunta la variable
    printf("valor en la direccion a la que apunta puntero: %d", *variable);
}













