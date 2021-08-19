/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: slist.c                                                                 *
*Description: Functions to simulate the Singly Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna Savina                                                         *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */

#include "slist.h"

slist_node_t *CreateNode(void);
int ToIncrement(void *data, void *param);
void SwapPtr(void **p1, void **p2);

struct slist_node
{
    void *data;
    struct slist_node *next;
};

struct slist
{
    slist_node_t *head;
    slist_node_t *tail;
};

/******************************* Functions ************************************/
/*******************************************************************************
*
	Decription: 	create new linked list O(1)
	Output:			pointer to a new linked list, returns NULL if fails
	
	Reviewer: Benjamin Bitton                                                         
	Status: approved
*
*******************************************************************************/
slist_t *SListCreate(void)
{
	slist_t *slist = (slist_t *)malloc(sizeof(slist_t));
	slist_node_t *p_dummy_node = NULL;
    
	if(NULL == slist)
	{
		return NULL;
	}
	
	p_dummy_node = CreateNode();
	
	if(NULL == p_dummy_node)
	{
		free(slist);
		slist = NULL;
		return NULL;
	}

	p_dummy_node->data = slist;
	p_dummy_node->next = NULL;
    
	slist->tail = p_dummy_node;
	slist->head = p_dummy_node;
    
	return slist;
}

/*******************************************************************************
*
	Decription: 	Deletes linkedd list and frees all allocations O(n)
	
	Reviewer: Benjamin Bitton                                                       
	Status: approved
*
*******************************************************************************/
void SListDestroy(slist_t *slist)
{
	slist_iter_t iter = {0};

	assert(slist);
    
	iter = SListBegin(slist);
    
	while(!SListIsSameIterator(iter, SListEnd(slist)))
	{    
		iter = SListRemove(iter);
	}
    
	free(iter);
	iter = NULL;
	
	slist->head = NULL;
	slist->tail = NULL;
	
	free(slist);
	slist = NULL;  
}

/*******************************************************************************
*
	Decription: 	Returns iterator to the beginning of linked list O(1)
	
	Reviewer: Benjamin Bitton                                                      
	Status: approved 
*
*******************************************************************************/
slist_iter_t SListBegin(const slist_t *slist)
{
	assert(slist);	

	return slist->head;
}

/*******************************************************************************
*
	Decription: 	Returns iterator to the end of the linked list O(1)
	
	Reviewer: Benjamin Bitton                                                      
	Status: approved 
*
*******************************************************************************/
slist_iter_t SListEnd(const slist_t *slist)
{
	assert(slist);		

	return slist->tail;
}

/*******************************************************************************
*
	Decription: 	returns iterator to next element O(1)

	Reviewer: Benjamin Bitton                                                      
	Status: approved  
*
*******************************************************************************/
slist_iter_t SListNext(const slist_iter_t iter)
{
	return iter->next;
}

/*******************************************************************************
*
	Decription: 	Compares two iterators O(1)	
	Output:			1 if iterators are the same, 0  if different
	
	Reviewer: Benjamin Bitton                                                      
	Status: approved  
*
*******************************************************************************/            
int SListIsSameIterator(const slist_iter_t iter1 ,const slist_iter_t iter2)
{
	return (iter1 == iter2); 
}

/*******************************************************************************
*
	Decription: 	Gets data from node of linked list	O(1)
	
	Reviewer: Benjamin Bitton                                                      
	Status: approved  
*
*******************************************************************************/
void *SListGetData(const slist_iter_t iter)
{
	assert(iter);
	return iter->data;
}

/*******************************************************************************
*
	Decription: 	Assigns data to a node O(1)
	
	Reviewer: Benjamin Bitton                                                      
	Status: approved  
*
*******************************************************************************/
void SListSetData(slist_iter_t iter, void *data)
{
	assert(data);
	assert(SListNext(iter)); /* If node is not a tail*/
	
	iter->data = data;
}

/*******************************************************************************
*
	Decription: 	Inserts a node into the linked list	O(1)
	If failed, returns iter to the last node
	
	Reviewer: Anna Savina                                                           
	Status: approved 
*
*******************************************************************************/
slist_iter_t SListInsert(slist_iter_t where, void *data)
{
	slist_iter_t p_new_node = CreateNode();
	
	assert(where);
	
	if (NULL == p_new_node)
	{
		while (NULL != SListNext(where))
		{
			where = SListNext(where);
		}
		
		return where;
	}
	
	p_new_node->data = SListGetData(where); 
	p_new_node->next = SListNext(where);
	
	where->data = data;
	where->next = p_new_node;
	
	if(!SListNext(p_new_node))
	{
		((slist_t *)(p_new_node->data))->tail = p_new_node;
	}
	
	return where;
}

