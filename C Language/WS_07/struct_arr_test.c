/*****************************************************************
*                                                                *
*File: struct_arr.c                                              *
*Description: Program to test struct_arr.c                       *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
  
#include "struct_arr.h"

#define LEN 3

int main()
{
	generic_type_t arr[LEN];
	
	InitInt(&arr[0], 7);
	InitFloat(&arr[1], 5.000001);
	InitChar(&arr[2], "Hello");
	
	AddtoArr(arr, 10, LEN);
	PrintArr(arr, LEN);
	CleanArr(arr, LEN);

	return 0;
}
