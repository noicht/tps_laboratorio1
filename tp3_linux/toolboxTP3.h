/*
 * toolboxTP3.h
 *
 *  Created on: 8 nov. 2021
 *      Author: nodus
 */

#ifndef TOOLBOXTP3_H_
#define TOOLBOXTP3_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>

#define MAX_LONG 256
#define MAX_PEDIDOS 1000
#define VACIO 0
#define OCUPADO 1

// #define MAX 100

//CABECERAS DE FUNCIONES
//VALIDACIONES - INICIO

int validate_forInts(char *buffer);
float validate_forFloats(char *buffer);

//VALIDACIONES - FINAL


//GET - INICIO

int getInt(char *MSG, char* ERROR_MSG);
int getIntRange(char* MSG, char* ERROR_MSG, int MIN, int MAX);

float getFloat(char MSG[], char ERROR_MSG[]);
float getFloatRange(char MSG[], char ERROR_MSG[], float MIN, float MAX);

void getString(char MSG[], char ERROR_MSG[], char auxString[], int tam);

//GET - FINAL





#endif /* TOOLBOXTP3_H_ */
