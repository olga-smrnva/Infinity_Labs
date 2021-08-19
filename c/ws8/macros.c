/**********************************************************************
*                                                                     *
*File: struct_arr.c                                                   *
*Description:  max2(a,b), max3(a,b,c), size of variable, size of type *
*Author: Olga Smirnova                                                *
*Reviewer: Anna Savina                                                *
*                                                                     *
***********************************************************************/

#include <stdio.h>
#include <stdlib.h> /*sizeof*/


#define MAX2(a,b) (((a) > (b)) ? (a) : (b))
#define MAX3(a,b,c) (MAX2(a, MAX2(b, c)))
#define SIZEOF_VAR(var) ((char *)(&var+1) - (char *)(&var))
#define SIZEOF_TYPE(type) ((size_t)((type *)0+1))

void TestMax2();
void TestMax3();
void TestSizeOfVariable();
void TestSizeofType();


int main()
{
	TestMax2();
	TestMax3();
	TestSizeOfVariable();
	TestSizeofType();

	return 0;
}


/****************************Test MAX2(a,b)****************************/

void TestMax2()
{
	printf("\nTEST for MAX2(a,b) macro\n\n");
	
	printf("Given numbers are: 3, 77 \n");
	printf("Expected Result: 77\n");
 	printf("Recieved Result: %d\n\n", MAX2(3, 77));
 	
 	printf("Given numbers are: -8, 123 \n");
 	printf("Expected Result: 123\n");
 	printf("Recieved Result: %d\n\n", MAX2(-8, 123));
 	
 	printf("Given numbers are: 111, 111\n");
 	printf("Expected Result: 111\n");
 	printf("Recieved Result: %d\n\n", MAX2(111, 111));
}


/****************************Test MAX3(a,b,c)**************************/

void TestMax3()
{
	printf("\nTEST for MAX3(a,b,c) macro\n\n");
	
	printf("Given numbers are: 3, 77, 14 \n");
	printf("Expected Result: 77\n");
 	printf("Recieved Result: %d\n\n", MAX3(3, 77, 14));
 	
 	printf("Given numbers are: -8, 123, 3 \n");
 	printf("Expected Result: 123\n");
 	printf("Recieved Result: %d\n\n", MAX3(-8, 123, 3));
 	
 	printf("Given numbers are: 111, 111, 111\n");
 	printf("Expected Result: 111\n");
 	printf("Recieved Result: %d\n\n", MAX3(111, 111, 111));
}


/*************************Test SIZEOF_VAR(var)*************************/

void TestSizeOfVariable()
{
	char a = 's';	
	int b = 7;
	float c = 5.000055;
	double d = 0.123456;
	int arr[7];
	
	printf("\nTEST for SIZEOF_VAR(var) macro\n\n");
	
	printf("Given variable is char c = 's' \n");
 	printf("Expected Result: 1\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_VAR(a));
	
	printf("Given variable is int a = 7 \n");
	printf("Expected Result: 4\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_VAR(b));
 	
 	printf("Given variable is float b = 5.000055 \n");
 	printf("Expected Result: 4\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_VAR(c));
 	
 	printf("Given variable is double d = 0.123456 \n");
 	printf("Expected Result: 8\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_VAR(d));
 	
 	printf("Given variable is int arr[7] \n");
 	printf("Expected Result: 28\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_VAR(arr));
}


/****************************Test SIZEOF_TYPE(type)*********************/

void TestSizeofType()
{
	printf("\nTEST for SIZEOF_TYPE(type) macro\n\n");
	 	
 	printf("Given type is char \n");
 	printf("Expected Result: 1\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_TYPE(char));
 	
	printf("Given type is int \n");
	printf("Expected Result: 4\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_TYPE(int));
 	
 	printf("Given type is float \n");
 	printf("Expected Result: 4\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_TYPE(float));

 	printf("Given type is double \n");
 	printf("Expected Result: 8\n");
 	printf("Recieved Result: %ld\n\n", SIZEOF_TYPE(double));
}



