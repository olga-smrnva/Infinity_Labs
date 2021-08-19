/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: queue.c                                                                 *
*Description: Functions to simulate the Queue                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Moshe Frydman                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */

#include "queue.h"
#include "slist.h"

struct queue 
{
	slist_t *slist;
};

/******************************* Functions ************************************/
/*******************************************************************************
*
	Decription: Create new queue_t queue (returns pointer to new created queue)		
	Time Complexity: O(1)		
	
	Reviewer: Moshe Frydman                                                   
	Status: approved
*
*******************************************************************************/
queue_t *QCreate(void)
{
	queue_t *p_queue = malloc(sizeof(queue_t));

	if(NULL == p_queue)
	{
		return NULL;
	}

	p_queue->slist = SListCreate();
	
	return p_queue;
}

/*******************************************************************************
*
	Decription: Destroy queue_t queue
	Time Complexity: O(n)	
	
	Reviewer: Moshe Frydman                                                   
	Status: approved		
*
*******************************************************************************/
void QDestroy(queue_t *queue)
{
	assert(queue);

	SListDestroy(queue->slist);
	queue->slist = NULL;
	
	free(queue);
	queue = NULL;
}

/*******************************************************************************
*
	Decription: Adds element to the rear of the queue 
												  (returns success/error status)
	Time Complexity: O(1)	
	
	Reviewer: Moshe Frydman                                                   
	Status: approved
*
*******************************************************************************/
int QEnqueue(queue_t *queue, void *data)
{
	assert(queue);
		
	return (SListInsert(SListEnd(queue->slist), data) == SListEnd(queue->slist));
}

/*******************************************************************************
*
	Decription: Dequeue from the front queue
	Time Complexity: O(1)	
	
	Reviewer: Moshe Frydman                                                   
	Status: approved
*
*******************************************************************************/
void QDequeue(queue_t *queue)
{
	assert(queue);
	
	SListRemove(SListBegin(queue->slist));
}

/*******************************************************************************
*
	Decription: Returns the element at the front		
	Time Complexity: O(1)
	
	Reviewer: Moshe Frydman                                                   
	Status: approved		
*
*******************************************************************************/
void *QPeek(const queue_t *queue)
{
	assert(queue);
	
	return SListGetData(SListBegin(queue->slist));
}

/*******************************************************************************
*
	Decription: returns 1 if queue is empty, 0 if not	
	Time Complexity: O(1)	
	
	Reviewer: Moshe Frydman                                                   
	Status: approved
*
*******************************************************************************/
int QIsEmpty(const queue_t *queue)
{
	assert(queue);
	
	return SListIsEmpty(queue->slist);
}

/*******************************************************************************
*
	Decription: Returns the size size of queue		
	Time complexity: O(n)
	
	Reviewer: Moshe Frydman                                                   
	Status: approved	
*
*******************************************************************************/
size_t QSize(const queue_t *queue)
{
	assert(queue);
	
	return SListSize(queue->slist);
}

/*******************************************************************************
*
	Decription: Append src to dest, src is an empty queue at the end of process
	Time complexity: O(1)	
	
	Reviewer: Moshe Frydman                                                   
	Status: approved
*
*******************************************************************************/
void QAppend(queue_t *dest, queue_t *src)
{
	assert(dest);
	assert(src);
	
	SListAppend(dest->slist, src->slist);
}


