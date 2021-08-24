#include <stdio.h>
#include <stdlib.h>

void cargarArchivo()
{
    int arreglo[] = {10,20,30,40,50,-60,70,80,90};

    FILE* fArchivo = fopen("archivo.bin", "ab");

    if (fArchivo != NULL)
    {
        fwrite(arreglo, sizeof(arreglo), 1, fArchivo);

        fclose(fArchivo);
    }
}

void mostrarArchivo()
{
    FILE* fArchivo = fopen("archivo.bin", "rb");

    int i;
    if (fArchivo != NULL)
    {
        while(fread(&i, sizeof(int), 1, fArchivo) > 0)
        {
            printf("[%i]", i);
        }

        fclose(fArchivo);
    }
}

int encontrarMenor(FILE* fArchivo)
{
    int menor;
    int aux;

    /// solucion trivial
    if(fread(&aux, sizeof(int),1, fArchivo) == 0)
    {
        fseek(fArchivo, sizeof(int) * -1, SEEK_END);
        fread(&menor, sizeof(int),1, fArchivo);
    }
    else
    {
        menor = encontrarMenor(fArchivo);

        fread(&aux, sizeof(int), 1, fArchivo);

        if(aux < menor)
        {
            menor = aux;
        }
    }

    return menor;
}
