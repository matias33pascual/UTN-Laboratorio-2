// funcion promedio recursivo de un arreglo

float clase_03_promedioRecursivo(int A[], int validos, int i)
{
    float prom=0;

    if(i<validos)
    {
        prom = ((float)A[i]/(float)validos)+clase_03_promedioRecursivo(A, validos, i+1);
    }

    return prom;

}

/// 1 Calcular el factorial de un número en forma recursiva
int clase_03_factorial (int x)
{
    int rta;
    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_03_factorial(x-1);
    }
    return rta;
}

///2 Calcular la potencia de un número en forma recursiva
int clase_03_potencia(int x, int factor)
{
    int rta;
    if(factor==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_03_potencia(x,factor-1);
    }
    return rta;
}

int clase_03_menorRecursivo(int A[], int i, int cant)
{
    int m;
    /// cuando llego al final del arreglo, retorno ese valor
    /// para comparar con los de las etapas recursivas anteriores
    if(i==cant)
    {
        m=A[cant-1];
    }
    else
    {
        m=clase_03_menorRecursivo(A, i+1, cant);
        if(m>A[i])
        {
            m = A[i];
        }
    }
    return m;
}













