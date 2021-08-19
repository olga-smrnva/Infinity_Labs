/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: slist.h                                                                 *
*Description: Functions to simulate the Singly Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna Savina                                                         *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#ifndef __OL99_SLIST_H__
#define __OL99_SLIST_H__

#include <stddef.h> /* size_t */ 

typedef struct slist_node slist_node_t; 
typedef struct slist slist_t; 
typedef slist_node_t* slist_iter_t;


/******************************* Functions ************************************/
/*******************************************************************************
*
	Decription: 	create new linked list O(1)
	Output:			pointer to a new linked list, returns NULL if fails
*
*******************************************************************************/
slist_t *SListCreate(void);

/*******************************************************************************
*
	Decription: 	Deletes linkedd list and frees all allocations O(n)
*
*******************************************************************************/
void SListDestroy(slist_t *slist);

/*******************************************************************************
*
	Decription: 	Returns iterator to the beginning of linked list O(1)
*
*******************************************************************************/
slist_iter_t SListBegin(const slist_t *slist);

/*******************************************************************************
*
	Decription: 	Returns iterator to the end of the linked list O(1)
*
*******************************************************************************/
slist_iter_t SListEnd(const slist_t *slist);

/*******************************************************************************
*
	Decription: 	returns iterator to next element O(1)
*
*******************************************************************************/
slist_iter_t SListNext(const slist_iter_t iter); 

/*******************************************************************************
*
	Decription: 	Compares two iterators O(1)	
	Output:			1 if iterators are the same, 0  if different
*
*******************************************************************************/            
int SListIsSameIterator(const slist_iter_t iter1 ,const slist_iter_t iter2);

/*******************************************************************************
*
	Decription: 	Gets data from node of linked list	O(1)
*
*******************************************************************************/
void *SListGetData(const slist_iter_t iter);

/*******************************************************************************
*
	Decription: 	Assigns data to a node O(1)
*
*******************************************************************************/
void SListSetData(slist_iter_t iter, void *data);

/*******************************************************************************
*
	Decription: 	Inserts a node into the linked list	O(1)
	If failed, returns iter.
*
*******************************************************************************/
slist_iter_t SListInsert(slist_iter_t where, void *data);

/*******************************************************************************
*
	Decription: 	Removes a node from the linked list	O(1)
	returns iter to next node after the one removed
*
*******************************************************************************/
slist_iter_t SListRemove(slist_iter_t iter);

/*******************************************************************************
*
	Decription: 	Returns size of the linked list O(n) 
*
*******************************************************************************/
size_t SListSize(const slist_t *slist);

/*******************************************************************************
*
	Decription: 	Checks if linked list is empty	O(1)
	returns 1 if linked list is empty, other value if not
*
*******************************************************************************/
int SListIsEmpty(const slist_t *slist);

/*******************************************************************************
*
	Decription: 	Searches linked list in specific range for requested element	
*
*******************************************************************************/
slist_iter_t SListFind(
    slist_iter_t from,
    slist_iter_t to,
    int (*is_match)(const void *data, void *param),
    void *param
	);

/*******************************************************************************
*
	Decription: 	Applies user defined function to a range of elements	
	returns output of action function 	
*
*******************************************************************************/
int SListForEach(
    slist_iter_t from,
    slist_iter_t to,
    int (*action)(void *data, void *param),
    void *param
    );

/*******************************************************************************
*
	Decription: Appends 2 given lists
*
*******************************************************************************/
void SListAppend(slist_t *dest, slist_t *src);


#endif /* __OL99_SLIST_H__ */


