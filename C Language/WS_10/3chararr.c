/*****************************************************************
*                                                                *
*File: 3chararr.c                                                *
*Description: Functions that print letters that appears          *
 both in arrays 1 and 2, but not in the array 3                  *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>	/* printf */

#define IGNORE 1
#define PRINT 2


static void PrintResult();
void ThreeCharArr(const char *s1, const char *s2, const char *s3, 
				       size_t size1, size_t size2, size_t size3);

int main(void)
{
	printf("\nTEST for ThreeCharArr\n\n");
	PrintResult();
	
	return 0;
}


void ThreeCharArr(const char *s1, const char *s2, const char *s3, 
				        size_t size1, size_t size2, size_t size3)
{
	int LUT[255] = {0};
	size_t i = 0;
	unsigned char *p1 = (unsigned char *)s1;
	unsigned char *p2 = (unsigned char *)s2;
	unsigned char *p3 = (unsigned char *)s3;

	for (i = 0; i < size3; i++)
	{
		LUT[p3[i]] = IGNORE;
	}
	
	for (i = 0; i < size1; i++)
	{
		if (LUT[p1[i]] != IGNORE)
		{
			LUT[p1[i]] = PRINT;
		}
	}
	
	for (i = 0; i < size2; i++)
	{
		if (LUT[p2[i]] == PRINT)
		{
			printf("%c ", p2[i]);
		}
	}
	
	printf("\n");
}


static void PrintResult()
{
	char s1_1[5] = {'!', '2', '3', '4', '&'};
	char s1_2[6] = {'&', '5', '6', '7', '!'};
	char s1_3[6] = {'2', '3', '4', '5', '6'};

	char s2_1[7] = {'a', 'b', 'a', 'a', 'a', 'a'};
	char s2_2[7] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char s2_3[7] = {'1', '!', '2', '@', '3', '#'};

	char s3_1[7] = {'1', '2', '3', '4', '5', '6'};
	char s3_2[7] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char s3_3[7] = {'!', '@', '#', '$', '%', '^'};
	
	printf("Expected Result 1: & !\n");
	printf("Recieved Result 1: ");
	ThreeCharArr(s1_1, s1_2, s1_3, 5, 6, 6);
	printf("\n");

	printf("Expected Result 2: a b\n");
	printf("Recieved Result 2: ");
	ThreeCharArr(s2_1, s2_2, s2_3, 5, 6, 6);
	printf("\n");
	
	printf("Expected Result 3:  \n");
	printf("Recieved Result 3: ");
	ThreeCharArr(s3_1, s3_2, s3_3, 5, 6, 6);
	printf("\n");
}