/*******************************************************************************
*
	Decription: 	Removes a node from the linked list	O(1)
	returns iter to next node after the one removed
	
	Reviewer: Anna Savina                                                           
	Status: approved 
*
*******************************************************************************/
slist_iter_t SListRemove(slist_iter_t iter)
{
	
	slist_iter_t to_free = NULL;
	assert(iter->next);
	
	to_free = SListNext(iter);

	iter->data = SListGetData(SListNext(iter));
	iter->next = SListNext(SListNext(iter));

	if(!SListNext(iter))
	{
		((slist_t *)(iter->data))->tail = iter;
	}

	free(to_free);
	to_free = NULL;

	return iter;
}

/*******************************************************************************
*
	Decription: 	Returns size of the linked list O(n) 
	
	Reviewer: Anna Savina                                                           
	Status: approved 
*
*******************************************************************************/
size_t SListSize(const slist_t *slist)
{
	size_t count = 0;
	
	assert(slist);
	
	SListForEach(SListBegin(slist), SListEnd(slist), ToIncrement, &count);
	
	return count;
}

/*******************************************************************************
*
	Decription: 	Checks if linked list is empty	O(1)
	returns 1 if linked list is empty, other value if not
	
	Reviewer: Anna Savina                                                           
	Status: approved 
*
*******************************************************************************/
int SListIsEmpty(const slist_t *slist)
{
	return SListIsSameIterator(SListBegin(slist), SListEnd(slist));
}

/*******************************************************************************
*
	Decription: 	Searches linked list in specific range for requested element
	
	Reviewer: Anna Savina                                                            
	Status: approved 
*
*******************************************************************************/
slist_iter_t SListFind(
    slist_iter_t from,
    slist_iter_t to,
    int (*is_match)(const void *data, void *param),
    void *param
)
{
	slist_iter_t p_iter = from;
	
	assert(from);
	assert(to);
	
	while(!SListIsSameIterator(p_iter, to))
	{
		if(1 == is_match(SListGetData(p_iter), param))
		{
			return p_iter;
		}
		
		p_iter = SListNext(p_iter);
	}
	
	return p_iter;
}


/*******************************************************************************
*
	Decription: 	Applies user defined function to a range of elements	
	returns output of action function 	
	
	Reviewer: Anna Savina                                                           
	Status: approved
*
*******************************************************************************/
int SListForEach(
    slist_iter_t from,
    slist_iter_t to,
    int (*action)(void *data, void *param),
    void *param
)
{
	slist_iter_t p_iter = from;
	int status = 0;
	
	assert(from);
	assert(to);
	
	while(!SListIsSameIterator(p_iter, to))
	{
		status = action(SListGetData(p_iter), param);
		
		if(0 != status)
		{
			return status;
		}	

		p_iter = SListNext(p_iter);
	}
	
	return status;
}  


/*******************************************************************************
*
	Decription: 	Appends 2 slists
	
	Reviewer: Anna Savina
	Status: approved
*
*******************************************************************************/ 
    
void SListAppend(slist_t *dest, slist_t *src)
{
        if (!SListIsEmpty(src))
    {
        SwapPtr(&dest->tail->data, &src->tail->data);
        SwapPtr(&dest->tail->data, &src->head->data);
        
        dest->tail->next = src->head->next;
        src->head->next = NULL;
        
        dest->tail = src->tail;
        src->tail = src->head;
    }
}
    
    
/******************************* Helping functions ****************************/
/******************************* Function to create node **********************/

slist_node_t *CreateNode()
{
	slist_node_t *p_new_node = (slist_node_t *)malloc(sizeof(slist_node_t));
    
	if (NULL == p_new_node)
	{
		return NULL; 
	}
    
	return p_new_node;
} 


/******************************* Function to increment by 1 *******************/

int ToIncrement(void *data, void *param)
{
	*(size_t *)param += 1;
	(void)(data);
	
	return 0;
}


/******************************* Function to swap pointers ********************/

void SwapPtr(void **p1, void **p2)
{
    void *p_temp = *p1;
    *p1 = *p2;
    *p2 = p_temp;
}



