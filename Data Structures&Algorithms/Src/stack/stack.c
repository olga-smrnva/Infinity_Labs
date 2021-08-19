/*******************************************************************************
*                                                                              *
*File: stack.c                                                                 *
*Description: Functions to simulate the Stack                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Zeyad Mahagna                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/
#include <stddef.h>	/*size_t */
#include <string.h>    /* memset */
#include <stdlib.h>    /*mallocs*/
#include <assert.h>
#include "stack.h"

struct stack
{
	void **elements;
	size_t capacity;
	size_t top_of_stack; 
};

/******************************* Functions ************************************/

/***** Creates a new stack_t stack, if create fails, returns NULL pointer *****/

stack_t *StackCreate(size_t capacity)
{
	size_t size_counter = sizeof(stack_t) + (sizeof(void *)*capacity);
	stack_t* stack = (stack_t *)malloc(size_counter);
	
	if (NULL == stack)
	{
	         return NULL;
	}
	
	memset(stack, 0 ,size_counter);
	
	stack->elements = (void**)(stack+1);
	stack->capacity = capacity;
	stack->top_of_stack = 0;
	
	return stack;
}


/***************** Frees memory allocation of the stack ***********************/

void StackDestroy(stack_t *stack)
{
	free(stack);
	stack = NULL;
}


/***************** Adds a new element to the top of the stack *****************/

void StackPush(stack_t *stack, void *element)
{
	assert(stack);
	assert(element);
    
	*stack->elements = element;
	stack->elements++;
	++stack->top_of_stack;
}


/***************** Pops an element from the top of the stack ******************/

void StackPop(stack_t *stack)
{
	assert(stack);
    
	*stack->elements = NULL;
	--stack->elements;
	--stack->top_of_stack;
}


/***************** Peeks at the element on the top of the stack ***************/

void *StackPeek(stack_t *stack)
{
	assert(stack);

	return *(stack->elements -1);
}	 


/***************** Getts current number of elements inside stack **************/

size_t StackSize(stack_t *stack)
{
	return stack->top_of_stack;
}	 


/***************** Checks if the stack contains any elements ******************/

int StackIsEmpty(stack_t *stack)
{
	return 0 == stack->top_of_stack;
}


/********** Returns number of elements that can be pushed onto the stack ******/

size_t StackCapacity(stack_t *stack)
{
	return stack->capacity;
}
 


