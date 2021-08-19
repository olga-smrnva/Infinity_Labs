/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: cbuffer_test.c                                                          *
*Description: Functions to simulate the Circular Buffer                        *
*Author: Olga Smirnova                                                         *
*Reviewer: Pavel Voropaev                                                      *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* ssize_t, size_t */
#include <stdio.h>		/* printf */
#include <errno.h>		/* errno */

#include "cbuffer.h"	

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"	

int TestCBuffer(void);
void IsTestPassed(size_t res, size_t exp, const char *f_name, const int line);

int main(void)
{
	TestCBuffer();
	
	return 0;
}

int TestCBuffer(void)
{
	int is_empty = 0;

	size_t capacity = 8;
	size_t count_w = 3;
	size_t count_r = 2;
	size_t size = 0;
	size_t free = 0;
	ssize_t result = 0;

	char *src = "Ololo";
	char dest[10] = {0};
	
/******************************* CBufferCreate ********************************/

	cbuffer_t *p_cbuffer = CBufferCreate(capacity);

	printf(KYEL"\nTEST for CIRCULAR BUFFER\n\n"KNRM);

	if (NULL == p_cbuffer)
	{
		     printf(KRED"Circular buffer wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Circular buffer created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* CBufferIsEmpty *******************************/

	is_empty = CBufferIsEmpty(p_cbuffer);
	
	printf("To begin with we check is our new circular buffer IS EMPTY: ");
	if(1 == is_empty)
	{
		printf(KGRN"YES, it is"KNRM);
	}
	else
	{
		printf(KRED"NO, it is not. Houston, we have a problem"KNRM);
	}

	IsTestPassed(is_empty, 1, "Function CBufferIsEmpty", __LINE__);
	
/******************************* CBufferSize **********************************/

	size = CBufferSize(p_cbuffer);
	
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 0, "Function CBufferSize", __LINE__);

/******************************* CBufferFreeSpace *****************************/

	free = CBufferFreeSpace(p_cbuffer);
	
	printf("At the beginning the FREE SPACE is: ");
	printf(KGRN"%lu"KNRM, free);
	IsTestPassed(free, capacity, "Function CBufferFreeSpace", __LINE__);
	
/******************************* CBufferWrite *********************************/

	printf("Now let's WRITE several elements. ");

	result = CBufferWrite(p_cbuffer, src, count_w);
	printf("The number ob bytes we WRITE is: ");
	printf(KGRN"%lu\n\n"KNRM, result);

	size = CBufferSize(p_cbuffer);
	printf("After writing 3 bytes the SIZE is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 3, "Function WRITE", __LINE__);
	
	free = CBufferFreeSpace(p_cbuffer);
	printf("After writing 3 bytes the FREE SPACE is: ");
	printf(KGRN"%lu"KNRM, free);
	IsTestPassed(free, (capacity - size), "Function WRITE", __LINE__);
	
/******************************* CBufferRead **********************************/

	printf("Now let's READ several elements. ");

	result = CBufferRead(p_cbuffer, dest, count_r);
	printf("The number ob bytes we READ is: ");
	printf(KGRN"%lu\n\n"KNRM, result);

	size = CBufferSize(p_cbuffer);
	printf("After reading 2 bytes the SIZE is: ");
	printf(KGRN"%lu"KNRM, size);
	IsTestPassed(size, 1, "Function READ", __LINE__);
	
	free = CBufferFreeSpace(p_cbuffer);
	printf("After reading 2 bytes the FREE SPACE is: ");
	printf(KGRN"%lu"KNRM, free);
	IsTestPassed(free, (capacity - size), "Function READ", __LINE__);

/******************************* CBufferDestroy *******************************/

    printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
    
	CBufferDestroy(p_cbuffer);
	p_cbuffer = NULL;
	
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
