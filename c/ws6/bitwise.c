/*****************************************************************
*                                                                *
*File: bitwise.c                                                 *
*Description: Create functions using birwise operators           *
*Author: Olga Smirnova                                           *
*Reviewer: Jake Belinky                                          *
*                                                                *
*****************************************************************/


#include <stdio.h>    /* printf */
#include <stddef.h>   /* size_t */
#include <stdlib.h>   

#define CHAR_BITS  8


/*****************************Pow2*******************************/

long Pow2(unsigned int x, unsigned int y)
{
	return x << y;
}


/*****************************IsPow2*****************************/

int IsPow2(unsigned int x)
{
	int result = 0;
	
	if (0 == (x&(x-1)))
	{
		result = 1;
	}
	
	else 
	{
		result = 0; 
	}
	
	return result;
}


/*****************************IsPow2Loop*************************/

int IsPow2Loop(unsigned int x)
{
	int result = 0;
	int count = 0;
	
	while (x)
	{
		if ((x % 2) == 1) 
		{
			++count;
		}
		x = x >> 1;
	}

	if (count == 1)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	
	return result;
}	


/*****************************AddOne*****************************/

int AddOne(int x)
{
	return (-(~x));
}


/*****************************Count3Bits*************************/

int Count3Bits(unsigned int *arr, size_t len)
{
	int bit_count = 0;
	size_t i = 0;
	size_t j = 0;
	
	for (i=0; i < len; ++i)
	{
		bit_count = 0;
		
		for (j=0; j < 32; ++j)
		{	
			if (arr[i] & (1<<j))
			{
				++bit_count;
			}
		}
		
		if (3 == bit_count)
		{
			printf("%u ", arr[i]);
		}
	}

	return 0;
}


/*****************************ByteMirror*************************/

unsigned int ByteMirror(unsigned int x)
{
	unsigned int result = 0;
	
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	
	result = ((x >> 16) | (x << 16));
	
	return result;
}


/*************************ByteMirrorLoop*************************/

unsigned int ByteMirrorLoop(unsigned int x)
{
	unsigned int result = x;
	int count = sizeof(x) * CHAR_BITS - 1;
	
	while (x)
	{   
	result |= x & 1;
	x >>= 1;
	result <<= 1;
	--count;
	}
	result <<= count;
	
	return result;
}


/*****************************Check1*****************************/

int Check1(unsigned char c)
{
	int a = 2;
	int b = 6;
	
	while (c & (1 << a) && c & (1 << b))
	{
		return 1;
	}
	
	return 0;
}


/*****************************Check2*****************************/

int Check2(unsigned char c)
{
	int a = 2;
	int b = 6;
	
	while (c & (1 << a) || c & (1 << b))
	{
		return 1;
	}
	
	return 0;
}


/**************************SwappBits*****************************/

unsigned char SwappBits(unsigned char c)
{
	const unsigned char i = 3;
	const unsigned char j = 5;
	
	unsigned char bit_3 = (c >> i) & 1;
	unsigned char bit_5 = (c >> j) & 1;
	
	unsigned char xor = bit_3 ^ bit_5;
    
    return c ^ (xor << i | xor << j);
}


/***********************Divisible16******************************/

unsigned int Divisible16(unsigned int n)
{
	while (n)
	{
		if (((n >> 4) << 4) == n)
	{
		return n;
	}
	--n;
	}
	
	return n;
}


/******************************Swapp*****************************/

void Swapp(unsigned int *a, unsigned int *b)
{
	*a = *a ^ *b; 
	*b = *a ^ *b; 
	*a = *a ^ *b;
}


/**************************CountBits*****************************/

int CountBits(int n)
{
	n = n - ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n + (n >> 4)) & 0x0F0F0F0F;
	n = n + (n >> 8);
	n = n + (n >> 16);

	return n & 0x0000003F;	
}


/**************************CountBitsLoop*************************/

int CountBitsLoop(int n)
{
	int count = 0; 
	
	if (n < 0)
	{
		++count;
		n *= -1;
	}
	
	while (n) 
	{ 
		count += n & 1; 
		n >>= 1; 
	} 
	
	return count; 
}


/****************************FloatBits***************************/

void FloatBits(float x)
{
	int *p = (int *) & x;
	int bit = 0;
	unsigned int last_bit = sizeof(x) * CHAR_BITS - 1;
	int i;

	for (i = last_bit; i >= 0; --i)
	{
		bit = (*p >> i) & 1;
		printf("%d", bit);
	}
}






