/*******************************************************************************
*                                                                              *
*File: bitsarr.c                                                               *
*Description: Functions to work with the 64bits array                          *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna, Jania, Tsivia, Pavel                                          *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/
#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */
#include <stdint.h>   /*unint64_t*/  
#include <limits.h>   /* CHAR_BIT */
#include <string.h>   /* strcmp */
#include <assert.h> 

#include "../include/bitsarr.h"

#define UINT64_BITS (sizeof(uint64_t) * CHAR_BIT) 
#define MASK_1 1lu

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"

int TestBitsArrSetAll();
int TestBitsArrResetAll();
int TestBitsArrSetOn();
int TestBitsArrSetOff();
int TestBitsArrSetBit();
int TestBitsArrGetVal();
int TestBitsArrFlip();
int TestBitsArrRotationRight();
int TestBitsArrRotationLeft();
int TestBitsArrCountBitsOn();
int TestBitsArrCountBitsOff();
int TestBitsArrToString();
int TestBitsArrMirror();

int TestBitsArrCountBitsOnLUT();
int TestBitsArrMirrorLUT();


void PrintBits(bitsarr_t bit_array);


int main()
{
	TestBitsArrSetAll();
	TestBitsArrResetAll();
	TestBitsArrSetOn();
	TestBitsArrSetOff();
	TestBitsArrSetBit();
	TestBitsArrGetVal();
	TestBitsArrFlip();
	TestBitsArrRotationRight();
	TestBitsArrRotationLeft();
	TestBitsArrCountBitsOn();
	TestBitsArrCountBitsOff();
	TestBitsArrToString();
	TestBitsArrMirror();
	
	printf(KBLU"\nFunctions with LUT\n"KNRM);
	
	TestBitsArrCountBitsOnLUT();
	TestBitsArrMirrorLUT();
	
	return 0;
}

/************************************* TESTS **********************************/

/****************************** TEST for BitsArrSetAll ************************/

int TestBitsArrSetAll()
{
	bitsarr_t x = 0;
	bitsarr_t y = BitsArrSetAll(x);

	printf(KYEL"\n\nTEST for BitsArrSetAll\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Recieved Result: ");
	PrintBits(y);
	
	if (0xffffffffffffffff == y)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf("\nFAILED\n");
		return 1;
	}
}


/****************************** TEST for BitsArrResetAll **********************/

int TestBitsArrResetAll()
{
	bitsarr_t x = 0xffffffffffffffff;
	bitsarr_t y = BitsArrResetAll(x);

	printf(KYEL"\n\nTEST for BitsArrResetAll\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Recieved Result: ");
	PrintBits(y);
	
	if (0 == y)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf("\nFAILED\n");
		return 1;
	}
	
	return 0;
}


/****************************** TEST for BitsArrSetOn *************************/

int TestBitsArrSetOn()
{
	bitsarr_t x = 5;
	size_t n = 1;
	bitsarr_t y = BitsArrSetOn(x, n);

	printf(KYEL"\n\nTEST for BitsArrSetOn\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Number of bit to be set: %lu \n", n);
	printf("Recieved Result: ");
	PrintBits(y);
	
	if (7 == y)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf("\nFAILED\n");
		return 1;
	}
}


/****************************** TEST for BitsArrSetOff ************************/

int TestBitsArrSetOff()
{
	bitsarr_t x = 15;
	size_t n = 2;
	bitsarr_t y = BitsArrSetOff(x, n);
	
	printf(KYEL"\n\nTEST for BitsArrSetOff\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Number of bit to be set: %lu \n", n);
	printf("Recieved Result: ");
	PrintBits(y);
	
	if (11 == y)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAILED\n"KNRM);
		return 1;
	}
}


/****************************** TEST for BitsArrSetBit ************************/

