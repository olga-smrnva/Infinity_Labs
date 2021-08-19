/*****************************************************************
*                                                                *
*File: mem.c                                                     *
*Description: Functions that act like the library functions      *
              memset(), memcpy(), memmove()                      *
*Author: Olga Smirnova                                           *
*Reviewer: Jania Peimer                                          *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
#include <string.h>   /* memset, memcpy, memmove */
#include <stddef.h>   /* size_t */
#include "mem.h"

int TestMemset();
int TestMemcpy();
int TestMemmove();


int main()
{
	printf("\nTEST for Memset\n\n");
	TestMemset();

	printf("\nTEST for Memcpy\n\n");
	TestMemcpy();
	
	printf("\nTEST for Memmove\n\n");
	TestMemmove();

return 0;
}


/****************************** TESTS ******************************/

/************************** TEST for Memset ************************/

int TestMemset()
{
	int c = '8';
	char str1[] = "Olololololo";
	void *s1 = (void *)str1;

	char str2[] = "Olololololo";
	void *s2 = (void *)str2;

	size_t n = 9;

	printf("The first given array is: %s\n\n", str1);
	/*printf("The given array is: %s\n\n", str2);*/

	memset(s2, c, n);
	printf("Expected Result: %s\n", str2);
	    
	Memset(s1, c, n);
	printf("Recieved Result: %s\n\n", str1);
	
	if (0 == strcmp(str1, str2))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
    
    return 0;
}


/************************** TEST for Memcpy ************************/

int TestMemcpy()
{
	char str1[] = "Olololololo";
	void *s1 = (void *)str1;

	char str2[] = "Ahahahahaha";
	void *s2 = (void *)str2;
	
	char str3[] = "Ahahahahaha";
	void *s3 = (void *)str3;

	size_t n = 9;

	printf("The sourse array is: %s\n", str1);
	printf("The destination array is: %s\n", str2);
	printf("The number of bytes we change: %lu\n\n", n);

	memcpy(s2, s1, n);
	printf("Expected Result: %s\n", str2);
	    
	Memcpy(s3, s1, n);
	printf("Recieved Result: %s\n\n", str3);
	
	if (0 == strcmp(str2, str3))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
    
    return 0;
}


/***************************TEST for Memmove************************/

int TestMemmove()
{
	char str1[] = "Olololololo";
	void *s1 = (void *)str1;

	char str2[] = "Ahahahahaha";
	void *s2 = (void *)str2;
	
	char str3[] = "Ahahahahaha";
	void *s3 = (void *)str3;

	size_t n = 3;

	printf("The sourse array is: %s\n", str1);
	printf("The destination array is: %s\n", str2);
	printf("The number of bytes we change: %lu\n\n", n);

	memmove(s2, s1, n);
	printf("Expected Result: %s\n", str2);
	    
	Memmove(s3, s1, n);
	printf("Recieved Result: %s\n\n", str3);
	
	if (0 == strcmp(str2, str3))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
    
    return 0;
}
























/*********TEST for Memmove********/
/*********TEST for Memmove********/
/*********TEST for Memmove********/
