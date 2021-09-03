#include "../librerias/listaEnlazada.h"
#include "../librerias/persona.h"

#define NOMBRE_ARCHIVO "archivo.bin"

void guardarArchivo()
{
    FILE* fArchivo = fopen(NOMBRE_ARCHIVO, "ab");

    if (fArchivo != NULL)
    {
        /// en total hay 6 personas
        persona personas[] = {
            {"Adrian", 40},
            {"Bernardo", 50},
            {"Carlos", 45},
            {"Daiana", 30},
            {"Estefania", 60},
            {"Franco", 35}
        };

        fwrite(personas, sizeof(personas), 1, fArchivo);

        fclose(fArchivo);
    }
}

nodo* leerArchivo(nodo* lista)
{
    FILE* fArchivo = fopen(NOMBRE_ARCHIVO, "rb");

    if (fArchivo != NULL)
    {
        persona auxPersona;
        nodo* nuevoNodo;

        while(fread(&auxPersona, sizeof(persona), 1, fArchivo) > 0)
        {
            nuevoNodo = crearNodo(auxPersona);
            lista = agregarEnOrden(lista, nuevoNodo);
        }

        fclose(fArchivo);
    }

    return lista;
}

int ejemplo_archivosListaSimple()
{
    //guardarArchivo();

    nodo* lista = inicLista();

    lista = leerArchivo(lista);

    mostrarRecursivo(lista);

    return 0;
}
