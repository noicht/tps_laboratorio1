/*
 ============================================================================
 Name        : CalculadoraExperimental.c
 Author      : Martin Cabrera
 Version     : 1.0
 Copyright   : Open Source
 Description : Calculadora Experimental
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcionesCalcu.h"

int main()
{

    setbuf(stdout, NULL);

    float numero1;
    float numero2;

    int opcion = 0;

    float resultadoSuma;
    float resultadoResta;
    float resultadoDiv;
    float resultadoMult;

    long resultFact1;
    long resultFact2;

    //flags

    int flagNum1 = 0;
    int flagNum2 = 0;
    int flagCalulos = 0;
    int divX0 = 0; // division por 0

    do
    {

        printf("Calculadora experimental version 1.0 \n\n");

        printf("1. Ingresar primer digito: \n");
        printf("2. Ingresar segundo digito: \n");
        printf("3. Calcular operaciones: \n");
        printf("4. Imprimir resultados: \n");
        printf("5. Salir de la aplicacion: \n\n");

        printf("Seleccione una opcion: ");
        fflush(stdout);
        scanf("%d", &opcion);

        system("cls");

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el primer digito: ");
            fflush(stdout);
            scanf("%f", &numero1);
            flagNum1 = 1;
            break;

        case 2:
            printf("\nIngrese el segundo digito: ");
            fflush(stdout);
            scanf("%f", &numero2);
            flagNum2 = 1;
            break;

        case 3:

            if (flagNum1 == 0 || flagNum2 == 0)
            {
                printf("\nERROR: No has introducido ambos digitos\n");

            }
            else
            {
                resultadoSuma = suma(numero1,numero2);
                resultadoResta = resta(numero1,numero2);
                resultadoMult = multiplicacion(numero1,numero2);
                resultadoDiv = division(numero1,numero2);
                resultFact1 = factorial(numero1);
                resultFact2 = factorial(numero2);

                flagCalulos = 1;

                if(numero2 == 0)
                {
                    divX0 = 1; // se tiene en cuenta cuando el segundo digito es 0 por si se realiza una division por 0
                }
                else
                {
                    divX0 = 0;
                }

                printf("\n\nOperaciones realizadas, volviendo al menu\n");






            }
            system("pause");
            system("cls");


            break;


        case 4:
            if(flagNum1 == 0 || flagNum2 == 0)
            {
                printf("\n\nERROR: No has introducido ambos digitos\n");
            }
            else
            {
                if(flagCalulos == 0)
                {
                    printf("\n\nERROR: No se han realizados los calculos\n");
                }
                else
                {
                    printf("\nSuma de %f y %f : %f", numero1,numero2,resultadoSuma);

                    printf("\nResta de %f y %f : %f", numero1,numero2,resultadoResta);

                    printf("\nMultiplicacion de %f y %f : %f", numero1,numero2,resultadoMult);

                    if(divX0 == 1)
                    {
                        printf("\nError matematico: division por 0 indefinida\n");

                    }
                    else
                    {
                        printf("\nDivision de %f y %f : %f", numero1,numero2,resultadoDiv);

                    }

                    if(numero1>=0)
                    {
                        printf("\nFactorial de %.0f : %ld ", numero1, resultFact1);
                    }
                    else
                    {
                        printf("\nLa operacion factorial solo funciona en numeros naturales incluido el 0");

                    }

                    if(numero2>=0)
                    {
                        printf("\nFactorial de %.0f : %ld ", numero2, resultFact2);

                    }
                    else
                    {
                        printf("\nLa operacion factorial solo funciona en numeros naturales incluido el 0\n");
                    }

                    //printf("\nPresione enter para reiniciar la calculadora\n");

                    numero1=0;
                    numero2=0;
                    flagNum1=0;
                    flagNum2=0;


                }


            }
            system("pause");
            system("cls");
            break;

        case 5:
            printf("Saliendo, gracias por utilizarme!");
            break;

        default:
            printf("\nOpcion invalida, seleccione una opcion correcta\n");
            system("pause");





        }


    }while(opcion != 5);




    return 0;

}
