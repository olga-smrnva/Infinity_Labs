/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: dlist.c                                                                 *
*Description: Functions to simulate the Double Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer:                                                                     *
*Status: in development                                                        *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* ssize_t, size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */

#include "dlist.h"

static dlist_node_t *CreateNode(void);
/*static dlist_iter_t CreateNode(void);*/

struct dlist_node
{
    void *data;
    struct dlist_node *next;
    struct dlist_node *prev;
};

struct dlist
{    
    dlist_node_t head;
    dlist_node_t tail;
};

/*******************************************************************************
*
	Decription:	Create new double linked list, 
	returns an terator to a new double linked list, NULL if fail 
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_t *DListCreate(void)
{
	dlist_t *list = (dlist_t *)malloc(sizeof(dlist_t));
	
	if(NULL == list)
	{
		return NULL;
	}
	
	list->head.data = NULL;
	list->head.next = &(list->tail);
	list->head.prev = NULL;

	list->tail.data = NULL;
	list->tail.next = NULL;
	list->tail.prev = &(list->head);
	
	return list;
}

/*******************************************************************************
*
	Decription: Destroys double linked list (free all allocations) 
	Time Complexity: O(n)
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
void DListDestroy(dlist_t *list)
{
	dlist_iter_t iter = {0};
	dlist_iter_t iter_end = {0};

	assert(list);
	
	iter = DListBegin(list);
	iter_end = DListEnd(list);
	
	while(!DListIsSameIterator(iter, iter_end))
	{
		iter = DListRemove(iter);
	}

	list->head.data = NULL;
	list->head.prev = NULL;
	list->head.next = NULL;
	
	list->tail.data = NULL;
	list->tail.prev = NULL;
	list->tail.next = NULL;
	
	free(list);
	list = NULL;
}

/*******************************************************************************
*
	Decription:	Returns an iterator to the beginning of the list 
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/

dlist_iter_t DListBegin(const dlist_t *list)
{
	assert(list);
	
	return (list->head.next);
}

/*******************************************************************************
*
	Decription: Returns an iterator to the end of the list
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListEnd(const dlist_t *list)
{
	assert(list);
	
	return (dlist_iter_t)&list->tail;
}

/*******************************************************************************
*
	Decription: Returns an iterator to the next node
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListNext(dlist_iter_t iterator)
{
	assert(iterator);

	return iterator->next;
}

/*******************************************************************************
*
	Decription: Return an iterator to the previous node
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListPrev(dlist_iter_t iterator)
{
	assert(iterator);

	return iterator->prev;
}

/*******************************************************************************
*
	Decription: Returns 1 if iterators are the same, 0 if different
	Time Complexity: O(1)
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
int DListIsSameIterator(dlist_iter_t iter1, dlist_iter_t iter2)
{
	return (iter1 == iter2);
}

/*******************************************************************************
*
	Decription: Returns the data of node
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
void *DListGetData(dlist_iter_t iterator)
{
	assert(iterator);
	
	return iterator->data;
}

/*******************************************************************************
*
	Decription: Assigns data to a node
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
void DListSetData(dlist_iter_t iterator, void *data)
{
	assert(iterator);
	assert(iterator->next); /*don't set data to tail*/
	
	iterator->data = data;
}

