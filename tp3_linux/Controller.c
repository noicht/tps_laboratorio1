#include "toolboxTP3.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int rtn = 1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
			{
				fclose(pFile);
				rtn = 0;
			}
		}
	}

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int rtn = 1;

	FILE* pFile = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
			{
				fclose(pFile);
				rtn = 0;
			}
		}
	}

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* auxUltId)
{
	int rtn = 1;

	Employee* this;

	char auxNombre[MAX_LONG];
	char auxHorasTrabajadas[MAX_LONG];
	char auxSueldo[MAX_LONG];

	if(pArrayListEmployee != NULL)
	{
		getString("Ingrese nombre y apellido del empleado: ", "ERROR, reingrese: ", auxNombre, MAX_LONG);
		getString("Ingrese horas trabajadas del empleado: ", "ERROR, reingrese: ", auxHorasTrabajadas, MAX_LONG);
		getString("Ingrese sueldo del empleado: ", "ERROR, reingrese: ", auxSueldo, MAX_LONG);


		this = employee_newParametros((*auxUltId)+1, auxNombre, auxHorasTrabajadas, auxSueldo);

		if(this != NULL)
		{
			*auxUltId += 1;

			rtn = ll_add(pArrayListEmployee, this);
		}

	}



    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 1;

	Employee* this;

	int idEmpleado;
	char auxNombre[MAX_LONG];
	int auxHorasTrabajadas;
	int auxSueldo;


	int opcion;


	rtn = controller_ListEmployee(pArrayListEmployee);

	if(rtn == 0)
	{
		idEmpleado = getInt("Ingrese ID del empleado a modificar: ", "ERROR, reingrese: ");
		this = (Employee*) ll_get(pArrayListEmployee, (idEmpleado) - 1);

		if(this != NULL)
		{
			printf("\n\nQue desea modificar?\n\n");
			printf("1. Nombre\n");
			printf("2. Horas trabajadas\n");
			printf("3. Sueldo\n");
			printf("4. Salir");

			opcion = getIntRange("Ingrese opcion: ", "ERROR, reingrese (rango: 1 - 4)", 1, 4);

			switch(opcion)
			{
			case 1:
				getString("Ingrese nombre y apellido del empleado: ", "ERROR, reingrese: ", auxNombre, MAX_LONG);
				rtn = employee_setNombre(this, auxNombre);
				break;
			case 2:
				auxHorasTrabajadas = getIntRange("Ingrese horas trabajadas del empleado: ", "ERROR, reingrese: ", 1, 1000);
				rtn = employee_setHorasTrabajadas(this, auxHorasTrabajadas);
				break;
			case 3:
				auxSueldo = getIntRange("Ingrese sueldo del empleado: ", "ERROR, reingrese: ", 1, 1000000);
				rtn = employee_setSueldo(this, auxSueldo);
				break;
			case 4:
				printf("\n\nSaliendo");
				break;
			}

		}

	}






    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 1;

	Employee* this;
	int idEmpleado;
	int contValidador = 0;

	do
	{
		rtn = controller_ListEmployee(pArrayListEmployee);
		idEmpleado = getInt("Ingrese el ID del empleado a eliminar: ", "ERROR, reingrese: ");
		this = (Employee*) ll_get(pArrayListEmployee, (idEmpleado)-1);

		if(this != NULL)
		{
			break;
		}
		else
		{
			printf("ID no existente, verifique el listado impreso en pantalla y vuelva a intentarlo. \n\n");
			contValidador++;

		}



	}while(contValidador < 3);

	if(contValidador == 3)
	{
		printf("Se ha excedido la cantidad de intentos por defecto (3)");

	}

	if(this != NULL)
	{
		rtn = employee_PrintEmployee(this);

		if (rtn == 0)
		{
			rtn = ll_remove(pArrayListEmployee, (idEmpleado) - 1);
		}

	}



    return rtn;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	int rtn = 1;

	int isEmpty = ll_isEmpty(pArrayListEmployee);

	if(pArrayListEmployee != NULL && isEmpty == 1)
	{
		int len = ll_len(pArrayListEmployee);
		Employee* auxThis;


		printf("******************************************************\n");
		printf("%4s  %15s  %15s  %7s \n", "Id", "Nombre", "Horas Trabajadas", "Sueldo");
		printf("******************************************************\n");

		for(int i = 0; i < len; i++)
		{
			auxThis = (Employee*) ll_get(pArrayListEmployee, i);

			if(auxThis != NULL)
			{
				rtn = employee_PrintEmployee(auxThis);
			}
		}

	}
	else
	{
		if(isEmpty == 0)
		{
			printf("\n\n\t\t--La lista esta vacia--\n\n");

		}
	}


    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 1;
	int orden;

	if(pArrayListEmployee != NULL && (!ll_isEmpty(pArrayListEmployee)))
	{
		printf("Ordenar de manera:\n\n");
		printf("1. Ascendente\n");
		printf("2. Descendente\n\n");
		orden = getIntRange("Ingrese opcion: ", "ERROR, orden invalido, reingrese: ", 1, 2);

		if(orden == 1)
		{
			ll_sort(pArrayListEmployee, employee_sortById, 1);
		}
		else
		{
			ll_sort(pArrayListEmployee, employee_sortById, 0);
		}

	}


    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int len;
	int temp;

	int auxId;
	char auxNombre[MAX_LONG];
	int auxHorasTrabajadas;
	int auxSueldo;

	FILE* pArch;
	Employee* auxThis;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pArch = fopen(path, "w");

		if(pArch != NULL)
		{
			len = ll_len(pArrayListEmployee);
			fprintf(pArch,"id,nombre,horasTrabajadas,Sueldo\n");

			for(int i = 0; i < len; i++)
			{
				auxThis = (Employee*)ll_get(pArrayListEmployee, i);

                temp = employee_getId(auxThis, &auxId);
                temp = employee_getNombre(auxThis, auxNombre);
                temp = employee_getHorasTrabajadas(auxThis, &auxHorasTrabajadas);
                temp = employee_getSueldo(auxThis, &auxSueldo);

                fprintf(pArch,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
			}
			fclose(pArch);
		}
	}

    return temp;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

	int rtn = 1;

	int len;

	FILE* pArch;
	Employee* auxThis;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pArch = fopen(path, "wb");
		if(pArch != NULL)
		{
			len = ll_len(pArrayListEmployee);
			for(int i = 0; i < len; i++)
			{
					auxThis = (Employee*) ll_get(pArrayListEmployee,i);

					if(auxThis != NULL)
					{
						fwrite(auxThis,sizeof(Employee),1,pArch);
					}
			}
			fclose(pArch);
			rtn = 0;
		}
	}

	return rtn;
}

int controller_getLastId(char path[])
{
	int id = 0;
	FILE* pArch = fopen(path, "rb");

	if(pArch != NULL)
	{
		fread(&id, sizeof(int), 1, pArch);

	}
	fclose(pArch);

	return id;
}

int controller_setLastId(char path[], int ultId)
{
	int rtn = 1;

	FILE* pArch = fopen(path, "wb");

	if(pArch != NULL)
	{
		fwrite(&ultId, sizeof(int), 1, pArch);
		rtn = 0;
	}
	fclose(pArch);

	return rtn;
}









