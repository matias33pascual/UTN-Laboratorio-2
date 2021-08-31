#include "persona.h"

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

persona cargarPersona()
{
    persona aux;

    fflush(stdin);
    printf("Ingrese nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("Ingrese edad:");
    scanf("%d", &aux.edad);

    return aux;
}
