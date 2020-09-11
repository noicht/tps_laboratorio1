#include <stdio.h>
#include <stdlib.h>

//funciones de las operaciones de la calculadora, se agregaran mas a futuro como proyecto propio

float suma(float num1, float num2)
{
    float resultadoSum;
    resultadoSum = num1 + num2;
    return resultadoSum;
}

float resta(float num1, float num2)
{
    float resultadoRest;
    resultadoRest = num1 - num2;
    return resultadoRest;
}

float division(float num1, float num2)
{
    float resultadoDivi;
    resultadoDivi = num1/num2;
    return resultadoDivi;
}

float multiplicacion(float num1, float num2)
{
    float resultadoMulti;
    resultadoMulti = num1*num2;
    return resultadoMulti;
}

int factorial(float num1)
{
    int resultadoFact = 1;
    int i;
    for (i = num1; i > 1; i--)
    {
        resultadoFact = resultadoFact * i;
    }
    return resultadoFact;
}
