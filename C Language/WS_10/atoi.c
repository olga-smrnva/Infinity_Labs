/*****************************************************************
*                                                                *
*File: atoi.c                                                    *
*Description: Functions that act like the library functions      *
              atoi(), itoa()                                     *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf*/
#include <string.h>   /* strlen */
#include <ctype.h>    /* isspace */
#include <stddef.h>   /* size_t */

#include "atoi.h"

#define TEN_BASE 10

/************************* Helping functions ********************/
int Power(int base, int exponent);
size_t Shift(const char *s);


/* Function converts the initial portion of the string s to int */

int Atoi10(const char *str)
{
	int if_negative = 1;
	int count = 1;
	int result = 0;
	
	size_t i = 0;
	size_t size = strlen(str);
	size_t shift_index = Shift(str);
	
	if (*(str + shift_index) == '-')
	{
		if_negative = -1;
		count = 0;
		++i;
	}
	
	for ( ; i < (size - shift_index); ++i)
	{
		result += (str[size - (i + count)] - '0') * 
							 Power(10, i + count - 1);
	}
	
	return (result * if_negative);
}


/******** Function converts the int number to char string *******/

char *Itoa36(const int x, char *str, const int base)
{
	char buffer[11] = "";
	char *p_buf = buffer; 
	char remainder = 0;
	int i = 0;
	char *result = str;
	
	int x_buf = x;
	int base_buf = base;
	
	if (0 > x_buf)
	{
		x_buf *= -1;
		*str = '-';
		++str;
	}

	while (0 < x_buf)
	{
		remainder = x_buf % base_buf;
		
		if (9 < remainder)
		{
			remainder += '7';
		}
		else
		{
			remainder += '0';
		}
		
		*p_buf = remainder;
		p_buf++;
		x_buf = x_buf / base_buf;
		i++;
	}
	
	while (0 < i)
	{
		p_buf--; 
		*str = *p_buf;
		str++;
		i--;
	}

	return result;
}


/************************* Helping functions ********************/

/**************** Function to raise base into power *************/

int Power (int base, int exponent)
{	
	int i = 0;
	int n = 1;
	
	
	for (i = 0; i < exponent; i++)
	{
		n *= base;
	}
	
	return n;
}


/**************** Function to shift if there are spaces *********/
	
size_t Shift (const char *s)
{
	size_t i = 0, count = 0;
	
	while (' ' == s[i] || '\t' == s[i])
	{
		if (0 != isspace(s[i]))
		{
			++count;
		}
		
		++i;
	}
	
	return count;
}















