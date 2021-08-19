/*****************************************************************
*                                                                *
*File: atoi_test.c                                               *
*Description: Functions that act like the library functions      *
              atoi(), itoa()                                     *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf*/
#include <string.h>   /* strcmp */

#include "atoi.h"

void TestAtoi10(void);
void TestItoa36(void);

int main()
{
	printf("\nTEST for Atoi10\n\n");
	TestAtoi10();
	
	printf("\nTEST for Itoa36\n\n");
	TestItoa36();

	return 0;
}


/****************************** TESTS ******************************/

/************************** TEST for Atoi10*************************/

void TestAtoi10(void)
{
	char *s1 = "7";
	char *s2 = "77";
	char *s3 = "0";
	char *s4 = "-777";
		
	int expected1 = 7;
	int expected2 = 77;
	int expected3 = 0;
	int expected4 = -777;
	
	int result1;
	int result2;
	int result3;
	int result4;
	
	result1 = Atoi10(s1);
	result2 = Atoi10(s2);
	result3 = Atoi10(s3);
	result4 = Atoi10(s4);
	
	printf("Expected Result 1: 7\n");
	printf("Recieved Result 1: %d\n", result1);
	
	if (result1 == expected1)
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
	
	printf("Expected Result 2: 77\n");
	printf("Recieved Result 2: %d\n", result2);
	
	if (result2 == expected2)
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
	
	printf("Expected Result 3: 0\n");
	printf("Recieved Result 3: %d\n", result3);
	
	if (result3 == expected3)
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
	
	printf("Expected Result 4: -777\n");
	printf("Recieved Result 4: %d\n", result4);
	
	if (result4 == expected4)
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n");
	}
}


/************************** TEST for Itoa10*************************/

void TestItoa36(void)
{
	int n1 = 7;
	int n2 = 77;
	int n3 = 777;
	int n4 = -7777;
	
	char buffer1[20] = "";
	char buffer2[20] = "";
	char buffer3[20] = "";
	char buffer4[20] = "";
	
	char *expected1 = "111";
	char *expected2 = "115";
	char *expected3 = "777";
	char *expected4 = "-1E61";
	
	Itoa36(n1, buffer1, 2);
	Itoa36(n2, buffer2, 8);
	Itoa36(n3, buffer3, 10);
	Itoa36(n4, buffer4, 16);
	
	printf("Expected Result 1: 111\n");
	printf("Recieved Result 1: %s\n", buffer1);
	
	if (0 == strcmp(buffer1, expected1))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n\n");
	}
	
	printf("Expected Result 2: 115\n");
	printf("Recieved Result 2: %s\n", buffer2);
	
	if (0 == strcmp(buffer2, expected2))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n\n");
	}
	
	printf("Expected Result 3: 777\n");
	printf("Recieved Result 3: %s\n", buffer3);
	
	if (0 == strcmp(buffer3, expected3))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n\n");
	}

	printf("Expected Result 4: -1E61\n");
	printf("Recieved Result 4: %s\n", buffer4);
	
	if (0 == strcmp(buffer4, expected4))
	{
		printf("SUCCEED\n\n");
	}
	else
	{
		printf("FAILED\n\n");
	}
}



