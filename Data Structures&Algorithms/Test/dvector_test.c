/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: dvector_test.c                                                          *
*Description: Functions to simulate the Dynamic Vector                         *
*Author: Olga Smirnova                                                         *
*Reviewer: Zeyad Mahagna                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */

#include "dvector.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

int TestVector();

int main()
{
	TestVector();

	return 0;
}

int TestVector()
{
	size_t initial_capacity = 10;
	size_t new_capacity = 30;
	
	size_t size = 0;
	size_t capacity = 0;
	
	size_t index1 = 1;
	
	int to_set1 = 7;
	int to_set2 = 77;
			
/******************************* VectorCreate *********************************/
    
	vector_t *vector = VectorCreate(initial_capacity);
	    
    printf(KYEL"\nTEST for Vector\n\n"KNRM);

	if (NULL == vector)
	{
	         printf(KRED"Vector wasn't created\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Vector created SUCCESSFULLY\n\n"KNRM);
	}

/******************************* VectorCapasity *******************************/
    
	capacity = VectorCapacity(vector);
	printf("At the beginning the CAPACITY (number of elements that can be pushed): ");
	printf(KGRN"%lu\n\n"KNRM, capacity);
	
/******************************* VectorSize ***********************************/
    
	size = VectorSize(vector);
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu\n\n"KNRM, size);
	
/******************************* VectorReserve ********************************/
    	
	VectorReserve(vector, new_capacity);
	
	capacity = VectorCapacity(vector);
	printf("CAPACITY after RESERVE: ");
	printf(KGRN"%lu\n\n"KNRM, capacity);
	
	size = VectorSize(vector);
	printf("SIZE after RESERVE: ");
	printf(KGRN"%lu\n\n"KNRM, size);	
	
/******************************* VectorPushBack *******************************/
/******************************* VectorGetElement *****************************/  	  	
    
	VectorPushBack(vector, &to_set1);
	printf("The first element to PUSH BACK is: ");
	printf(KGRN"%u\n\n"KNRM, to_set1);
	
	printf("The first element to GET: ");
	printf(KGRN"%d\n\n"KNRM, *(int *)VectorGetElement(vector, 0));
	
	size = VectorSize(vector);
	printf("SIZE after the first PUSH: ");
	printf(KGRN"%lu\n\n"KNRM, size);
	
	VectorPushBack(vector, &to_set2);
	printf("The second element to PUSH BACK is: ");
	printf(KGRN"%u\n\n"KNRM, to_set2);
	
	printf("The second element to GET: ");
	printf(KGRN"%d\n\n"KNRM, *(int *)VectorGetElement(vector, 1));
	
	size = VectorSize(vector);
	printf("SIZE after the second PUSH: ");
	printf(KGRN"%lu\n\n"KNRM, size);
		
/******************************* VectorSetElement *****************************/
	
	VectorSetElement(vector, index1, &to_set1);
	
	printf("Now we SET the second element to the value of 7 and GET: ");
	printf(KGRN"%d\n\n"KNRM, *(int *)VectorGetElement(vector, index1));
	
/******************************* VectorPop ************************************/

	VectorPopBack(vector);
    
	size = VectorSize(vector);
	printf("Now we do POP \n\nSIZE after POP is: ");
	printf(KGRN"%lu\n\n"KNRM, size);	
	
/******************************* VectorShrinkToFit ****************************/
	
	VectorShrinkToFit(vector);
	
	capacity = VectorCapacity(vector);
	printf("CAPACITY after SHRINK: ");
	printf(KGRN"%lu\n\n"KNRM, capacity);
	
	size = VectorSize(vector);
	printf("SIZE after SHRINK: ");
	printf(KGRN"%lu\n\n"KNRM, size);
	
	printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);
/******************************* VectorDestroy ********************************/
    
	VectorDestroy(vector);
	vector = NULL;
	
    
    return 0;
}
