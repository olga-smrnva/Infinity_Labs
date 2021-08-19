/*******************************************************************************
*                                                                              *
*File: stack.h                                                                 *
*Description: Functions to simulate the Stack                                  *
*Author: Olga Smirnova                                                         *
*Reviewer: Zeyad Mahagna                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h>	/*size_t */

typedef struct stack stack_t;

/******************************* Functions ************************************/

/***** Creates a new stack_t stack, if create fails, returns NULL pointer *****/
stack_t *StackCreate(size_t capacity);


/***************** Frees memory allocation of the stack ***********************/
void StackDestroy(stack_t *stack);	


/***************** Adds a new element to the top of the stack *****************/
void StackPush(stack_t *stack, void *element);


/***************** Pops an element from the top of the stack ******************/
void StackPop(stack_t *stack);


/***************** Peeks at the element on the top of the stack ***************/
void *StackPeek(stack_t *stack);	 


/***************** Getts current number of elements inside stack **************/
size_t StackSize(stack_t *stack);	 


/***************** Checks if the stack contains any elements ******************/
int StackIsEmpty(stack_t *stack);


/********** Returns number of elements that can be pushed onto the stack ******/
size_t StackCapacity(stack_t *stack); 
 
 
#endif /* __STACK_H__ */




