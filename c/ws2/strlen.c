/*****************************************************************
*File: strlen.c                                                  *
*Description: Counts the lenght of a string                      *
*Author: Olga Smirnova                                           *
*Reviewer: Moshe Frydmann                                        *
*                                                                *
*****************************************************************/ 

#include <stdio.h>
#include <string.h>

/*****************************main********************************/

int StrLen(char *str);

int main()
{
    char str[] = "Hello";
                  
    printf("Length of the string is:  %d \n", StrLen(str)); 
      
    return 0;
}

/****************************functions****************************/

int StrLen(char *str)
 { 
    int i = 0;
     
    while (str[i] != '\0');
    {
        i++;
    }
    return i;
 }
 
 
