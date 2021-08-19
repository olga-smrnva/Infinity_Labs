/*****************************************************************
*                                                                *
*File: struct_arr.c                                              *
*Description: Program that creates an array of elements,         *
 print them to the screen, and can add to each element           *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* malloc, realloc */
#include <string.h>   /* strlen, strcat*/
#include <assert.h>   

#include "struct_arr.h"


/**********************Add Functions*****************************/

int AddtoArr(generic_type_t arr[], int to_add, size_t size)
{
	size_t i = 0;
	for (i=0; i < size; ++i)
	{
		arr[i].Add(&arr[i], to_add);
	}
	return 0;
}

int AddInt(generic_type_t *struct_int, int to_add)
{
	assert(struct_int);
	
	*(int *)&struct_int->element += to_add;
	
	return 0;
}

int AddFloat(generic_type_t *struct_float, int to_add)
{
	assert(struct_float);
	
	*(float *)&struct_float->element += to_add;
	
	return 0; 
}

int AddChar(generic_type_t *struct_char, int to_add)
{
	char str_to_add[10] = "";
	size_t len_s = 0;
	size_t len_a = 0;
	
	assert(struct_char);
	
	sprintf(str_to_add, "%d", to_add); 
	
	len_s = strlen((char *)(&struct_char->element));
	len_a = strlen(str_to_add);
	
	struct_char->element = realloc(struct_char->element, len_s + len_a + 1);

	if (NULL == struct_char->element)
	{
		return 1;
	}
	
	strcat(struct_char->element, str_to_add);
	
	return 0;
}


/**********************Print Functions***************************/

void PrintArr(generic_type_t arr[], size_t size)
{
	size_t i = 0;
	
	for (i =0; i < size; ++i)
	{
		arr[i].Print(&arr[i]);
	}
}

void PrintInt(generic_type_t *struct_int)
{
	assert(struct_int);
	
	printf("%d\n", *(int *)&struct_int->element);
}

void PrintFloat(generic_type_t *struct_float)
{
	assert(struct_float);
	
	printf("%f\n", *(float *)&struct_float->element);
}

void PrintChar(generic_type_t *struct_char)
{
	assert(struct_char);
	
	printf("%s\n", (char *)struct_char->element);
}


/**********************Clean Functions***************************/

void CleanArr(generic_type_t arr[], size_t size)
{
	size_t i = 0;
	for (i=0; i < size; ++i)
	{
		arr[i].Clean(&arr[i]);
	}
}

void CleanChar(generic_type_t *struct_char)
{
	assert(struct_char);
	
	free(struct_char->element);
	struct_char->element = NULL;
}

void NoClean(generic_type_t *struct_int)
{
	(void)struct_int;
}


/**********************Initializing Functions********************/

int InitInt(generic_type_t *struct_int, int x)
{
	assert(struct_int);
	
	struct_int->element = *(void **)&x;
	struct_int->Print = PrintInt;
	struct_int->Add = AddInt;
	struct_int->Clean = NoClean;
	
	return 0;
}

int InitFloat(generic_type_t *struct_float, float y)
{
	assert(struct_float);
	
	struct_float->element = *(void **)&y;
	struct_float->Print = PrintFloat;
	struct_float->Add = AddFloat;
	struct_float->Clean = NoClean;
	
	return 0;
}

int InitChar(generic_type_t *struct_char, char *str)
{
	assert(struct_char);
	
	struct_char->element = malloc(strlen(str) + 1);
	
	if (NULL == struct_char->element)
	{
		return 1;
	}
	
	strcpy((char *)struct_char->element, str);
	struct_char->Print = PrintChar;
	struct_char->Add = AddChar;
	struct_char->Clean = CleanChar;
	
	return 0;
}














