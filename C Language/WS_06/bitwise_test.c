/*****************************************************************
*                                                                *
*File: bitwise_test.c                                            *
*Description: Functions to test functions from bitwise.c         *
*Author: Olga Smirnova                                           *
*Reviewer: Jake Belinky                                          *
*                                                                *
*****************************************************************/


#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */
#include <stdlib.h>   

#include "bitwise.h"

#define CHAR_BITS  8
#define INT_BITS  (sizeof(int) * CHAR_BITS)

int TestPow2(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2);
int TestIsPow2(unsigned int a, unsigned int b);
int TestIsPow2Loop(unsigned int a, unsigned int b);
int TestAddOne(int x, int y, int z);
int TestCount3Bits(unsigned int *arr, size_t len);
int TestByteMirror(unsigned int x, unsigned int z);
int TestByteMirrorLoop(unsigned int x, unsigned int z);
int TestCheck1(unsigned char a, unsigned char b);
int TestCheck2(unsigned char a, unsigned char b, unsigned char c);
int TestSwappBits(unsigned char a, unsigned char b, 
		  unsigned char exp_a, unsigned char exp_b);
int TestDivisible16(unsigned int x, unsigned int y, unsigned int z);
int TestSwapp(unsigned int x, unsigned int y);
int TestCountBits(int x, int y);
int TestCountBitsLoop(int x, int y);
int TestFloatBits(float n);

int main ()
{

/****Variables to test Pow2***************/

	unsigned int x = 2;
	unsigned int y = 3;

	unsigned int x2 = 3;
	unsigned int y2 = 4;

/****Variables to test IsPow2*************/

	unsigned int a = 16;
	unsigned int b = 35;

/****Variables to test AddOne*************/

	int x3 = 33;
	int y3 = -32;
	int z3 = -11;
	
/****Variables to test Count3Bits*********/

	unsigned int arr[] = {6, 7, 8, 9, 10, 11};
	size_t len = 6;

/****Variables to test ByteMirror*********/

	unsigned int x4 = 2;
	unsigned int z4 = ByteMirror(x4);

/****Variables to test ByteMirrorLoop*****/

	unsigned int m = 2;
	unsigned int z6 = ByteMirrorLoop(m);
	
/****Variables to test Check1*************/

	unsigned char a1 = '"'; /* TRUE */
	unsigned char b1 = 'D'; /* FALSE */
	
/****Variables to test Check2*************/

	unsigned char c1 = '!'; /* TRUE */

/****Variables to test SwappBits**********/

	unsigned char a2 = 'a'; 
	unsigned char b2 = 'P';
	unsigned char exp_a = 'I';
	unsigned char exp_b = 'P';

/****Variables to test Divisible16********/

	unsigned int x5 = 33; 
	unsigned int y5 = 17; 
	unsigned int z5 = 22;

/****Variables to test Swapp**************/

	unsigned int x6 = 3;
	unsigned int y6 = 7;

/****Variables to test CountBits**********/

	int x7 = 5;
	int y7 = 11;

/****Variables to test FloatBits**********/

	float n = 5.0;

/************************Test Pow2*******************************/

	TestPow2(x, y, x2, y2);
		
/************************Test IsPow2*****************************/

	TestIsPow2(a, b);
	
/************************Test IsPow2Loop*************************/

	TestIsPow2Loop(a, b);
	
/************************Test AddOne*****************************/

	TestAddOne(x3, y3, z3);

/************************Test Count3Bits*************************/

	TestCount3Bits(arr, len);
	
/************************Test ByteMirror*************************/

	TestByteMirror(x4, z4);
	
/************************Test ByteMirrorLoop*********************/

	TestByteMirrorLoop(m, z6);
	
/************************Test Check1*****************************/

	TestCheck1(a1, b1);
	
/************************Test Check2*****************************/

	TestCheck2(a1, b1, c1);
	
/************************Test SwappBits**************************/

	TestSwappBits(a2, b2, exp_a, exp_b);

/************************Test Divisible16************************/

	TestDivisible16(x5, y5, z5);

/************************Test Swapp******************************/

	TestSwapp(x6, y6);
	
/************************Test CountBits**************************/

	TestCountBits(x7, y7);
	
/************************Test CountBitsLoop**********************/

	TestCountBitsLoop(x7, y7);

/************************Test FloatBits**************************/

	TestFloatBits(n);
	
	return 0;
}