int TestBitsArrSetBit()
{
	bitsarr_t x = 12;
	size_t n = 1;
	int b_v = 1;
	bitsarr_t y = BitsArrSetBit(x, n, b_v);
	
	bitsarr_t x2 = 15;
	size_t n2 = 2;
	bitsarr_t y2 = BitsArrSetBit(x2, n2, b_v);
	
	bitsarr_t x3 = 15;
	size_t n3 = 2;
	int b_v2 = 0;
	bitsarr_t y3 = BitsArrSetBit(x3, n3, b_v2);
	
	printf(KYEL"\n\nTEST for BitsArrSetBit\n\n"KNRM);
	
	printf("Given number 1: ");
	PrintBits(x);
	printf("Number of bit to be set: %lu \n", n);
	printf("Boolean value to be set: %d \n", b_v);
	printf("Recieved Result 1: ");
	PrintBits(y);
	printf("\n");
	
	printf("Given number 2: ");
	PrintBits(x2);
	printf("Number of bit to be set: %lu \n", n2);
	printf("Boolean value to be set: %d \n", b_v);
	printf("Recieved Result 2: ");
	PrintBits(y2);
	printf("\n");
	
	printf("Given number 3: ");
	PrintBits(x3);
	printf("Number of bit to be set: %lu \n", n3);
	printf("Boolean value to be set: %d \n", b_v2);
	printf("Recieved Result 3: ");
	PrintBits(y3);
	
	if (14 == y && 15 == y2 && 11 == y3)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf("\nFAILED\n");
		return 1;
	}
}


/****************************** TEST for BitsArrGetVal ************************/

