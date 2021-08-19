/*********************************************************************
*                                                                    *
*File: endian.c                                                      *
*Description: Function to check whether the system is Little Endian  *
*Author: Olga Smirnova                                               *
*Reviewer: Benjamin Bitton                                           *
*                                                                    *
*********************************************************************/

#include <stdio.h>

#define IS_LITTLE_ENDIAN ((char *)(1) == (char *)(1u) ? (1) : (0))

int IsLittleEndian();

int main()
{
	IsLittleEndian();
	
	if (1 == IsLittleEndian())
	{
		printf ("The system is Little Endian \n");    
	}
	
	if (1 == IS_LITTLE_ENDIAN)
	{
		printf ("The macro also says the system is Little Endian \n");    
	}
	
	return 0;
}


int IsLittleEndian()
{
	unsigned int x = 1;
	return ((1 == *(char*)&x));
}


