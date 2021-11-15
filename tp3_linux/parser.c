#include "toolboxTP3.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#define MAX_LONG 256

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 1;

	Employee* auxThis;

    char id[MAX_LONG];
    char nombre[MAX_LONG];
    char horasTrabajadas[MAX_LONG];
    char sueldo[MAX_LONG];

    int readEncabezados;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	readEncabezados = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); // lectura de encabezados del CSV
    	do
    	{
			if(	readEncabezados == 4 )
			{
				auxThis = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(auxThis != NULL)
				{
					ll_add(pArrayListEmployee, auxThis); // agrego auxThis en la ll
					rtn = 0;
				}

			}
    	} while(!feof(pFile));
    }



    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 1;

	Employee* auxThis;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	do
    	{
    		auxThis = employee_new();

    		if(auxThis != NULL)
    		{
    			rtn = -1;

    			if( fread(auxThis, sizeof(Employee), 1, pFile) )
    			{
    				ll_add(pArrayListEmployee, auxThis);
    				rtn = 0;
    			}
    		}

    	} while(!feof(pFile));
    }



    return rtn;
}
