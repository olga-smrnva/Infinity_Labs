/*****************************************************************
*                                                                *
*File: str.c                                                     *
*Description: Functions to work with strings                     *
*Author: Olga Smirnova                                           *
*Reviewer: Rina Volovich                                         *
*                                                                *
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "str.h"


int StrLen(const char *str);
int StrCmp(const char *str1, const char *str2);


/*****************************StrCpy******************************
            
             Gets destination string and sourse string 
        and returns a pointer to the destination string         */
           

char *StrCpy(char *dest, const char *src)
{
    char *ptr = dest;
    
    assert(src);
    assert(dest);
     
    while ('\0' != *src)
    {
        *dest = *src;
        ++dest;
        ++src;
    }
        
    *dest = '\0';
       
    return ptr;
}
     
   
     
/*****************************StrnCpy****************************
  
  Copies first n characters of the string to another string    */   
  

char *StrnCpy(char *dest, const char *src, size_t n)
{
    char *ptr = dest;
    size_t i;
    
    assert(dest);
     
    for (i = 0; *src != '\0' && i < n; ++i)
    {
        *dest = *src;
        ++dest;
        ++src;
    }
    
    for( ; i < n; ++i)
    {    
        *dest = '\0';
        ++dest;
    }
        
    return ptr;
}
    
   
    
/***************************StrCaseCmp****************************

              Compares two strings ingnoring case               */
               

int StrCaseCmp(const char *s1, const char *s2)
{
    int result;
    const char *ptr1;
    const char *ptr2;
    
    ptr1 = s1;
    ptr2 = s2;
     
    if (ptr1 == ptr2)
    {
        return 0;   
    } 
        
    while ((result = tolower(*ptr1) - tolower(*ptr2++)) == 0)
    {   
        if (*ptr1++ == '\0')
        {
            break;
        }
    }
        
    return result;
}



/*****************************StrChr******************************

      Locates character in string, returns pointer to the first 
           occurrence to the character c in the string s        */


char *StrChr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (*s++ == '\0')
        {
            return 0;
        }
    }
        
    return (char *)s;        
}
    
    
    
/*****************************StrDup*****************************

     Duplicates a string, returns pointer to a new string      */


char *StrDup(const char *s)
{
    size_t length = StrLen(s) + 1;
    char *new;
    new = malloc(length);
    
    assert(src);
    
    StrCpy(new, s);
    
    return new;
}


/*****************************StrCat******************************
        
                         Joins two strings                      */
                         

char *StrCat(char *dest, const char *src)
{
    char *ptr;
	
    ptr = dest + StrLen(dest);
	
    while (*src != '\0')
    {
        *ptr = *src;
        ++ptr;
        ++src;
    }
	
    *ptr = '\0';
	
    return dest;
}



/*****************************StrnCat*****************************

                  Joins first n bytes to the string             */
                  

char *StrnCat(char *dest, const char *src, size_t n)
{
    char *ptr;
	
    ptr = dest + StrLen(dest);
	
    while (*src != '\0' && n--)
    {
        *ptr++ = *src++;
    }
	
    *ptr = '\0';
	
    return dest;
}


/*****************************StrStr******************************

                       Locates a substring                      */


char *StrStr (const char *haystack, const char *needle)
{
    size_t l = StrLen(needle), i = 0;
       
    while(('\0' != *haystack ))
    {
            
        while (*haystack != *needle && ('\0' !=  *haystack ) )
        {
            ++haystack;
        }

        while (i < l && *(haystack + i) == *(needle + i) && '\0' != *(haystack + i) )
        {
            ++i;
        }

        if (i == l)
        {
            return (char *)haystack;
        }
        else if ('\0' != *haystack)
        {
            haystack++;
        }
    }

    return NULL;
}



/*****************************StrSpn******************************

               Gets length of a prefix substring
      Returns the number of characters in the initial segment 
         of str1 which consist only of characters from str2     */
         

size_t StrSpn(const char *s, const char *accept)
{
    size_t count = 0;
	
    while (*s && StrChr(accept, *s++))
    {
        count++;
    }
	
    return count;
}
    
    
    
/*****************************StrCmp*****************************

                     Compares two strings                      */
                     
    
int StrCmp(const char *str1, const char *str2)
{ 
    int i = 0;
     
    while (*(str1+i) == *(str2+i) && *(str1+i) != '\0' && *(str2+i) != '\0')
    {
        ++i;
    }
    
    return (*(str1+i)-*(str2+i));
} 
    
    
/*****************************StrLen*****************************
 
                      Returns string length                    */
                      

int StrLen(const char *str)
{ 
    const char *start = str;
   
    while (*str)
    {
        ++str;
    }
 
    return str - start;
 }
 
 
 
 
 
 
 
 
    
    
    
