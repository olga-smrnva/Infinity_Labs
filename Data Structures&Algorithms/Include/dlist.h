/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: dlist.h                                                                 *
*Description: Functions to simulate the Double Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer:                                                                     *
*Status: in development                                                        *
*                                                                              *
*******************************************************************************/

#ifndef __OL99_DLIST_H__
#define __OL99_DLIST_H__

#include <sys/types.h>		/* size_t, ssize_t */

typedef struct dlist dlist_t;
typedef struct dlist_node dlist_node_t;
typedef dlist_node_t* dlist_iter_t;


/******************************* Functions ************************************/

/*******************************************************************************
*
	Decription:	Create new double linked list, 
	returns an terator to a new double linked list, NULL if fail 
	
	Time Complexity: O(1)	
*
*******************************************************************************/
dlist_t *DListCreate(void);

/*******************************************************************************
*
	Decription: Destroys double linked list (free all allocations) 
	
	Time Complexity: O(n)
*
*******************************************************************************/
void DListDestroy(dlist_t *list);

/*******************************************************************************
*
	Decription:	Returns an iterator to the beginning of the list 
	
	Time Complexity: O(1)	
*
*******************************************************************************/

dlist_iter_t DListBegin(const dlist_t *list);

/*******************************************************************************
*
	Decription: Returns an iterator to the end of the list
	
	Time Complexity: O(1)	
*
*******************************************************************************/
dlist_iter_t DListEnd(const dlist_t *list);

/*******************************************************************************
*
	Decription: Returns an iterator to the next node
	
	Time Complexity: O(1)		
*
*******************************************************************************/
dlist_iter_t DListNext(dlist_iter_t iterator);

/*******************************************************************************
*
	Decription: Return an iterator to the previous node

	Time Complexity: O(1)	
*
*******************************************************************************/
dlist_iter_t DListPrev(dlist_iter_t iterator);

/*******************************************************************************
*
	Decription: Returns 1 if iterators are the same, 0 if different
	
	Time Complexity: O(1)
*
*******************************************************************************/
int DListIsSameIterator(dlist_iter_t iter1, dlist_iter_t iter2);

/*******************************************************************************
*
	Decription: Returns the data of node
	
	Time Complexity: O(1)		
*
*******************************************************************************/
void *DListGetData(dlist_iter_t iterator);

/*******************************************************************************
*
	Decription: Assigns data to a node
	
	Time Complexity: O(1)		
*
*******************************************************************************/
void DListSetData(dlist_iter_t iterator, void *data);

/*******************************************************************************
*
	Decription:Inserts a node into the double linked list, before the iterator, 
	returns iterator to inserted node. If failed, iterator to end of list
	
	Time Complexity: O(1) Amortized O(n)		
*
*******************************************************************************/

dlist_iter_t DListInsert(dlist_iter_t where, void *data);

/*******************************************************************************
*
	Decription: Removes a node from the double linked list, 
	returns iterator to next node
	
	Time Complexity: O(1)		
*
*******************************************************************************/
dlist_iter_t DListRemove(dlist_iter_t who);

/*******************************************************************************
*
	Decription:	Returns size of the double linked list
	
	Time Complexity: O(n)		
*
*******************************************************************************/
size_t DListSize(const dlist_t *list);

/*******************************************************************************
*
	Decription:	Returns 1 if list is empty, 0 otherwise
	
	Time Complexity: O(1)		
*
*******************************************************************************/
int DListIsEmpty(const dlist_t *list);

/*******************************************************************************
*
	Decription: Searches linked list in specific range for requested element	
	
	Output:	First found iterator to the requested element. 
	If not, iterator to the end of the list.

	Time Complexity: O(n)	
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
*
*******************************************************************************/
dlist_iter_t DListPushFront(dlist_t *dlist, void *data);

/*******************************************************************************
*
	Decription:	Add new node in the end of the list, returns iterator to newlly 
	created node, if failed, returns the end of the list.
	
	Time Complexity: O(1)		
*
*******************************************************************************/
dlist_iter_t DListPushBack(dlist_t *dlist, void *data);

/*******************************************************************************
*
	Decription:	Delete a node in the beginning of the list 

	Time Complexity: O(1)	
*
*******************************************************************************/
void DListPopFront(dlist_t *dlist);

/*******************************************************************************
*
	Decription:	Delete a node in the end of the list 
	
	Time Complexity: O(1)		
*
*******************************************************************************/
void DListPopBack(dlist_t *dlist);

/*******************************************************************************
*
	Decription:	Finds all matched nodes and copy them to output_list
	Output:	return number of elements if successfull, -1 if failed allocation

	Time Complexity: O(n)
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
*
*******************************************************************************/
 
dlist_iter_t DListSplice(dlist_iter_t where, dlist_iter_t from, dlist_iter_t to);

#endif /*__OL99_DLIST_H__ */



