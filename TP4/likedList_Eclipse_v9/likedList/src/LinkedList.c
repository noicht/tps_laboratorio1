#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }


    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len;

	if(this != NULL)
	{
		len = ll_len(this);

		if(nodeIndex >= 0 && nodeIndex < len) // indice menor al size de la LL
		{
			// si nodeIndex = 0 e i = 0, deja pFirstNode, caso contrario, pNextNode

			pNode = this->pFirstNode; // entro al pirmer nodo

			for(int i = 0; i < nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
			}
		}


	}


    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex); // no tocar
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;

    Node* pNodeNuevo;
    Node* pNodeAnterior;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(nodeIndex >= 0 && nodeIndex <= len)
    	{
    		pNodeNuevo = (Node*) malloc(sizeof(Node*));

    		if(pNodeNuevo != NULL)
    		{
    			pNodeNuevo -> pElement = pElement; // asigno el elemento que paso por parametro

    			if(nodeIndex == 0)
    			{
    				pNodeNuevo -> pNextNode = this -> pFirstNode; //	primer nodo que apunta al siguiente nodo le asigno lo que apunta la ll (NULL) ya que es el primer nodo

    				this -> pFirstNode = pNodeNuevo; // asigno NULL, la lista que apunta al primer nodo le asigno la direccion del nuevo nodo
    			}
    			else
    			{
    				pNodeAnterior = getNode(this, nodeIndex - 1);

    				pNodeNuevo -> pNextNode = pNodeAnterior -> pNextNode; // el nuevo nodo le asigno lo que apuntaba el nodo anterior (NULL)

    				pNodeAnterior -> pNextNode = pNodeNuevo; // al nodo anterior que apunta al siguiente nodo le asigno la direccion de memoria del siguiente nodo


    			}
				this -> size++;
    			returnAux = 0;


    		}


    	}

    }



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement); // no tocar
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement); // agrego en la ultima posicion un elemento y con el ll_len me traigo la ultima posicion
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = getNode(this, index); // traigo el nodo con el indice

    	if(pNode != NULL)
    	{
    		returnAux = pNode -> pElement; // retorno el nodo que apunta al elemento
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	pNode = getNode(this, index);

    	if(pNode != NULL)
    	{
    		pNode -> pElement = pElement; // modifico el elemento del nodo y le asigno el paramentro pElement
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pDeletedNode;
    Node* pPreviousNode;

    if(this != NULL && index >= 0 && index < this -> size)
    {
    	if(index == 0)
    	{
    		pDeletedNode = getNode(this, index);
    		this->pFirstNode = pDeletedNode -> pNextNode;
    	}
    	else
    	{
    		pDeletedNode = getNode(this, index);
    		pPreviousNode = getNode(this, index-1);
    		pPreviousNode -> pNextNode = pDeletedNode -> pNextNode;
    	}
    	this -> size--;
    	returnAux = 0;
    	free(pDeletedNode);
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;


    if(this != NULL)
    {

    	for(int i = 0; i < ll_len(this); i++)
    	{
    		ll_remove(this,i);
    	}
    	if(ll_len(this) == 0)
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0) // verifico si ll_clear borro todos los elementos
    	{
    		free(this);
    		this = NULL;

    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    Node* pNode;

    if(this != NULL)
    {
    	for(int i = 0; i < len; i++)
    	{
    		pNode = ll_get(this, i); // hago uso de un for para iterar la lista e ir trayendome los elementos de cada posicion, me traigo el nodo que apunta al elemento

    		if(pNode -> pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}


    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    int len = ll_len(this);

    if(this != NULL)
    {

    	if(len == 0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	if(index >= 0 && index <= len)
    	{
    		returnAux = addNode(this, index, pElement);
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(index >= 0 && index <= len)
    	{
    		returnAux = ll_get(this, index);
    		ll_remove(this, index);
    	}

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;

    int len = ll_len(this);

    if(this != NULL)
    {
    	returnAux = 0;

    	for(int i = 0; i < len; i++)
    	{
    		pNode = ll_get(this, i);

    		if(pNode == pElement)
    		{
    			returnAux = 1;
    			break;

    		}
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int flag = 0;
    Node* pNode = NULL;

    int len;


    if(this != NULL && this2 != NULL)
    {
    	len = ll_len(this2);

    	returnAux = 1;

    	for(int i = 0; i < len; i++)
    	{
    		pNode = ll_get(this2, i);
    		flag = ll_contains(this, pNode);

    		if(flag == 0)
    		{
    			returnAux = 0;
    			break;
    		}

    	}
    	printf("%d", flag);

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
    void* pAux = NULL;


    if(this != NULL)
    {
    	len = ll_len(this);

    	if((from >= 0 && from <= len) && (to >= from && to <= len))
    	{
    		cloneArray = ll_newLinkedList();

    		for(int i = from; i < to; i++)
    		{
    			pAux = ll_get(this, i);

    			if(pAux != NULL)
    			{
    				addNode(cloneArray, i, pAux);
    			}
    		}
    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this, 0, len);
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    int validate_order;
    void* pElement1;
	void* pElement2;
	void* pAuxElement;
    int len;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	len = ll_len(this);
        for(int i = 0; i<-1; i++)
        {
            pElement1 = ll_get(this, i);
            for(int j=i+1; j<len; j++)
            {
                pElement2 = ll_get(this, j);
                validate_order = pFunc(pElement1, pElement2);

                if((order==1 && (validate_order==1)) ||
                   (order==0 && (validate_order==-1)))
                {
					pAuxElement = pElement1;
					pElement1 = pElement2;
					pElement2 = pAuxElement;

                }
                ll_set(this, i, pElement1);
                ll_set(this, j, pElement2);
            }
        }
        returnAux = 0;
    }

    return returnAux;

}

