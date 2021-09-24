#include "../librerias/pila.h"
#include "../librerias/lista.h"

void pasarInformacion_arregloArreglo(int arregloOrigen[], int validos, int arregloDestino[], int dimension)
{
    for(int i = 0; i < validos && i < dimension; i++)
    {
        arregloDestino[i] = arregloOrigen[i];
    }
}

nodo* pasarInformacion_arregloLista(int arreglo[], int validos, nodo* lista)
{
    for(int i = 0; i < validos; i++)
    {
        lista = agregarAlPrincipio(lista, arreglo[i]);
    }

    return lista;
}

void pasarInformacion_arregloArchivo(int arreglo[], int validos, char nombreArchivo[])
{
    FILE* archivo = fopen(nombreArchivo, "wb");

    if(archivo)
    {
        for(int i = 0; i < validos; i++)
        {
            fwrite(arreglo[i], sizeof(int), 1, archivo);
        }

        /// otra forma
        /// fwrite(arreglo, sizeof(arreglo), 1, archivo);

        fclose(archivo);
    }
}

void pasarInformacion_arregloPila(int arreglo[], int validos, Pila* pila)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(pila, arreglo[i]);
    }
}

/// -----------------------------------------------------------

typedef struct
{
    char nombre[30];
    int DNI;
} stPersona;

void pasarInformacion_archivoArreglo(char* nombreArchivo, stPersona arreglo[], int dimension)
{
    FILE* fArchivo = fopen(nombreArchivo, "rb");

    if (fArchivo != NULL)
    {
        stPersona persona;
        int i = 0;

        while(fread(&persona, sizeof(persona), 1, fArchivo) > 0 && i < dimension)
        {
            arreglo[i] = persona;
            i++;

            /// tambien podria haber sido:
            /// arreglo[i++] = persona;
        }

        fclose(fArchivo);
    }
}

/**
    Para el siguiente ejemplo utilizamos como parametro una variable de tipo FILE*

    En el main llamariamos a la funcion de la siguiente manera:

    int main()
    {
        nodo* lista = inicLista();
        FILE* archivo = fopen("archivo.bin", "rb");

        if(arhivo)
        {
            pasarInformacion_archivoLista(archivo, lista);

            fclose(archivo);
        }
    }

*/

nodo* pasarInformacion_archivoLista(FILE* archivo, nodo* lista)
{
    stPersona persona;

    while(fread(&persona, sizeof(persona), 1, archivo) > 0)
    {
        lista = agregarAlFinal(lista, persona);
    }

    return lista;
}

void pasarInformacion_archivoPila(FILE* archivo, Pila* pila)
{
    stPersona persona;

    while(fread(&persona, sizeof(persona), 1, archivo) > 0)
    {
        apilar(pila, persona.DNI);
    }
}
