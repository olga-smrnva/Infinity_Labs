/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: queue.h                                                                 *
*Description: Functions to simulate the Queue                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Moshe Frydman                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/


#ifndef __OL99_QUEUE_H__
#define __OL99_QUEUE_H__

#include <stddef.h>		/* size_t */

typedef struct queue queue_t;


/******************************* Functions ************************************/
/*******************************************************************************
*
	Decription: Create new queue_t queue (returns pointer to new created queue)		

	Time Complexity: O(1)		
*
*******************************************************************************/
queue_t *QCreate(void);

/*******************************************************************************
*
	Decription: Destroy queue_t queue
		
	Time Complexity: O(n)			
*
*******************************************************************************/
void QDestroy(queue_t *queue);

/*******************************************************************************
*
	Decription: Adds element to the rear of the queue 
												  (returns success/error status)
	
	Time Complexity: O(1)	
*
*******************************************************************************/
int QEnqueue(queue_t *queue, void *data);

/*******************************************************************************
*
	Decription: Dequeue from the front queue
		
	Time Complexity: O(1)	
*
*******************************************************************************/
void QDequeue(queue_t *queue);

/*******************************************************************************
*
	Decription: Returns the element at the front		
	
	Time Complexity: O(1)			
*
*******************************************************************************/
void *QPeek(const queue_t *queue);

/*******************************************************************************
*
	Decription: returns 1 if queue is empty, 0 if not	

	Time Complexity: O(1)	
*
*******************************************************************************/
int QIsEmpty(const queue_t *queue);

/*******************************************************************************
*
	Decription: Returns the size size of queue		

	Time complexity: O(n)		
*
*******************************************************************************/
size_t QSize(const queue_t *queue);

/*******************************************************************************
*
	Decription: Append src to dest, src is an empty queue at the end of process

	Time complexity: O(1)	
*
*******************************************************************************/
void QAppend(queue_t *dest, queue_t *src);


#endif /* __OL99_QUEUE_H__*/