/************************Test Pow2*******************************/

int TestPow2(unsigned int x, unsigned int y, unsigned int x2, unsigned int y2)
{
	int result = 0;
	int result1 = 16; /* TRUE */
	int result2 = 48; /* TRUE */
	
	printf("\nTEST for Pow2\n");
	
	printf("Expected Result: 16, 48 \n");
	printf("Recieved Result: %ld, %ld\n", Pow2(x, y), Pow2(x2, y2));
	
	if (result1 == Pow2(x, y) && result2 == Pow2(x2, y2))
	{
		printf("Test DONE\n");
		result = 0;
	}
	else
	{
		printf("Test FAILED\n");
		result = 1;
	}
	
	return result;
}

/************************Test IsPow2*****************************/

int TestIsPow2(unsigned int a, unsigned int b)
{
	int result = 0;

	printf("\nTEST for IsPow2\n");
	
	printf("Expected Result: 1, 0\n");
	printf("Recieved Result: %d, %d\n", IsPow2(a), IsPow2(b));
	
	if (1 == IsPow2(a) && 0 == IsPow2(b))
	{
		printf("Test DONE\n");
		result = 0;
	}
	else
	{
		printf("Test FAILED\n");
		result = 1;
	}
	
	return result;
}

/************************Test IsPow2Loop*************************/

int TestIsPow2Loop(unsigned int a, unsigned int b)
{
	int result = 0;

	printf("\nTEST for IsPow2Loop\n");
	
	printf("Expected Result: 1, 0\n");
	printf("Recieved Result: %d, %d\n", IsPow2Loop(a), IsPow2Loop(b));
	
	if (1 == IsPow2Loop(a) && 0 == IsPow2Loop(b))
	{
		printf("Test DONE\n");
		result = 0;
	}
	else
	{
		printf("Test FAILED\n");
		result = 1;
	}
	
	return result;
}

/************************Test AddOne*****************************/

int TestAddOne(int x, int y, int z)
{
	int result = 0;
	
	printf("\nTEST for AddOne\n");
	
	printf("AddOne(%i)=%i\n",x, AddOne(x));
	
	printf("AddOne(%i)=%i\n",y, AddOne(y));
	
	printf("AddOne(%i)=%i\n",z, AddOne(z));
	
	printf("Test DONE\n");
	
	return result;
}

/************************Test Count3Bits*************************/

int TestCount3Bits(unsigned int *arr, size_t len)
{
	int result = 0;

	printf("\nTEST for Count3Bits\n");
	
	printf("Expected result: 7 11\n");
	
	printf("Received result: ");
	Count3Bits(arr, len);
	
	printf("\n");
	
	return result;
}

/************************Test ByteMirror*************************/

int TestByteMirror(unsigned int x, unsigned int z)
{
	int result = 0;
	
	int iPos = 0;
	
	printf("\nTEST for ByteMirror\n");
	
	printf("Before reverse: ");
	for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
	{
	  (x & (1 << iPos))? printf("1"): printf("0");	
	}
	
	printf("\n");
	
	printf("After reverse: ");
	for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
	{
	  (z & (1 << iPos))? printf("1"): printf("0");	
	}
	
	printf("\n");
	
	return result;
	
}

/************************Test ByteMirrorLoop*********************/

