/*
 ============================================================================
 Name        : tp2_laboratorio1.c
 Author      : Martin Cabrera
 Version     : 1.0
 Copyright   : Open-source
 Description : ABM
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#define CANT_EMPLEADOS 1000

int main()
{
	setbuf(stdout, NULL);

    char seguir = 's';
    int orderer;
    eEmployee employees[CANT_EMPLEADOS];

    int index;
    int idAux;
    char nameAux[51];
    char lastnameAux[51];
    float salaryAux;
    int sectorAux;

    int emplCount = 0;

    initEmployees(employees, CANT_EMPLEADOS);

    do
        {
        switch(menu())
        {
        case 1:
            index = freeSpace(employees, CANT_EMPLEADOS);
            if(index == -1)
            {
                printf("ERROR: Sin espacio \n\n");
            }
            else
                {
                    idAux = index + 1;
                    printf("-- ID de empleado %d --\n", idAux);

                    getValidString("Ingrese nombre: ", "Valor incorrecto.", nameAux);
                    getValidString("Ingrese apellido: ", "Valor incorrecto.", lastnameAux);
                    salaryAux =getValidFloat("Ingrese salario: ","Valor incorrecto", 10000, 1000000);
                    printSector();
                    sectorAux =getValidInt("Ingrese sector: ","Valor incorrecto", 0, 5);

                if(addEmployee(employees, CANT_EMPLEADOS, idAux, nameAux, lastnameAux, salaryAux, sectorAux) == -1)
                    {
                    printf("ERROR: Contacte a soporte tecnico\n");
                }
                else
                {
                    emplCount++;
                }
            }
            break;
        case 2:
            if(emplCount < 1)
            {
                printf("Sin empleados que editar.\n");
            }
            else
                {
                idAux= getValidInt("Ingrese ID: ", "ID incorrecto.", 0, 1000);
                if(editEmployeeById(employees, CANT_EMPLEADOS, idAux)==-1)
                {
                    printf("ERROR: Contacte a soporte tecnico\n");
                }
            }
            break;
        case 3:
            if(emplCount < 1)
            {
                printf("Sin empleados que borrar.\n");
            }
            else
            {
                idAux= getValidInt("Ingrese ID: ", "ID incorrecto.", 0, 1000);
                if(removeEmployee(employees, CANT_EMPLEADOS, idAux)==-1)
                {
                    printf("ERROR: Contacte a soporte tecnico\n");
                }
                else
                {
                    emplCount--;
                }
            }
            break;
        case 4:
            if(emplCount < 1)
            {
                printf("Sin empleados que mostrar.\n");
            }
            else
            {
                orderer = getValidInt("Ordenar a los empleados de manera\n 1_Ascendente, 2_Descendente: ", "Valor incorrecto.", 1, 2);
                if(sortEmployees(employees, CANT_EMPLEADOS, orderer)==-1)
                {
                    printf("ERROR: Contacte a soporte tecnico\n");
                }
                /*else
                {
                    if(aboveAverageSalary(employees, CANT_EMPLEADOS)==-1)
                    {
                    printf("ERROR: Contacte a soporte tecnico\n");
                    }
                }*/
            }
            break;
        case 5:
            seguir = 'n';
            printf("\n*******Saliendo*******\n");
            break;
        case 0:
            hardcodeo(employees);
            emplCount = emplCount + 7;
            break;
        default:
            printf("Opcion incorrecta, ingrese numero entre 0 y 5. \n\n");
            break;
        }
    system("pause");
    } while(seguir == 's');
    return 0;
}

