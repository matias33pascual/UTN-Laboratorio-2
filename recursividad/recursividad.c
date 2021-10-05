/// i : posicion actual en el arreglo. Index
/// PRIMERA VERSION
void clase_02_mostrarArreglo(int arreglo[], int validos, int i)
{
    /// solucion trivial
    if (i == validos - 1)
        printf("[%i]", arreglo[i]);

    else
    {
        printf("[%i]", arreglo[i]);

        /// acercamiento a la condicion de corte
        i++;

        /// llamado recursivo
        clase_02_mostrarArreglo(arreglo, validos, i);
    }
}

/// VERSIONES MAS ELEGANTES
void clase_02_mostrarArreglo2(int arreglo[], int validos, int i)
{
    if (i != validos)
    {
        /// expresion de la solucion trivial
        printf("[%i]", arreglo[i++]);
        clase_02_mostrarArreglo2(arreglo, validos, i);
    }
}

void clase_02_mostrarArreglo3(int arreglo[], int validos, int i)
{
    if(i < validos)
    {
        printf("[%i]", arreglo[i]);
        clase_02_mostrarArreglo3(arreglo, validos, ++i); /// CUIDADO CON ESTO: se debe pasar ++i
        /**
            ¿ Por que ++i y no i++ ?
            Porque al pasar ++i, primero se suma i y luego se pasa.
        */
    }
}
