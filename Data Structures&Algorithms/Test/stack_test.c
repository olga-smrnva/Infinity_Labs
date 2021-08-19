/*******************************************************************************
*                                                                              *
*File: stack_test.c                                                            *
*Description: Functions to simulate the Stack                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Zeyad Mahagna                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */

#include "stack.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

int TestStack();

int main()
{
	TestStack();

	return 0;
}

int TestStack()
{
	int num = 0;
	size_t to_push = 12345;
	size_t capacity = 0;
	size_t size = 0;
	size_t peek = 0;
	char *str = "The TOP element";
	char *str_peek = NULL;

/******************************* Srack Create**********************************/
    
	stack_t *stack = StackCreate(10);
    
    	printf(KYEL"\nTEST for Stack\n\n"KNRM);
    	
/******************************* StackIsEmpty *********************************/    	
    	
	num = StackIsEmpty(stack);
	printf("At the beginning is the STACK EMPTY? (1 - yes, 0 - no) ");
	printf(KGRN"%d\n\n"KNRM, num);
	
/******************************* StackCapasity ********************************/
    
	capacity = StackCapacity(stack);
	printf("CAPACITY (number of elements that can be pushed): ");
	printf(KGRN"%lu\n\n"KNRM, capacity);
	
/******************************* StackSize ************************************/
    
	size = StackSize(stack);
	printf("At the beginning the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu\n\n"KNRM, size);
    
/******************************* StackPush ************************************/
    
	StackPush(stack, &to_push);
	printf("The first STACK PUSH is (number): ");
	printf(KGRN"%lu\n\n"KNRM, to_push);
    
/******************************* StackPeek ************************************/
    
	peek = *(size_t *)StackPeek(stack);
	printf("Now the STACK PEEK element on the top is: ");
	printf(KGRN"%lu\n\n"KNRM, peek);
    
/******************************* StackPush ************************************/
        
	StackPush(stack, (void*)str);
	printf("The second STACK PUSH is (string): ");
	printf(KGRN"%s\n\n"KNRM, str);
    
/******************************* StackPeek ************************************/    
    
	str_peek = (char *)StackPeek(stack);
	printf("Now the STACK PEEK element on the top is: "); 
	printf(KGRN"%s\n\n"KNRM, str_peek);
    
/******************************* StackPop *************************************/    
    
	StackPop(stack);
    
/******************************* StackPeek ************************************/    
    
	peek = *(size_t *)StackPeek(stack);
	printf("After the STACK POP the STACK PEEK element on the top is: ");
	printf(KGRN"%lu\n\n"KNRM, peek);

/******************************* StackIsEmpty *********************************/
    
	num = StackIsEmpty(stack);
	printf("And now is the STACK EMPTY? (1 - yes, 0 - no) ");
	printf(KGRN"%d\n\n"KNRM, num);
    
/******************************* StackSize ************************************/    
    
	size = StackSize(stack);
	printf("And now the SIZE (current № of elements inside) is: ");
	printf(KGRN"%lu\n\n"KNRM, size);
	
	printf("Looks like everything is OK :-) \n");
	printf("It's time to ");
	printf(KRED"DESTROY!\n\n"KNRM);

/******************************* StackDestroy *********************************/
    
	StackDestroy(stack);
    
	if (stack == NULL)
	{
		printf(KRED"Stack wasn't destroyed\n\n"KNRM);
	}
	else
	{
		printf(KGRN"Stack Destroyed SUCCESSFULLY\n\n"KNRM);
	}
    
	return 0;
}
