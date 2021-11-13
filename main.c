#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    El dueño de un almacen nos pide organizar sus productos
    Todos sus productos estan en un archivo
    En el archivo se guardaron los productos de la siguiente manera:
        nombre
        precio
        categoria

    El dueño nos pide que organicemos los productos segun la categoria a la que pertenecen
*/

typedef struct
{
    char nombre[30];
    float precio;
    char categoria[30];

} stProducto;

typedef struct
{
    char nombre[30];
    stProducto arregloProductos[10];
    int validos;

} stCategoria;

#define NOMBRE_ARCHIVO "productos.bin"

int main()
{
    char nombres[10][30] = {
        "bebidas.bin",
        "lacteos.bin",
        "gaseosas.bin",
        "comidas.bin"
    };

    stCategoria categorias[10];
    int validos = 0;

    FILE* fArchivo = fopen(NOMBRE_ARCHIVO, "rb");

    if(fArchivo)
    {
        stProducto producto;

        while(fread(&producto, sizeof(producto), 1, fArchivo) > 0)
        {
            int posicionCategoria = estaCargadaCategoria(producto.categoria, categorias);

            if (posicionCategoria == -1)
            {
                agregarNuevaCategoria(producto.categoria, &validos);
            }

            int validosProducto = agregarProducto(producto, categorias, posicionCategoria);

            categorias[posicionCategoria].validos = validosProducto;
        }

        fclose(fArchivo);
    }

    return 0;
}

int agregarProducto(stProducto producto, stCategoria categorias[10], int posicionCategoria)
{
    int validosProductos = categorias[posicionCategoria].validos;

    categorias[posicionCategoria].arregloProductos[validosProductos] = producto;

    return categorias[posicionCategoria].validos + 1;
}

void agregarNuevaCategoria(char categoria[30], int* validos, stCategoria categorias[10])
{
    strcpy(categorias[*validos].nombre, categoria);

    *validos += 1;
}

int estaCargadaCategoria(char categoria[30], stCategoria categorias[10])
{
    int posicionCategoria = -1;

    int flag = 0;

    int i;
    for(i = 0; i < 10 && flag == 0; i++)
    {
        flag = strcmpi(categorias[i].nombre, categoria);
    }

    if(flag != 0)
    {
        posicionCategoria = i;
    }

    return posicionCategoria;
}
