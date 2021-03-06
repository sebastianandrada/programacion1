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
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
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
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int indexNodoActual;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < this->size)
    {
        pNode = this->pFirstNode;
        if(nodeIndex > 0)
        {
            for(indexNodoActual=0;indexNodoActual<nodeIndex;indexNodoActual++)
            {
                if(pNode != NULL)
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
    return getNode(this, nodeIndex);
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
    Node* nuevoNodo = malloc(sizeof(Node));
    Node* pNode;
    int len = ll_len(this);
    nuevoNodo->pElement = pElement;

    if (this!= NULL && nodeIndex > -1 && nodeIndex <= len) {
        if(nodeIndex == 0)
        {
            nuevoNodo->pNextNode = this->pFirstNode;
            this->pFirstNode = nuevoNodo;
            this->size++;
            returnAux = 0;
        } else
        {
            pNode = getNode(this, nodeIndex-1);
            nuevoNodo->pNextNode = pNode->pNextNode;
            pNode->pNextNode = nuevoNodo;
            this->size++;
            returnAux = 0;
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
    return addNode(this,nodeIndex,pElement);
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
        addNode(this,this->size,pElement);
        returnAux = 0;
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
    Node* nodeAux = NULL;
    if(this != NULL && index > -1 && index < this->size)
    {
        nodeAux = getNode(this, index);
        returnAux = nodeAux->pElement;
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
    Node* pNodeAux;
    if(this != NULL && index >= 0 && index < this->size)
    {
        pNodeAux = getNode(this, index);
        pNodeAux->pElement = pElement;
        returnAux = 0;
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
    Node* pNodeAux;
    Node* pNodePrev;
    if(this != NULL && index > -1 && index < this->size)
    {
        if(index == 0)
        {
            pNodeAux = this->pFirstNode;
            this->pFirstNode = pNodeAux->pNextNode;
            free(pNodeAux);
            this->size--;
            returnAux = 0;
        } else
        {
            pNodeAux = getNode(this, index);
            pNodePrev = getNode(this, index-1);
            pNodePrev->pNextNode = pNodeAux->pNextNode;
            free(pNodeAux);
            this->size--;
            returnAux = 0;
        }
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
    int len = ll_len(this);
    int indexNodoActual;
    //Node* pNodeAux;

    if(this != NULL)
    {
        //pNodeAux = this->pFirstNode;
        for(indexNodoActual=0;indexNodoActual<len;indexNodoActual++)
        {
            /*pNodeToDelete = pNodeAux;
            pNodeAux = pNodeAux->pNextNode;
            free(pNodeToDelete);*/
            ll_remove(this, indexNodoActual);
        }
        returnAux = 0;
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
        ll_clear(this);
        free(this);
        this = NULL;
        returnAux = 0;
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
    Node* pNodeAux;
    if(this != NULL)
    {
        int i;
        pNodeAux = this->pFirstNode;
        for(i=0;i<len;i++)
        {
            pNodeAux = getNode(this, i);
            if(pElement == pNodeAux->pElement)
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
    if(this != NULL)
    {
        if(this->pFirstNode == NULL)
        {
            returnAux = 1;
        }else
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
    int returnAux;
    returnAux = addNode(this, index, pElement);
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
    Node* pNodeAux;
    Node* pNodePrev;
    if(this != NULL && index > -1 && index < this->size)
    {
        if(index == 0)
        {
            pNodeAux = this->pFirstNode;
            this->pFirstNode = pNodeAux->pNextNode;
            returnAux = pNodeAux->pElement;
            free(pNodeAux);
            this->size--;
        } else
        {
            pNodePrev = getNode(this, index-1);
            pNodeAux = pNodePrev->pNextNode;
            pNodePrev->pNextNode = pNodeAux->pNextNode;
            returnAux = pNodeAux->pElement;
            this->size--;
            free(pNodeAux);
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
    void* pElementAux;
    int i;
    if(this != NULL)
    {
        int len = ll_len(this);
        returnAux = 0;
        for(i=0;i<len;i++)
        {
            pElementAux = ll_get(this, i);

            if(pElementAux == pElement)
            {
                returnAux = 1;
                break;
            }
            returnAux = 0;
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
    int i;
    int len = ll_len(this2);
    void* pElement;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i=0;i<len;i++)
        {
            pElement = ll_get(this2, i);
            if(!ll_contains(this, pElement))
            {
                returnAux = 0;
                break;
            }
        }
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
    int i;
    void* pElement;
    if(this != NULL && from > -1 && from < this->size && to > from && to <= this->size)
    {
        cloneArray = ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pElement = ll_get(this, i);
            ll_add(cloneArray, pElement);
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
    int i;
    int len = ll_len(this);
    void* pElementAux;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0;i<len;i++)
        {
            pElementAux = ll_get(this, i);
            ll_add(cloneArray, pElementAux);
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
    int flagNoEstaOrdenado = 1;
    int len = ll_len(this);
    int i;
    int retornoFn;
    void* pElementA;
    void* pElementB;
    if(this != NULL && pFunc != NULL && len>0)
    {
        while(flagNoEstaOrdenado == 1)
        {
            flagNoEstaOrdenado = 0;
            for(i=0;i<len-1;i++)
            {
                pElementA = ll_get(this, i);
                pElementB = ll_get(this, i+1);
                if(pElementA != NULL && pElementB != NULL)
                {
                    retornoFn = pFunc(pElementA, pElementB);
                    if((order == 0 && retornoFn == -1) ||
                       (order == 1 && retornoFn == 1 ))
                    {
                        ll_set(this, i, pElementB);
                        ll_set(this, i+1, pElementA);
                        flagNoEstaOrdenado = 1;
                        returnAux = 0;
                    }
                }

            }
        }
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    int i;
    int len = ll_len(this);
    void* pElementAux;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0;i<len;i++)
        {
            pElementAux = ll_get(this, i);
            if(pElementAux != NULL && pFunc(pElementAux))
            {
                ll_add(cloneArray, pElementAux);
            }
        }
    }
    return cloneArray;
}

Node* ll_startIter(LinkedList* lista)
{
    lista->nodoActual = lista->pFirstNode;
    return lista->pFirstNode;
}

/*Node* ll_set_startIterator(LinkedList* lista, Node* node)
{

}
*/
Node* ll_getNext(LinkedList* lista)
{

    Node* nodeAux;
    nodeAux = lista->nodoActual;
    /*if(lista->nodoActual->pNextNode != NULL)
    {*/
        lista->nodoActual = lista->nodoActual->pNextNode;
    //}

    return nodeAux;
}

void ll_map(LinkedList* this, int (*pFunc)(void*))
{
    Node* it;
    it = ll_startIter(this);
    Node* pNodeAux;
    if(this != NULL)
    {

        while(it != NULL)
        {
            pNodeAux = ll_getNext(this);
            if(pNodeAux != NULL && pFunc != NULL)
            {
                pFunc(pNodeAux->pElement);
            }
            it= this->nodoActual->pNextNode;
        }
    }
}

//strtok strstr
