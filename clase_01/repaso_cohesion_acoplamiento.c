#include <stdio.h>

/// EJEMPLOS DE COHESION FUERTE
int sumarNumeros(int primerNumero, int segundoNumero)
{
    return primerNumero + segundoNumero;
}

/// EJEMPLOS DE COHESION DEBIL
/**
    Si la funcion dice que suma dos numeros,
    no deberia borrar la pantalla,
    luego cambiar el color y despues decirme que
    presione una tecla para continuar.
    Deberia sumar numeros y devolvere el resultado
*/
void sumarNumeros2(int primerNumero, int segundoNumero)
{
    system("cls");
    system("color 1f");

    int resultado = primerNumero + segundoNumero;

    printf("la suma es: %d \n\n", resultado);

    system("pause");
}

/**
    La siguiente funcion calcula la suma de muchos numeros, pero si quisiera cambiar
    la forma en que se comunica con el usuario (por ejemplo si fuera para usuarios en Francia),
    tendria que modificar la funcion para escribir todos los printf en Frances.
    Si la funcion dice que suma muchos numeros, lo correcto seria que hiciera
    solo eso. Dejando la interaccion con el usuario en otra funcion o en el main.
*/
int sumarMuchosNumeros()
{
    int cantidadNumeros = 0;
    int numero = 0;
    int total = 0;

    printf("ingrese la cantidad de numeros que desea sumar \n");

    fflush(stdin);
    scanf("%d", &cantidadNumeros);

    for(int i = 0; i < cantidadNumeros; i++)
    {
        printf("ingrese un numero y presione ENTER\n");

        fflush(stdin);
        scanf("%d", &numero);

        total += numero;

        printf("\n");
    }

    return total;
}

/**
    Acoplamiento:
        Medida de interacción de los módulos
        que constituyen un programa.
*/

// EJEMPLOS

//{ acoplamiento de datos
void cargarNombreApellido(char* nombre, char* apellido)
{
    cargarNombre(nombre);

    printf("\n");

    cargarApellido(apellido);
}

void cargarNombre(char* nombre)
{
    printf("ingrese su nombre \n");

    fflush(stdin);
    scanf("%s", nombre);
}

void cargarApellido(char* apellido)
{
    printf("ingrese su apellido \n");

    fflush(stdin);
    scanf("%s", apellido);
}
//}

//{ acomplamiento de control
int cargarConControlDeCarga(char* nombre, char* apellido, int controlDeCarga)
{
    /// utilizamos un flag para saber si hubo un error
    int flag = 0;

    switch(controlDeCarga)
    {
    case -1:
        cargarNombre(nombre);
        break;
    case 0:
        cargarNombre(nombre);
        cargarApellido(apellido);
        break;
    case 1:
        cargarApellido(nombre);
        break;
    default:
        /// explicamos al usuario el uso correcto de la funcion
        printf("Error en funcion \"acoplamiento de control\" \n");
        printf("\nControl de carga invalido: \n");
        printf("\tingrese -1 para cargar nombre\n");
        printf("\tingrese 1 para cargar apellido\n");
        printf("\tingrese 0 para cargar ambos\n");

        /// ponemos el flag en 1 porque hubo un error
        flag = 1;
    }

    return flag;
}
//}

//{ acoplamiento externo

/// le decimos al compilador que existe una variable global con este nombre
extern int variableGlobal;

/// explicado en clase
void modificarVariable_1()
{
    variableGlobal = 30;
}

void modificarVariable_2()
{
    variableGlobal = 20;
}

//}
