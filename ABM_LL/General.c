#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include <string.h>
#define MAX_LONG 100

//isdigit(char*);


// 1 si es int, 0 si no es int
int validate_forInts(char *buffer)
{
    int return_ = 1;

    if(strlen(buffer) > 0)
    {
        for(int i = 0; i < strlen(buffer); i++) //recorro buffer
        {
            if(buffer[0] == '-')
            {
                continue;
            }
            else
            {


                if(isdigit(buffer[i]) == 0) //valido el dato ingresado al buffer
                {
                    //ES CUALQUIER COSA MENOS UN NUMERO
                    return_ = 0;
                    break;
                }
            }
        }

    }
    else
    {
        //SI la cadena viene vacia...
        return_ = 0;
    }

    return return_;
}

float validate_forFloats(char* buffer)
{
    int return_ = 1;
    int isNegative = 0;
    int countSigno = 0;
    if(strlen(buffer) > 0)
    {
        for(int i = 0; i < strlen(buffer); i++) //recorro buffer
        {
            if(buffer[0] == '-' && isNegative == 0)
            {
                isNegative = 1;
            }
            if(i > 0 || isNegative == 1)
            {
                if(buffer[i] == '.' || buffer[i] == ',') //valido el dato ingresado al buffer
                {
                    countSigno++;

                }
                else
                {
                    if(isdigit(buffer[i]) == 0)
                    {
                        return_ = 0;
                        break;
                    }
                }
            }
        }
        if(countSigno > 1)
        {
            return_ = 0;
        }

    }
    else
    {
        //SI la cadena viene vacia...
        return_ = 0;
    }

    return return_;

}


int getInt(char *MSG, char* ERROR_MSG)
{
    int return_;
    char buffer[MAX_LONG];
    printf("%s", MSG);
    fflush(stdin);
    scanf("%[^\n]", buffer);

    while(validate_forInts(buffer) == 0)
    {
        //Mientras este aca, dato incorrecto
        printf("%s", ERROR_MSG);
        fflush(stdin);
        scanf("%[^\n]", buffer);

    }
    return_ = atoi(buffer);
    //gets();
    return return_;
}

float getFloat(char MSG[], char ERROR_MSG[])
{
    float rtn;
    char temp[MAX_LONG];
    printf("%s", MSG);
    fflush(stdin);
    //__fpurge(stdin);
    scanf("%[^\n]", temp);

    while(validate_forFloats(temp) == 0)
    {
        printf("%s", ERROR_MSG);
        fflush(stdin);
        //__fpurge(stdin);
        scanf("%[^\n]", temp);
    }
    rtn = atof(temp);
    return rtn;

}
int getIntRange(char* MSG, char* ERROR_MSG, int MIN, int MAX)
{
    int return_;

    return_=getInt(MSG, ERROR_MSG);

    while(return_ < MIN || return_ > MAX)
    {
        printf("ERROR: fuera de rango --> [MIN] = %d [MAX] = %d\n", MIN,MAX);
        return_=getInt(MSG, ERROR_MSG);
    }

    return return_;

}



void getString(char MSG[], char ERROR_MSG[], char auxString[], int tam)
{
    char temp[MAX_LONG];
    printf("%s", MSG);
    fflush(stdin);
    scanf("%[^\n]", temp);

    while(strlen(temp) > tam || strlen(temp) == 0)
    {
        printf("ERROR, Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n", tam);
        printf("%s", ERROR_MSG);
        fflush(stdin);
        scanf("%[^\n]", temp);
    }
    strcpy(auxString, temp);

}

float getFloatRange(char MSG[], char ERROR_MSG[], float MIN, float MAX)
{
    float rtn;
    rtn = getFloat(MSG, ERROR_MSG);


    while(rtn < MIN || rtn > MAX)
    {
        printf("ERROR: fuera de rango --> [MIN] = %f [MAX] = %f\n", MIN,MAX);
        rtn = getFloat(MSG, ERROR_MSG);
    }
    return rtn;

}



/*
void prueba(void)
{
    printf("Probando");

}
*/
