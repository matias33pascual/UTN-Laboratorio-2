/// Para pensar en clase

/// SUMATORIA y FACTORIAL

/// FACTORIAL: primera version. Yendo hacia adelante ->
int clase_02_factorial(int numero)
{
    if (numero == 0)
        return 1;

    return _clase_02_factorialAux(1, numero);
}

/// PRIMERA VERSION
int _clase_02_factorialAux(int numeroActual, int numeroFinal)
{
    int resultado;

    if (numeroActual == numeroFinal)
    {
        resultado = 1;
    }
    else
    {
        resultado = numeroActual * _clase_02_factorialAux(++numeroActual, numeroFinal);
    }

    return resultado;
}

/// SEGUNDA VERSION: vamos hasta el final y volvemos <-
int clase_02_factorial2 (int x)
{
    int rta;
    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_02_factorial2(x-1);
    }
    return rta;
}

/// VERSION FINAL
int clase_02_factorial3(int numero)
{
    if(numero == 0)
        return 1;

    else
        return numero *= clase_02_factorial3(--numero);
}

/// SOLUCIONES ---------------------------------------------------------------------------------
int clase_02_sumatoria(int numero)
{
    return _sumatoriaAux(0, numero);
}

/// PRIMERA VERSION
int _sumatoriaAux(int numeroActual, int numeroFinal)
{
    int resultado;

    if (numeroActual == numeroFinal)
    {
        resultado = 0;
    }
    else
    {
        resultado = numeroActual + _sumatoriaAux(++numeroActual, numeroFinal);
    }

    return resultado;
}

/// SEGUNDA VERSION
int _sumatoriaAux2(int valorActual, int numero)
{
    if (valorActual == numero)
        return 0;

    return valorActual + _sumatoriaAux2(++valorActual, numero);
}

/// ---------------------------------------------------------------

/// FACTORIAL: primera version. Yendo hacia adelante ->
int clase_02_factorial(int numero)
{
    if (numero == 0)
        return 1;

    return _clase_02_factorialAux(1, numero);
}

/// PRIMERA VERSION
int _clase_02_factorialAux(int numeroActual, int numeroFinal)
{
    int resultado;

    if (numeroActual == numeroFinal)
    {
        resultado = 1;
    }
    else
    {
        resultado = numeroActual * _clase_02_factorialAux(++numeroActual, numeroFinal);
    }

    return resultado;
}

/// SEGUNDA VERSION: vamos hasta el final y volvemos <-
int clase_02_factorial2 (int x)
{
    int rta;
    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*clase_02_factorial2(x-1);
    }
    return rta;
}

/// VERSION FINAL
int clase_02_factorial3(int numero)
{
    if(numero == 0)
        return 1;

    else
        return numero *= clase_02_factorial3(--numero);
}
