/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: dvector.c                                                               *
*Description: Functions to simulate the Dynamic Vector                         *
*Author: Olga Smirnova                                                         *
*Reviewer: Zeyad Mahagna                                                       *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */

#include "dvector.h"

#define GROWTH_FACTOR (2)
#define REDUCE_FACTOR (2)
#define REDUCE_FACTOR_LIMIT (4)

struct vector
{
    void **elements;
    size_t capacity;
    size_t size;
};

/******************************* Functions ************************************/

/*******************************************************************************
*
	Decription: 	creating a new vector_t Vector; O(1)
	Return Value:	returns a pointer to the new struct
*  
*******************************************************************************/
vector_t *VectorCreate(size_t initial_capacity)
{
	vector_t *vector = (vector_t *)malloc(sizeof(vector_t));

	if (NULL == vector)
	{
		return NULL;
	}

	vector->capacity = initial_capacity;
	vector->size = 0;
	vector->elements = (void **)malloc(sizeof(void*) * initial_capacity);

	if (NULL == vector->elements)
	{
		free(vector);
		return NULL;
	}

	return vector;
}


/*******************************************************************************
*
	Decription: 	freeing memory allocation of a Vector; O(1)
*
*******************************************************************************/		
void VectorDestroy(vector_t *vector)
{
	assert(vector);
	
	vector->capacity = 0;
	vector->size = 0;
	
	free(vector->elements);
	vector->elements = NULL;
	
	free(vector);
	vector = NULL;
}


/*******************************************************************************
*
	Decription: 	adding a new element to the end of a VectorCreate, if 
					capacity is equal to size, 
					vector is reallocated to capacity multiplied by growth 
					factor; O(1)
	Return Value:	returns 0 successful and other if failed
*
*******************************************************************************/	
int VectorPushBack(vector_t *vector, void *element)
{
	int status = 0;

	assert(vector);

	if (vector->capacity == vector->size)
	{
		status = VectorReserve(vector, vector->capacity * GROWTH_FACTOR);
	}

	vector->elements[vector->size] = element;
	++vector->size;

	return status;
}


/*******************************************************************************
*
	Decription: 	poping an element from the end of a Vector; O(1)
*
*******************************************************************************/
void VectorPopBack(vector_t *vector)
{
	assert(vector);
	assert(0 < vector->size);
    
	--(vector->size);
	
	if (vector->size == (vector->capacity / REDUCE_FACTOR_LIMIT))
	{
		VectorReserve(vector, (vector->capacity / REDUCE_FACTOR));
	}
}


/*******************************************************************************
* 
	Decription: 	Re-allocate vector based on new_capacity. Unspecified if 
					new_capacity is less than size. O(1)
	Return Value:	returns 0 successful and other if failed
*
*******************************************************************************/
int VectorReserve(vector_t *vector, size_t new_capacity)
{
	void **temp = NULL;

	assert(vector);
	assert(new_capacity >= vector->size);

	temp = realloc(vector->elements, sizeof(void *) * new_capacity);
	
	if (NULL == temp)
	{
		return 1;
	}
	
	vector->elements = temp;
	
	vector->capacity = new_capacity;

	return 0;
}


/*******************************************************************************
*
	Decription: 	checking an amount of elements in Vector; O(1)
	Return Value:	returns the number of elements as size_t
*
*******************************************************************************/
size_t VectorSize(const vector_t *vector)
{
	assert(vector);
	
	return vector->size;
} 


/*******************************************************************************
*
   Decription: 	checking current capacity of Vector; O(1)
   Return Value:	returns the number of elements the structure can hold
*
*******************************************************************************/
size_t VectorCapacity(const vector_t *vector)
{
	assert(vector);
	
	return vector->capacity;
}


/*****************************************************************************/
/* 
	Decription: 	setting an specific element in a Vector.
			unspecified if index is bigger than size; O(1)
*/
void VectorSetElement(vector_t *vector, size_t index, void *element)
{
    assert(vector); 
    assert(index < vector->size);
    
    vector->elements[index] = element;
}


/*******************************************************************************
*
	Decription: 	getting specific element from Vector; O(1)
	Return Value:	returns the element as a void pointer
*
*******************************************************************************/
void *VectorGetElement(vector_t *vector,  size_t index)
{
	assert(vector);
	assert(index < vector->size);
	
   	return vector->elements[index];
}


/*******************************************************************************
*
	Decription: 	reallocate memory exactly to the current size; O(1)
	Return Value:	returns 0 if successful and other if failed
*
*******************************************************************************/
int VectorShrinkToFit(vector_t *vector)
{
	assert(vector);

	return VectorReserve(vector, vector->size);
}




