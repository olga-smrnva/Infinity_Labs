/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: queue_test.c                                                            *
*Description: Functions to simulate the Queue                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Moshe Frydman                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>		/* printf */
#include <stddef.h>		/* size_t */

#include "queue.h"	

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"	

int TestQueue(void);
int TestQAppend(void);

void IsTestPassed(size_t result, size_t expected, const char *f_name);

int main(void)
{
	TestQueue();
	TestQAppend();
	
	return 0;
}

int TestQueue(void)
{
	int is_empty = 0;
	size_t size = 0;
	size_t result = 0;

/******************************* QCreate **************************************/
	
	queue_t *p_queue = QCreate();
	
	printf(KYEL"\nTEST for QUEUE\n\n"KNRM);

	if (NULL == p_queue)
	{
	         printf(KRED"Queue wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Queue created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* QIsEmpty *************************************/
    
	is_empty = QIsEmpty(p_queue);
	printf("To begin with we check is our new queue IS EMPTY: ");
	if(1 == is_empty)
	{
		printf(KGRN"YES, it is\n\n"KNRM);
	}
	else
	{
		printf(KRED"NO, it is not. Houston, we have a problem\n\n"KNRM);
	}

/******************************* QSize ****************************************/
    
	size = QSize(p_queue);
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu\n\n"KNRM, size);

/******************************* QEnqueue *************************************/

	printf("Now let's ENQUEUE several elements. ");
	
	QEnqueue(p_queue,(void *)1);
	QEnqueue(p_queue,(void *)2);
	QEnqueue(p_queue,(void *)3);
	
	result = QSize(p_queue);
	IsTestPassed(result, 3, "Function QEnqueue");

/******************************* QDequeue *************************************/

	printf("Now let's DEQUEUE an element. ");
	
	QDequeue(p_queue);
	
	result = QSize(p_queue);
	IsTestPassed(result, 2, "Function QDequeue");
	
/******************************* QPeek ****************************************/

	printf("Now let's PEEK an element. ");
	
	result = (size_t)QPeek(p_queue);
	IsTestPassed(result, 2, "Function QDequeue");

/******************************* QDestroy *************************************/
    
    printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
    
	QDestroy(p_queue);
	p_queue = NULL;
	
	return 0;

}


/******************************* Test for QAppend *****************************/

int TestQAppend()
{
	size_t size = 0;

/******************************* QCreate **************************************/
	
	queue_t *p_queue_to_append = QCreate();
	queue_t *p_queue_from_append = QCreate();
	
	
	printf(KYEL"\n\nTEST for Queue APPEND \n\n"KNRM);
	
	if (NULL == p_queue_to_append)
	{
	         printf(KRED"Queue to append wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Queue to append created SUCCESSFULLY\n\n"KNRM);
	}
	
	if (NULL == p_queue_from_append)
	{
	         printf(KRED"Queue from append wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Queue from append created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* QEnqueue *************************************/

	QEnqueue(p_queue_to_append,(void *)1);
	QEnqueue(p_queue_to_append,(void *)2);
	QEnqueue(p_queue_to_append,(void *)3);
	
	size = QSize(p_queue_to_append);
	printf("The SIZE of the queue to append is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 3, "Enqueue");
	
	QEnqueue(p_queue_from_append,(void *)1);
	QEnqueue(p_queue_from_append,(void *)2);
	QEnqueue(p_queue_from_append,(void *)3);
	
	size = QSize(p_queue_from_append);
	printf("The SIZE of the queue from append is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 3, "Enqueue");

/******************************* QAppend **************************************/

	QAppend(p_queue_to_append, p_queue_from_append);
	
	size = QSize(p_queue_to_append);
	printf("The SIZE of the queue to append (after) is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 6, "Function SListAppend");
	
	size = QSize(p_queue_from_append);
	printf("The SIZE of the queue from append (after) is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 0, "Function SListAppend");
	
	printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);

/******************************* QDestroy *************************************/

	QDestroy(p_queue_from_append);
	p_queue_from_append = NULL;
	
	QDestroy(p_queue_to_append);
	p_queue_to_append = NULL;
	
	return 0;
}

/******************************* Helping functions ****************************/
/******************************* Checks if test passed ************************/

void IsTestPassed(size_t result, size_t expected, const char *f_name)
{
	if(result != expected)
	{
		printf(KRED"\n%s FAILED\n\n"KNRM, f_name);
	}
	else
	{
		printf(KGRN"\n%s SUCCEEDED\n\n"KNRM, f_name);
	}
}
