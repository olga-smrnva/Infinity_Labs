/*****************************************************************
*                                                                *
*File: remspace.c                                                *
*Description: Function to remove all extra spaces from           *
 the beginning, end of the string and from the string itself     *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


char* RemSpace(char *s);

int main()
{
    char arr[] = "  Hello, my     friend!  How   are you?    \0";
   
    printf("Here is our string after editing: \n");
    printf("%s \n", RemSpace(arr));

    return 0;
}

char* RemSpace(char *s)
{
    char *start = s;
    char *end = s;
    char *temp =s;
    char *ret = s;
    int i = 1;
       
    while(*start == ' ' || *start == '\t')
    {
        ++start;
    }
    
    ret = start;
    temp = start;
    
    while(*start)
    {
        while((*start == ' ' || *start == '\t') && 
        (*(start+i) == ' ' || *(start+i) == '\t'))
        {
           ++start;
        }
        *temp = *start;
        ++temp;
        ++start;  
    } 
    *temp = '\0';
    
    while(*end)
    {
        ++end;
    }
    --end;
    
    while(*end == ' ' || *end == '\t')
    {
        --end;
    }
    ++end;
    
    *end = '\0';
    
    return ret;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