int TestByteMirrorLoop(unsigned int x, unsigned int z)
{
	int result = 0;
	
	int iPos = 0;
	
	printf("\nTEST for ByteMirrorLoop\n");
	
	printf("Before reverse: ");
	for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
	{
	  (x & (1 << iPos))? printf("1"): printf("0");	
	}
	
	printf("\n");
	
	printf("After reverse: ");
	for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
	{
	  (z & (1 << iPos))? printf("1"): printf("0");	
	}
	
	printf("\n");
	
	return result;
}

/************************Test Check1*****************************/

int TestCheck1(unsigned char a, unsigned char b)
{
	int result = 0;
	
	printf("\nTEST for Check1\n");
	
	printf("Expected Result: 0\n");
 	printf("Recieved Result: %i\n\n", Check1(a));
 	
 	printf("Expected Result: 1\n");
 	printf("Recieved Result: %i\n\n", Check1(b));
	
	return result;
}

/************************Test Check2*****************************/

int TestCheck2(unsigned char a, unsigned char b, unsigned char c)
{
	int result = 0;
	
	printf("\nTEST for Check2\n");
	
	printf("Expected Result: 0\n");
 	printf("Recieved Result: %i\n\n", Check2(a));
 	
 	printf("Expected Result: 1\n");
 	printf("Recieved Result: %i\n\n", Check2(b));
 	
 	printf("Expected Result: 0\n");
 	printf("Recieved Result: %i\n\n", Check2(c));
	
	return result;
}

/************************Test SwappBits**************************/

int TestSwappBits(unsigned char a, unsigned char b, 
		   unsigned char exp_a, unsigned char exp_b)
{
	int result = 0;
	
	printf("\nTEST for SwappBits\n");
	
	printf("Expected Result: %c\n", exp_a);
 	printf("Recieved Result: %c\n", SwappBits(a));
 	
 	printf("Expected Result: %c\n", exp_b);
 	printf("Recieved Result: %c\n\n", SwappBits(b));
 	 	
 	return result;
}

/************************Test Divisible16************************/

int TestDivisible16(unsigned int x, unsigned int y, unsigned int z)
{
	int result = 0;
	
	printf("\nTEST for Divisible16\n");
	
	printf("Expected Result: 32\n");
 	printf("Recieved Result: %d\n\n", Divisible16(x));
 	
 	printf("Expected Result: 16\n");
 	printf("Recieved Result: %d\n\n", Divisible16(y));
 	
 	printf("Expected Result: 16\n");
 	printf("Recieved Result: %d\n\n", Divisible16(z));
 	
 	return result;
}

/************************Test Swapp******************************/

int TestSwapp(unsigned int x, unsigned int y)
{
	int result = 0;
	
	printf("\nTEST for Swap\n");
	
	Swapp(&x, &y);
 	
 	printf("Expected Result: a = 7 b = 3\n");
 	printf("Recieved Result: a = %d b = %d\n\n", x, y);
 	
 	return result;
}

/************************Test CountBits**************************/

int TestCountBits(int x, int y)
{
	int result = 0;
	
	printf("\nTEST for CountBits\n");
	
	printf("Expected Result: 2\n");
 	printf("Recieved Result: %d\n\n", CountBits(x));
 	
 	printf("Expected Result: 3\n");
 	printf("Recieved Result: %d\n\n", CountBits(y));
 	
 	return result;
}

/************************Test CountBitsLoop**********************/

int TestCountBitsLoop(int x, int y)
{

	printf("\nTEST for CountBitsLoop\n");
	
	printf("Expected Result: 2\n");
 	printf("Recieved Result: %d\n\n", CountBitsLoop(x));
 	
 	printf("Expected Result: 3\n");
 	printf("Recieved Result: %d\n\n", CountBitsLoop(y));
 	
 	return 0;	
}


/************************Test FloatBits**************************/

int TestFloatBits(float n)
{
	printf("\nTEST for FloatBits\n");
	
	printf("Expected Result: 01000000101000000000000000000000\n");
 	printf("Recieved Result: ");
	FloatBits(n);
	printf("\n\n");
	
	return 0;
}






