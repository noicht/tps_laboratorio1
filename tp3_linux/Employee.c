#include "Employee.h"
#include "toolboxTP3.h"

Employee* employee_new()
{
	Employee* this = calloc(sizeof(Employee*), 1);

	return this;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldosStr)
{
	Employee* this = employee_new();

	if(this != NULL)
	{
		employee_setId(this, atoi(idStr));
		employee_setNombre(this, nombreStr);
		employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
		employee_setSueldo(this, atoi(sueldosStr));

		// aca seteo todo
	}
	return this;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);

	}
}


// SETS

int employee_setId(Employee* this,int id)
{
	int rtn = 1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 0;

	}

	return rtn;

}



int employee_setNombre(Employee* this,char* nombre)
{
	int rtn = 1;

	if(this != NULL && strlen(nombre) > 0)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}
	return rtn;

}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn = 1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn = 0;
	}
	return rtn;
}



int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn = 1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		rtn = 0;
	}
	return rtn;

}

// GETS


int employee_getId(Employee* this,int* id)
{
	int rtn = 1;

	if(this != NULL)
	{
		*id = this->id;
		rtn = 0;
	}
	return rtn;

}



int employee_getNombre(Employee* this,char* nombre)
{
	int rtn = 1;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}
	return rtn;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn = 1;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn = 0;
	}
	return rtn;

}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn = 1;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		rtn = 0;
	}
	return rtn;

}

int employee_getEmployee(Employee* this, int* auxId, char* auxNombre, int* auxHorasTrabajadas, int* auxSueldo)
{
	int rtn = 1;

	if(this != NULL)
	{
		employee_getId(this, auxId);
		employee_getNombre(this, auxNombre);
		employee_getHorasTrabajadas(this, auxHorasTrabajadas);
		employee_getSueldo(this, auxSueldo);

		rtn = 0;
	}
	return rtn;

}


int employee_PrintEmployee(Employee* this)
{
	int rtn = 1;

	int auxId;
	char auxNombre[MAX_LONG];
	int auxHorasTrabajadas;
	int auxSueldo;


	if(this != NULL)
	{
		rtn = employee_getEmployee(this, auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

		if(rtn == 0)
		{
			printf("%4d %18s %18d %7d \n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
		}
	}
	else
	{
		printf("\n\nNo hay empleados cargados\n\n");

	}

	return rtn;

}

int employee_sortById(void* id1, void* id2)
{
	int rtn;

	Employee* emp1;
	Employee* emp2;

	if(id1 != NULL && id2 != NULL)
	{
		emp1 = (Employee*) id1;
		emp2 = (Employee*) id2;

		if(emp1->id > emp2->id)
		{
			rtn = 1;
		}
		else
		{
			if(emp1->id < emp2->id)
			{
				rtn = 0;

			}
			else
			{
				rtn = -1;
			}
		}

	}

	return rtn;

}
