#include "toolboxTP3.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


#define ULT_ID "ultId.bin"

#define ARCH_CSV "data.csv"
#define ARCH_BIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{


	setbuf(stdout, NULL);

    int opcion = 0;
    int estado;

    int ultId = controller_getLastId(ULT_ID);
    int isListaCargada = 0;
    int auxUltId = ultId;
    int isListaGuardada = 0;



    LinkedList* listaEmpleados = ll_newLinkedList();

    //printf("ultimo id: %d\n", ultId); // solo para probar


    do{

        printf("\t\t\t***BIENVENIDO***\n\n");
        printf("Menu: \n\n");

    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado.\n");
    	printf("4. Modificar datos de empleado.\n");
    	printf("5. Baja de empleado.\n");
    	printf("6. Listar empleados.\n");
    	printf("7. Ordenar empleados.\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");

    	opcion = getIntRange("Ingrese opcion: ", "ERROR, reingrese", 1, 10);



        switch(opcion)
        {
            case 1:

            	if (isListaCargada < 1)
            	{
					estado = controller_loadFromText(ARCH_CSV,listaEmpleados);
			        if (estado != 0)
					{
						printf("Error cargando el archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realizó correctamente. \n");
						isListaCargada = 1;
					}
					break;
            	}
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;

            case 2:
            	if (isListaCargada < 1)
                {
					estado = controller_loadFromBinary(ARCH_BIN,listaEmpleados);
					if (estado != 0)
					{
						printf("Error cargando el archivo. \n");
					}
					else
					{
						printf("La carga del archivo se realizó correctamente. \n");
						isListaCargada = 1;
					}
                }
            	else
            	{
            		printf("La lista ya fue cargada.\n");
            	}
                break;

            case 3:
            	estado = controller_addEmployee(listaEmpleados, &auxUltId);

                if (estado != 0)
                {
					printf("Error cargando empleado. \n");
                }
                else
                {
                	printf("La carga del empleado se realizó correctamente. \n");
                }
            	break;

            case 4:
            	estado = controller_editEmployee(listaEmpleados);
                if (estado != 0)
                {
                	printf("Error en la modificación del empleado. \n");
                }
                else
                {
                	printf("La modificación del empleado se realizó correctamente. \n");
                }
            	break;

            case 5:
            	estado = controller_removeEmployee(listaEmpleados);
				if (estado != 0)
				{
					printf("Error eliminando empleado. \n");
				}
				else
				{
					printf("La eliminacion del empleado se realizó correctamente. \n");
				}
            	break;

            case 6:
            	estado = controller_ListEmployee(listaEmpleados);
				if (estado == 0)
				{
					printf("Error mostrando la lista. \n");
				}
				else
				{
					printf("La muestra de la lista se realizó correctamente. \n");
				}
            	break;
            case 7:
            	estado = controller_sortEmployee(listaEmpleados);
				if (estado != 0)
				{
					printf("Error en el ordenamiento. \n");
				}
				else
				{
					printf("El orden de los empleados se realizó correctamente. \n");
				}
            	break;
            case 8:

            	if (isListaCargada == 1 && auxUltId > ultId)
            	{
                	controller_ListEmployee(listaEmpleados);

                	estado = controller_saveAsText(ARCH_CSV , listaEmpleados);
					if (estado != 0)
					{
						printf("Hubo un inconveniente al guardar la lista de empleados. \n");
					}
					else
					{
						printf("Los cambios en la lista de empleados se guardaron correctamente. \n");
						controller_setLastId(ULT_ID,auxUltId);
						isListaGuardada = 1;
					}


            	}
            	else
            	{
            		printf("No hay ninguna lista cargada. \n");
            	}
            	break;
            case 9:
            	if (isListaCargada == 1 && auxUltId > ultId)
            	{
                	controller_ListEmployee(listaEmpleados);

                	estado = controller_saveAsBinary(ARCH_BIN , listaEmpleados);
					if (estado != 0)
					{
						printf("Hubo un inconveniente al guardar la lista de empleados. \n");
					}
					else
					{
						printf("Los cambios en la lista de empleados se guardaron correctamente. \n");
						controller_setLastId(ULT_ID,auxUltId);
						isListaGuardada = 1;
					}


            	}
            	else
            	{
            		printf("No hay ninguna lista cargada. \n");
            	}
            	break;

            case 10:
            	if (isListaGuardada < 1 && auxUltId > ultId)
            	{

            			ll_deleteLinkedList(listaEmpleados);
            			break;

            	}
            	else
            	{
            		ultId = auxUltId;
            	}

            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }

    }while(opcion != 10);
    return 0;
}

