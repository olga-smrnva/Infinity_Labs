/*****************************************************************
*                                                                *
*File: palindrome.c                                              *
*Description: Function to check if fiven string is a palindrome  *
*Author: Olga Smirnova                                           *
*Reviewer: Rina Volovich                                         *
*                                                                *
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>



int Palindrome(char *arr)
{
    char *arr1 = strdup(arr);
    char temp = 'a';
    int start = 0;
    int end = strlen(arr)-1;
    
    for(start=0, end=strlen(arr)-1; start<end; ++start, --end)
    {
        temp = arr1[start];
        arr1[start] = arr1[end];
        arr1[end] = temp;
    }
    
    
    if (strcmp(arr, arr1) == 0)
    {
        return 0;
    }
    else 
    {
        return 1; 
    }
   
    free(arr1);
    arr1 = NULL;
}


int main()
{
    char arr[7] = "ololo";
    char arr1[7] = "777h";
   
    Palindrome(arr);
    if (0 == Palindrome(arr))
    {
        printf("The given array is Palindrom \n");
    }
    else
    {
        printf("The given array is not Palindrom \n");
    }
    
    Palindrome(arr1);
     if (0 == Palindrome(arr1))
    {
        printf("The given array is Palindrom \n");
    }
    else
    {
        printf("The given array is not Palindrom \n");
    }
    
    return 0;

}



