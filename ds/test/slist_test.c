/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: slist_test.c                                                            *
*Description: Functions to simulate the Singly Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna Savina                                                         *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */

#include "slist.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

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

int TestSlist();
int TestSlistAppend();
void IsTestPassed(size_t result, size_t expected, const char *f_name);

int IsMatch(const void *data, void *param);
int Action(void *data, void *param);

int main()
{
	TestSlist();
	TestSlistAppend();

	return 0;
}

int TestSlist()
{
	int is_empty = 0;
	size_t size = 0;
	size_t result = 0;
	
	slist_iter_t iter = NULL; 
	slist_iter_t iter_from = NULL; 
	slist_iter_t iter_to = NULL;
	
	
/******************************* SlistCreate **********************************/
    
	slist_t *p_list = SListCreate();
	    
	printf(KYEL"\nTEST for Singly Linked List\n\n"KNRM);

	if (NULL == p_list)
	{
	         printf(KRED"List wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"List created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* SListIsEmpty *********************************/
    
	is_empty = SListIsEmpty(p_list);
	printf("To begin with we check is our new list IS EMPTY: ");
	if(1 == is_empty)
	{
		printf(KGRN"YES, it is\n\n"KNRM);
	}
	else
	{
		printf(KRED"NO, it is not. Houston, we have a problem\n\n"KNRM);
	}
	
/******************************* SListSize ************************************/
    
	size = SListSize(p_list);
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu\n\n"KNRM, size);
	
/******************************* SListInsert **********************************/
/******************************* SListGetData *********************************/
/******************************* SListBegin ***********************************/
/******************************* SListEnd *************************************/

	printf("Now let's INSERT an element. ");
	printf("To make WHERE be the 1st node we use SListBegin: \n"); 
	
	printf("\n(To compare our result with the expected we use SListGetData)\n");
	
	iter = SListBegin(p_list);
	SListInsert(iter,(void *)2);
	result = (size_t )SListGetData(iter);
	IsTestPassed(result, 2, "Functions SListInsert and SListBegin");
	
	printf("Now we INSERT one more node: \n"); 
	
	SListInsert(iter,(void *)1);
	result = (size_t )SListGetData(iter);
	IsTestPassed(result, 1, "Function SListInsert");
	
	printf("To make WHERE be the last node and insert one more node we use SListEnd: \n"); 
	
	iter = SListEnd(p_list);
	SListInsert(iter,(void *)3);
	result = (size_t )SListGetData(iter);
	IsTestPassed(result, 3, "Functions SListInsert and SListEnd");	
	
/******************************* SListSetData *********************************/

	printf("Now I want to SET the element to 5 \n\n");
	printf("The value before SET is: %lu \n\n", result);
	SListSetData(iter, (void *)5);
	result = (size_t )SListGetData(iter);
	printf("The value after SET is: %lu \n", result);
	IsTestPassed(result, 5, "Function SListSetData");
	
/******************************* SListSize ************************************/	
	
	size = SListSize(p_list);
	printf("After 3 INSERTS the SIZE is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 3, "All the INSERTS");
	
/******************************* SListFind ************************************/
	
	printf("Now let's test SListFind function: \n");
	iter_from = SListBegin(p_list);
	iter_to = SListEnd(p_list);
	iter = SListFind(iter_from, iter_to, IsMatch, (void *)5);
	result = (size_t)SListGetData(iter);
	IsTestPassed(result, 5, "Function SListFind");

/******************************* SListForEach *********************************/

	printf("Now let's test SListForEach function: \n");
	result =  (size_t)SListForEach(iter_from, iter_to, Action, (void *)2);
	IsTestPassed(result, 0, "Function SListForEach");
	
/******************************* SListRemove **********************************/	
	
	SListRemove(iter);
	
	size = SListSize(p_list);
	printf("It's time to REMOVE! The SIZE after removal is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 2, "Function SListRemove");

/******************************* SlistDestroy *********************************/
    
    printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
    
	SListDestroy(p_list);
	p_list = NULL;
	
	return 0;
}


/******************************* Test for SListAppend *************************/

int TestSlistAppend()
{
	size_t size = 0;
		
	slist_iter_t iter_a = NULL;
	slist_iter_t iter_t = NULL;
	
/******************************* SlistCreate **********************************/
	
	slist_t *p_list_to_append = SListCreate();
	slist_t *p_list_from_append = SListCreate();
	
	printf(KYEL"\n\nTEST for Singly Linked List APPEND \n\n"KNRM);
	
	if (NULL == p_list_to_append)
	{
	         printf(KRED"List to append wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"List to append created SUCCESSFULLY\n\n"KNRM);
	}
	
	if (NULL == p_list_from_append)
	{
	         printf(KRED"List from append wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"List from append created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* SListInsert **********************************/
	
	iter_a = SListBegin(p_list_from_append);
	SListInsert(iter_a,(void *)1);
	SListInsert(iter_a,(void *)2);
	SListInsert(iter_a,(void *)3);
	
	iter_t = SListBegin(p_list_to_append);
	SListInsert(iter_t,(void *)1);
	SListInsert(iter_t,(void *)2);
	SListInsert(iter_t,(void *)3);
	
	size = SListSize(p_list_to_append);
	printf("The SIZE of list from we append is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 3, "Function SListInsert to list to append ");
	
	size = SListSize(p_list_to_append);
	printf("The SIZE of list where we append is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 3, "Function SListInsert to list to append ");
	
	printf("Now let's test SListAppend function \n\n");

/******************************* SlistAppend **********************************/
	
	SListAppend(p_list_to_append, p_list_from_append);
	
	size = SListSize(p_list_to_append);
	printf("The SIZE of the list WHERE we APPEND (after) is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 6, "Function SListAppend");
	
	size = SListSize(p_list_from_append);
	printf("The SIZE of the list FROM WHICH we APPEND (after) is: ");
	printf(KGRN"%lu\n"KNRM, size);
	IsTestPassed(size, 0, "Function SListAppend");
	
	printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
    
/******************************* SlistDestroy *********************************/

	SListDestroy(p_list_from_append);
	p_list_from_append = NULL;
	
	SListDestroy(p_list_to_append);
	p_list_to_append = NULL;
	
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


/******************************* IsMatch function *****************************/

int IsMatch(const void *data, void *param)
{
	return ((int)(long)data == (int)(long)param);
}


/******************************* Action function ******************************/

int Action(void *data, void *param)
{
	int sum = (int)(long)data + (int)(long)param;
	(void) sum;
	
	return 0;
}

