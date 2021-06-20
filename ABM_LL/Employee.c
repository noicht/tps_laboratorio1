#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "LinkedList.h"
#include "General.h"

//encapsulamiento - abstraccion - herencia - polimorfismo

Employee* employee_new()
{
	Employee* this = calloc(sizeof(Employee*), 1);

	return this;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();

	if(this != NULL)
	{
		employee_setId(this, atoi(idStr));
		employee_setNombre(this, nombreStr);
		employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
		employee_setSueldo(this, atoi(sueldoStr));

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
	int rtn = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		rtn = 0;
	}
	return rtn;

}

int employee_setNombre(Employee* this,char* nombre)
{
	int rtn = -1;

	if(this != NULL && strlen(nombre) > 0)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}
	return rtn;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn = 0;
	}
	return rtn;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn = -1;

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
	int rtn = -1;

	if(this != NULL)
	{
		*id = this->id;
		rtn = 0;
	}
	return rtn;

}

int employee_getNombre(Employee* this,char* nombre)
{
	int rtn = -1;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		rtn = 0;
	}
	return rtn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn = -1;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		rtn = 0;
	}
	return rtn;

}


int employee_compareByName(void* e1, void* e2)
{
	int comp;

	Employee* emp1 = (Employee*) e1;
	Employee* emp2 = (Employee*) e2;
	comp = strcmp(emp1->nombre, emp2->nombre);
	return comp;
}

int employee_SortByID(void* auxA, void* auxB)
{
	int rtn = 0;
	Employee* employeeA = (Employee*) auxA;
	Employee* employeeB = (Employee*) auxB;

    if(employeeA->id > employeeB->id)
    {
        rtn = 1 ;
    }
    if(employeeA->id < employeeB->id)
    {
        rtn = -1;
    }
    return rtn;

}

int employee_SortByName(void* auxA, void* auxB)
{
	int rtn = 0;
	Employee* employeeA = (Employee*) auxA;
	Employee* employeeB = (Employee*) auxB;

    if(strcmp(employeeA->nombre, employeeB->nombre) < 0)
    {
        rtn = 1 ;
    }
    if(strcmp(employeeA->nombre, employeeB->nombre) > 0)
    {
        rtn = -1;
    }
    return rtn;

}

int employee_SortByHours(void* auxA, void* auxB)
{
	int rtn = 0;
	Employee* employeeA = (Employee*) auxA;
	Employee* employeeB = (Employee*) auxB;

    if(employeeA->horasTrabajadas > employeeB->horasTrabajadas)
    {
        rtn = 1 ;
    }
    if(employeeA->horasTrabajadas < employeeB->horasTrabajadas)
    {
        rtn = -1;
    }
    return rtn;



}


int employee_SortBySalary(void* auxA, void* auxB)
{
	int rtn = 0;
	Employee* employeeA = (Employee*) auxA;
	Employee* employeeB = (Employee*) auxB;

    if(employeeA->sueldo > employeeB->sueldo)
    {
        rtn = 1 ;
    }
    if(employeeA->sueldo < employeeB->sueldo)
    {
        rtn = -1;
    }
    return rtn;



}



