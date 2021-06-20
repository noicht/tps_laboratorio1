#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef GENERAL_H_
#define GENERAL_H_
// #define MAX 100

//CABECERAS DE FUNCIONES
//VALIDACIONES

int validate_forInts(char *buffer);
float validate_forFloats(char *buffer);

//GET - INICIO

int getInt(char *MSG, char* ERROR_MSG);
int getIntRange(char* MSG, char* ERROR_MSG, int MIN, int MAX);

float getFloat(char MSG[], char ERROR_MSG[]);
float getFloatRange(char MSG[], char ERROR_MSG[], float MIN, float MAX);

void getString(char MSG[], char ERROR_MSG[], char auxString[], int tam);

//GET - FINAL




#endif /*GENERAL_H_*/