int TestBitsArrGetVal()
{
	bitsarr_t x = 12;
	size_t n = 1;
	bitsarr_t y = BitsArrGetVal(x, n);
	
	bitsarr_t x2 = 15;
	size_t n2 = 2;
	bitsarr_t y2 = BitsArrGetVal(x2, n2);
	
	printf(KYEL"\n\nTEST for BitsArrGetVal\n\n"KNRM);
	
	printf("Given number 1: ");
	PrintBits(x);
	printf("Number of bit to get value from: %lu \n", n);
	printf("Expected Result 1: 0 \n");
	printf("Recieved Result 1: %lu \n\n", y);
	
	printf("Given number 2: ");
	PrintBits(x2);
	printf("Number of bit to get value from: %lu \n", n2);
	printf("Expected Result 2: 1 \n");
	printf("Recieved Result 2: %lu \n", y2);
	
	if (0 == y && 1 == y2)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrFlip *****************************/

int TestBitsArrFlip()
{
	/*printf("\n\nTEST for BitsArrFlip\n\n");
	
	return 0;*/
	
	bitsarr_t x = 5;
	size_t n = 1;
	bitsarr_t y = BitsArrFlip(x, n);

	printf(KYEL"\n\nTEST for BitsArrFlip\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Number of bit to be flipped: %lu \n", n);
	printf("Recieved Result: ");
	PrintBits(y);
	
	if (7 == y)
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrRotationRight ********************/

int TestBitsArrRotationRight()
{
	bitsarr_t x = 9;
	size_t n = 4;
	bitsarr_t y = 0x9000000000000000;
	
	printf(KYEL"\n\nTEST for BitsArrRotationRight\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Number of times to rotate: %lu \n\n", n);
	printf("Expected Result: ");
	PrintBits(y);
	printf("Recieved Result: ");
	PrintBits(BitsArrRotationRight(x, n));
	
	if (y == BitsArrRotationRight(x, n))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrRotationLeft *********************/

int TestBitsArrRotationLeft()
{
	bitsarr_t x = 9;
	size_t n = 4;
	bitsarr_t y = 0x90;
	
	printf(KYEL"\n\nTEST for BitsArrRotationLeft\n\n"KNRM);
	
	printf("Given number: ");
	PrintBits(x);
	printf("Number of times to rotate: %lu \n\n", n);
	printf("Expected Result: ");
	PrintBits(y);
	printf("Recieved Result: ");
	PrintBits(BitsArrRotationLeft(x, n));
	
	if (y == BitsArrRotationLeft(x, n))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrCountBitsOn **********************/

int TestBitsArrCountBitsOn()
{
	bitsarr_t x = 5;
	bitsarr_t y = 11;
	
	printf(KYEL"\n\nTEST for BitsArrCountBitsOn\n\n"KNRM);
	
	printf("Expected Result: 2\n");
 	printf("Recieved Result: %ld\n\n", BitsArrCountBitsOn(x));
 	
 	printf("Expected Result: 3\n");
 	printf("Recieved Result: %ld\n", BitsArrCountBitsOn(y));
	
	if (2 == BitsArrCountBitsOn(x) && 3 == BitsArrCountBitsOn(y))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}

/*************************** TEST for BitsArrCountBitsOff *********************/

int TestBitsArrCountBitsOff()
{
	bitsarr_t x = 5;
	bitsarr_t y = 11;
	
	printf(KYEL"\n\nTEST for BitsArrBitsOff\n\n"KNRM);
	
	printf("Expected Result: 62\n");
 	printf("Recieved Result: %ld\n\n", BitsArrCountBitsOff(x));
 	
 	printf("Expected Result: 61\n");
 	printf("Recieved Result: %ld\n", BitsArrCountBitsOff(y));
	
	if (62 == BitsArrCountBitsOff(x) && 61 == BitsArrCountBitsOff(y))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrToString *************************/

int TestBitsArrToString()
{
	char dest[65];
	char cmp[65] = 
	"0000000000000000000000000000000000000000000000000000000000000111";
	bitsarr_t x = 0x00000007; 
	
	printf(KYEL"\n\nTEST for BitsArrToString\n\n"KNRM);
	
	printf("Expected Result: ");
	PrintBits(x);
	
	BitsArrToString(x, dest);
	printf("Recieved Result: %s\n", dest);
	
	if (0 == strcmp(cmp, dest))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrMirror ***************************/

int TestBitsArrMirror()
{
	bitsarr_t x = 0xf0f0f;
	bitsarr_t y = 0xf0f0f00000000000;
	
	bitsarr_t x1 = 0xf0f0f;
	bitsarr_t y1 = 0xf0f0f00000000000;
	
	printf(KYEL"\n\nTEST for BitsArrMirror\n\n"KNRM);
	
	printf("Expected Result: ");
	PrintBits(y);
 	printf("Recieved Result: ");
 	PrintBits(BitsArrMirror(x));
 	printf("\n");
 	
 	printf("Expected Result: ");
 	PrintBits(x1);
 	printf("Recieved Result: ");
 	PrintBits(BitsArrMirror(y1));
	
	if (y == BitsArrMirror(x) && x1 == BitsArrMirror(y1))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		printf("\n\n");
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrCountBitsOnLUT *******************/

int TestBitsArrCountBitsOnLUT()
{
	bitsarr_t x = 5;
	bitsarr_t y = 11;
	
	printf(KYEL"\n\nTEST for BitsArrCountBitsOnLUT\n\n"KNRM);
	
	printf("Expected Result: 2\n");
 	printf("Recieved Result: %ld\n\n", BitsArrCountBitsOnLUT(x));
 	
 	printf("Expected Result: 3\n");
 	printf("Recieved Result: %ld\n", BitsArrCountBitsOnLUT(y));
	
	if (2 == BitsArrCountBitsOnLUT(x) && 3 == BitsArrCountBitsOnLUT(y))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** TEST for BitsArrMirrorLUT ************************/

int TestBitsArrMirrorLUT()
{
	bitsarr_t x = 0xf0f0f;
	bitsarr_t y = 0xf0f0f00000000000;
	
	bitsarr_t x1 = 0xf0f0f;
	bitsarr_t y1 = 0xf0f0f00000000000;
	
	printf(KYEL"\n\nTEST for BitsArrMirrorLUT\n\n"KNRM);
	
	printf("Expected Result: ");
	PrintBits(y);
 	printf("Recieved Result: ");
 	PrintBits(BitsArrMirrorLUT(x));
 	printf("\n");
 	
 	printf("Expected Result: ");
 	PrintBits(x1);
 	printf("Recieved Result: ");
 	PrintBits(BitsArrMirrorLUT(y1));
	
	if (y == BitsArrMirrorLUT(x) && x1 == BitsArrMirrorLUT(y1))
	{
		printf(KGRN"\nSUCCESS\n"KNRM);
		printf("\n\n");
		return 0;
	}
	else
	{
		printf(KRED"\nFAIL\n"KNRM);
		return 1;
	}
}


/*************************** Function to print binary *************************/

void PrintBits(bitsarr_t bit_array)
{
	int i = 0;

	for (i = (UINT64_BITS - 1) ; i >= 0 ; i--)
	{
	  (bit_array & (MASK_1 << i))? printf("1"): printf("0");	
	}
	printf("\n");
}