/*******************************************************************************
*
	Decription:Inserts a node into the double linked list, before the iterator, 
	returns iterator to inserted node. If failed, iterator to end of list
	Time Complexity: O(1) Amortized O(n)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/

dlist_iter_t DListInsert(dlist_iter_t where, void *data)
{
	dlist_node_t *p_new_node = NULL;
	
	assert(where);
	
	p_new_node = CreateNode();
	
	if (NULL == p_new_node)
	{
		while (NULL != DListNext(where))
		{
			where = DListNext(where);
		}
		
		return where;
	}
	
    p_new_node->data = data;
    p_new_node->next = where;
    p_new_node->prev = DListPrev(where);
    
    p_new_node->prev->next = p_new_node;
    where->prev = p_new_node;
	
	return p_new_node;
}

/*******************************************************************************
*
	Decription: Removes a node from the double linked list, 
	returns iterator to next node
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListRemove(dlist_iter_t who)
{
	dlist_iter_t current = {0};
	dlist_iter_t prev = {0};
    
	assert(who);
	assert(who->next);
	
	current = DListNext(who);
	prev = DListPrev(who);
        
    prev->next = current;

    free(who);
    who = NULL;

    return current;
}

/*******************************************************************************
*
	Decription:	Returns size of the double linked list
	Time Complexity: O(n)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
size_t DListSize(const dlist_t *list)
{
	size_t count = 0;
	dlist_iter_t p_start = DListBegin(list);
	
	assert(list);
	
	while(p_start != DListEnd(list))
	{
		p_start = DListNext(p_start);
		++count;
	}
	
	return count;
}


/*******************************************************************************
*
	Decription:	Returns 1 if list is empty, 0 otherwise
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
int DListIsEmpty(const dlist_t *list)
{
	return DListIsSameIterator(DListBegin(list), DListEnd(list));
}

/*******************************************************************************
*
	Decription: Searches linked list in specific range for requested element	
	Output:	First found iterator to the requested element. 
	If not, iterator to the end of the list.
	Time Complexity: O(n)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListFind(
    dlist_iter_t from,
    dlist_iter_t to,
    int (*is_match)(const void *list_data,  void *param),
    void *param);

/*******************************************************************************
*
	Decription:	Applies user defined function to a range of elements, 
	returns return value of action function
	Time Complexity: O(n)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
int DListForEach(
    dlist_iter_t from,
    dlist_iter_t to,
    int (*action)(void *data, void *param),
    void *param);


/*******************************************************************************
*
	Decription:	Add new node in the beginning of the list, returns iterator to
	newly created node, or to the end of list in case of fail
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListPushFront(dlist_t *dlist, void *data);

/*******************************************************************************
*
	Decription:	Add new node in the end of the list, returns iterator to newlly 
	created node, if failed, returns the end of the list.
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
dlist_iter_t DListPushBack(dlist_t *dlist, void *data);

/*******************************************************************************
*
	Decription:	Delete a node in the beginning of the list 
	Time Complexity: O(1)	
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
void DListPopFront(dlist_t *dlist);

/*******************************************************************************
*
	Decription:	Delete a node in the end of the list 
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
void DListPopBack(dlist_t *dlist);

/*******************************************************************************
*
	Decription:	Finds all matched nodes and copy them to output_list
	Output:	return number of elements if successfull, -1 if failed allocation
	Time Complexity: O(n)
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
int DListMultiFind(
    dlist_iter_t from,
    dlist_iter_t to,
    int (*is_match)(const void *data, const void *param),
    const void *param,
    dlist_t *output_list);

/*******************************************************************************
*
	Decription: Put nodes in range of "from" "to" after the node,
	"where" Src list is reduced, and nodes before "from" and after "to"
	are connected (if possible)
	Output: Iterator to "where"
	Time Complexity: O(1)		
	
	Reviewer:                                                 
	Status: in development
*
*******************************************************************************/
 
dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to);


/******************************* Helping functions ****************************/
/******************************* Function to create node **********************/

static dlist_node_t *CreateNode()
{
	dlist_node_t *p_new_node = (dlist_node_t *)malloc(sizeof(dlist_node_t));
    
	if (NULL == p_new_node)
	{
		return NULL; 
	}
    
	return p_new_node;
} 

/*static dlist_iter_t CreateNode (void)
{
	dlist_iter_t newNode = (dlist_iter_t)malloc(sizeof(dlist_node_t));
	
	if (NULL == newNode)
	{
		return NULL;
	}
	
	return newNode;
}*/


/******************************* Function to increment by 1 *******************/

/*int ToIncrement(void *data, void *param)
{
	*(size_t *)param += 1;
	(void)(data);
	
	return 0;
}*/


/******************************* Function to swap pointers ********************/

/*void SwapPtr(void **p1, void **p2)
{
    void *p_temp = *p1;
    *p1 = *p2;
    *p2 = p_temp;
}*/










