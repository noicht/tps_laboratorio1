#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#define MAX 50

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* this;

	int cant = 0;
	int i = 0;

	char varId[MAX];
	char varNombre[MAX];
	char varHorasTrabajadas[MAX];
	char varSueldo[MAX];


	cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHorasTrabajadas, varSueldo);

	while(!feof(pFile))
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", varId, varNombre, varHorasTrabajadas, varSueldo);

		if(cant == 4)
		{
			this = employee_newParametros(varId, varNombre, varHorasTrabajadas, varSueldo);
			ll_add(pArrayListEmployee, this);
			i++;
		}
		else
		{
			if(feof(pFile))
			{
				printf("--------------------END OF FILE--------------------\n\n");
				system("pause");
				break;

			}
		}
	}

	printf("Data loaded successfully");

    return i;
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
	Employee employee;
	Employee* pEmployee;

	int cant = 0;
	int i = 0;

	cant = fread(&employee, sizeof(Employee),1, pFile);

	while(!feof(pFile))
	{
		pEmployee = employee_new();

		employee_setId(pEmployee, employee.id);
		employee_setNombre(pEmployee, employee.nombre);
		employee_setHorasTrabajadas(pEmployee, employee.horasTrabajadas);
		employee_setSueldo(pEmployee, employee.sueldo);

		if(cant == 1)
		{
			ll_add(pArrayListEmployee, pEmployee);
			fread(&employee, sizeof(Employee),1, pFile);
			i++;



		}
		else
		{
			if(!feof(pFile))
			{
				printf("\n\nERROR: There was a problem at the end of the file");
				system("pause");
				break;


			}
			else
			{
				printf("\n--------------------END OF FILE--------------------\n");

			}
		}



	}

	printf("Data loaded successfully");
	fclose(pFile);

    return i;
}
