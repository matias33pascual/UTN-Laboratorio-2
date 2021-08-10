void punteroDoble()
{
    int variableA = 10;
    int* pVariableA = &variableA;
    int** ppVariableA = &pVariableA;

    printf("&variable A: %X \n", &variableA);
    printf("valor de variable A: %i \n\n", variableA);

    printf("&puntero a variable A: %X \n", &pVariableA);
    printf("valor de puntero de variable A: %X \n\n", pVariableA);
    printf("valor almacenado donde apunta puntero A: %i \n\n", *pVariableA);

    printf("PUNTERO DOBLE \n\n");

    // para hacer y pensar con la clase
}
