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

int StrCmp(const char *str1, const char *str2);

int main()
{
    char str1[] = "b";
    char str2[] = "a";
       
    printf("%d \n", StrCmp(str1, str2));
     
    return 0;
}

/****************************functions****************************/

int StrCmp(const char *str1, const char *str2)
{ 
    int i = 0;
     
    while (*(str1+i) == *(str2+i) && *(str1+i) != '\0' && *(str2+i) != '\0')
    {
        i++;
    }
    
    return (*(str1+i)-*(str2+i));
 
}
