#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "General.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* open_file = fopen(path,"r");

	if(ll_len(pArrayListEmployee) == 0)
	{
		if(open_file == NULL)
		{
			printf("ERROR: file not found");
			system("pause");
		}
		else
		{
			printf("SUCCESS: file opened without errors");

			if(parser_EmployeeFromText(open_file, pArrayListEmployee) == 0)
			{
				fclose(open_file);
				rtn = 1;
			}


			system("pause");

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
	int rtn = -1;
	FILE* open_file = fopen(path, "rb");

	if(ll_len(pArrayListEmployee) == 0)
	{
		if(open_file == NULL)
		{
			printf("ERROR: file not found");
			system("pause");
		}
		else
		{
			printf("SUCCESS: file opened without errors");
			rtn = parser_EmployeeFromBinary(open_file, pArrayListEmployee);
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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* this;
	Employee* auxThis;


	int rtn = -1;
	char idStr[5];
	char nameStr[128];
	char hoursStr[10];
	char salaryStr[10];

	int idAux;
	int hoursAux;
	int salaryAux;
	int flagID = 0;

	if(pArrayListEmployee != NULL)
	{
		this = employee_new();
		do
		{
			idAux = getIntRange("Enter ID: ", "Invalid ID, try again: ", 1, 10000);
			if(ll_len(pArrayListEmployee) > 0)
			{
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					auxThis = (Employee*) ll_get(pArrayListEmployee, i);

					if(idAux == auxThis->id)
					{
						printf("\nERROR: This ID is already assigned to an employee");
						flagID = 0;

					}
					else
					{
						flagID = 1;
					}
				}
			}
			else
			{
				flagID = 1;
			}
		}while(flagID == 0);

		getString("Enter the name of the employee: ", "ERROR: invalid value, try again", nameStr, 128);
		hoursAux = getIntRange("Enter the amount of hours worked: ", "ERROR: invalid value, try again: ", 1, 10);
		salaryAux = getIntRange("Enter the salary of the employee: ", "ERROR: invalid value, try again: ",9000, 9999999);


		itoa(idAux, idStr, 10);
		itoa(hoursAux, hoursStr, 10);
		itoa(salaryAux, salaryStr, 10);

		this = employee_newParametros(idStr, nameStr, hoursStr, salaryStr);
		ll_add(pArrayListEmployee, this);

		rtn = 0;


	}



    return rtn;
}

/** \brief Modificar datos de empleado
 *
d * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* this;

	int id;
	int option;
	char name[100];
	int salary;
	int hoursWorked;

	if(ll_len(pArrayListEmployee) > 0)
	{
		id = getInt("Enter the ID: ", "ERROR: invalid value, try again: ");

		this = ll_get(pArrayListEmployee, (id-1));


		printf("\n\n--------------------MODIFY MENU--------------------\n\n");
		printf("1- Name\n");
		printf("2- Amount of worked hours\n");
		printf("3- Salary\n");
		printf("4- Exit\n");
		option = getIntRange("-Option: ", "ERROR: Invalid option, try again:", 1, 4);

		switch(option)
		{
		case 1:
			getString("Enter name: ", "ERROR: Invalid name, try again: ", name, 128);
			employee_setNombre(this, name);
			printf("SUCCESS: name modified");
			system("pause");
			break;


		case 2:
			hoursWorked = getIntRange("Enter amount of hours worked: ", "ERROR: invalid value,  try again", 1,10);
			employee_setHorasTrabajadas(this, hoursWorked);
			printf("SUCCESS: worked hours modified");
			system("pause");
			break;

		case 3:
			salary = getIntRange("Enter salary: ", "ERROR: invalid value, try again: ",9000, 9999999);
			employee_setSueldo(this, salary);
			printf("SUCCESS: salary modified");
			system("pause");
			break;

		case 4:
			printf("Exiting...");
			break;

		}


	}
	else
	{
		printf("\nERROR: file does not exist");
	}




    return 1;
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
	Employee* this;

	int deleteThis;
	int option;
	int rtn = -1;

	if(ll_len(pArrayListEmployee) > 0)
	{
		deleteThis = getIntRange("Enter ID: ", "ERROR: invalid value, try again: ", 1, 10000);

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			this = ll_get(pArrayListEmployee, i);

			if(this -> id == deleteThis)
			{
				option = getIntRange("Confirm operation? 1-yes, 2-no", "ERROR: invalid value, try again", 1,2);

				if(option == 1)
				{
					this = ll_pop(pArrayListEmployee, i);
					printf("\nSUCCESS: Employee deleted");
					rtn = 0;
					break;
				}
				else
				{
					printf("ERROR: could not delete employee");
					break;
				}


			}
		}

	}
	else
	{
		printf("ERROR: file does not exist");
	}
	system("pause");

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
	Employee* this;
	int rtn = -1;


	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{
    	printf("+************************************************************************+\n");
    	printf("|ID---------NAME---------HOURS---------SALARY");
    	printf("+************************************************************************+\n");

    	for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    	{
    		this = ll_get(pArrayListEmployee, i);

    		if(this != NULL)
    		{
    			printf("%4d%14s\t\t%d\t\t%6d\n", this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    			rtn = 0;
    		}
    	}

	}
	else
	{
		printf("File loaded with 0 employees\n");

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
	//int rtn = -1;
	int option;

    printf("Select sorting type: \n");
    printf("\t1- Id\n");
    printf("\t2- Name\n");
    printf("\t3- Worked hours\n");
    printf("\t4- Salary\n");
    option = getIntRange("Enter option:","ERROR: invalid value, try again", 1, 4);

    switch(option){
    case 1:
        ll_sort(pArrayListEmployee, employee_SortByID, 0);
        printf("SUCCESS: sorting by ID complete\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee, employee_SortByName, 0);
        printf("SUCCESS: sorting by name complete\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee, employee_SortByHours, 0);
        printf("SUCCESS: sorting by worked hours complete\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee, employee_SortBySalary, 0);
        printf("SUCCESS: sorting by salary complete\n");
        break;

    }

    return 0;
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
	Employee* this;
	FILE* list = fopen(path, "w");
	int rtn = -1;

	if(list == NULL)
	{
		printf("ERROR: could not save the file as text");
	}
	else
	{
		fprintf(list, "id,nombre,horasTrabajadas,sueldo\n");

		if(pArrayListEmployee != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				this = (Employee*)ll_get(pArrayListEmployee,i);
				fprintf(list, "%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
			}
			printf("SUCCESS: file saved");
			rtn = 0;
		}

	}
	fclose(list);
	return rtn;


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
	Employee* this;
	FILE* list = fopen(path, "w");
	int rtn = -1;

	if(list == NULL)
	{
		printf("ERROR: could not save the file as text");
	}
	else
	{

		if(pArrayListEmployee != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				this = (Employee*)ll_get(pArrayListEmployee,i);
				fwrite(this, sizeof(Employee),1, list);

			}
			printf("SUCCESS: file saved");
			rtn = 0;
		}

	}
	fclose(list);
	return rtn;


}

