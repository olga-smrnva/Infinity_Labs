/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: dlist_test.c                                                            *
*Description: Functions to simulate the Double Linked List                     *
*Author: Olga Smirnova                                                         *
*Reviewer:                                                                     *
*Status: in development                                                        *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* ssize_t, size_t */
#include <stdio.h>		/* printf */

#include "dlist.h"	

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"	

int TestDList(void);
void IsTestPassed(size_t res, size_t exp, const char *f_name, const int line);

int IsMatch(const void *data, void *param);
int Action(void *data, void *param);

int main(void)
{
	TestDList();
	
	return 0;
}

int TestDList(void)
{
	int is_empty = 0;
	size_t size = 0;
	size_t result = 0;
	dlist_iter_t iter = {0}; 

/******************************* DListCreate **********************************/

	dlist_t *p_list = DListCreate();
	    
	printf(KYEL"\nTEST for Double Linked List\n\n"KNRM);

	if (NULL == p_list)
	{
	         printf(KRED"List wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"List created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* DListIsEmpty *********************************/

	is_empty = DListIsEmpty(p_list);
	
	printf("To begin with we check is our new list IS EMPTY: ");
	if(1 == is_empty)
	{
		printf(KGRN"YES, it is"KNRM);
	}
	else
	{
		printf(KRED"NO, it is not. Houston, we have a problem"KNRM);
	}

	IsTestPassed(is_empty, 1, "Function DListIsEmpty", __LINE__);
		
/******************************* DListSize ************************************/

	size = DListSize(p_list);
	
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 0, "Function DListSize", __LINE__);
	
/******************************* DListInsert **********************************/
/******************************* DListGetData *********************************/
/******************************* DListBegin ***********************************/
/******************************* DListEnd *************************************/

	printf("Now let's INSERT an element. ");
	printf("To make WHERE be the 1st node we use DListBegin: \n"); 
	
	printf("\n(To compare our result with the expected we use DListGetData)\n");
	
	iter = DListInsert(DListEnd(p_list),(void *)2);
	/*DListSetData(iter, (void *)5);*/
	result = (size_t )DListGetData(iter);
	IsTestPassed(result, 2, "Functions DListInsert and DListEnd", __LINE__);
	
/******************************* DListDestroy *********************************/

    printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
    
	DListDestroy(p_list);
	p_list = NULL;
	
	return 0;
}



/******************************* Helping functions ****************************/
/******************************* Checks if test passed ************************/

void IsTestPassed(size_t res, size_t exp, const char *f_name, const int line)
{
	if(res != exp)
	{
		printf(KRED"\n%s FAILED on line %d\n\n"KNRM, f_name, line);
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

