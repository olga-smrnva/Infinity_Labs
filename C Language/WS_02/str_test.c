/*****************************************************************
*                                                                *
*File: str_test.c                                                *
*Description: Main function to test str.c functions              *
*Author: Olga Smirnova                                           *
*Reviewer: Rina Volovich                                         *
*                                                                *
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "str.h"


int TestIntFunction(int n1, int n2);
int TestCharFunction(char *expecterd, char *result);
int TestSize_tFunction(size_t n1, size_t n2);

int main()
{
    int c = 'r';
    
    const char src[12] = "Programming";
    const char s[40] = "Hello World"; 
    const char *s1 = "abcD";
    const char *s2 = "abcd";
    const char *s3 = "abcd ololo";
    
    const char *haystack1 = "Hello world";
    const char *haystack2 = "Hi world";
    const char *needle = "Hello";
    
    const char *accept = "b";
    

/****Variables to test StrCpy*****/
    char result[40] = "Hello World";
    char expected[40] = "Hello World";

    
/****Variables to test StrnCpy****/
    char src1[12] = "Ololo";
    char result1[40] = "Hello World";
    char expected1[40] = "Hello World";
    
    
/****Variables to test StrChr*****/
    char *result2 = StrChr(src, c);
    char *expected2 = strchr(src, c);
    char *result3 = StrChr(s, c);
    char *expected3 = strchr(s, c);
    
    
/****Variables to test StrCat*****/
    char src2[12] = "Hahaha";
    char dest_cat1[40] = "Hello";
    char dest_cat2[40] = "Hello";
    

/****Variables to test StrnCat****/
    char src3[12] = "Hohoho";
    char dest_ncat1[40] = "Hello";
    char dest_ncat2[40] = "Hello";
    
    
/****Variables to test StrDup*****/
    char *s4 = StrDup(s);
    
    
/****Variables to test StrStr*****/
    char *resultstr1 = StrStr(haystack1, needle);
    char *expectedstr1 = strstr(haystack1, needle);
    char *resultstr2 = StrStr(haystack2, needle);
    char *expectedstr2 = strstr(haystack2, needle);
    
/*******************************TESTS*******************************/


/*********TEST for StrCpy*********/
    printf("\nTEST for StrCpy\n");
    StrCpy(result, src);
    strcpy(expected, src);
    TestCharFunction(expected, result);


/*********TEST for StrnCpy********/
    printf("\nTEST for StrnCpy\n");
    StrnCpy(result1, src1, 5);
    strncpy(expected1, src1, 5);
    TestCharFunction(expected1, result1);
    

/*********TEST for StrChr*********/    
    printf("\nTEST for StrChr\n");
    TestCharFunction(expected2, result2);
    TestCharFunction(expected3, result3);
    
    
/*******TEST for StrCaseCmp*******/
    printf("\nTEST for StrCaseCmp\n");
    TestIntFunction(StrCaseCmp(s1, s2), strcasecmp(s1, s2));
    TestIntFunction(StrCaseCmp(s1, s2), strcasecmp(s1, s2));
    
    
/*********TEST for StrDup*********/
    printf("\nTEST for StrDup\n");
    printf("Expected result is: %s, result we have is: %s \n", s, s4);  
    free(s4);
    s4 = NULL;


/*********TEST for StrCat*********/
    printf("\nTEST for StrCat\n");
    StrCat(dest_cat1, src2);
    strcat(dest_cat2, src2);
    TestCharFunction(dest_cat2, dest_cat1);
    
    
/*********TEST for StrnCpy********/
    printf("\nTEST for StrnCat\n");
    StrnCat(dest_ncat1, src3, 5);
    strncat(dest_ncat2, src3, 5);
    TestCharFunction(dest_ncat2, dest_ncat1);    
    
    
/*********TEST for StrStr*********/
    printf("\nTEST for StrStr\n");
    TestCharFunction(expectedstr1, resultstr1);
    TestCharFunction(expectedstr2, resultstr2);
    
    
/*********TEST for StrSpn*********/
    printf("\nTEST for StrSpn\n");
    TestSize_tFunction(StrSpn(s3, accept), strspn(s3, accept));


return 0;
}




int TestIntFunction(int n1, int n2)
{
    if (n1 == n2)
    {
        printf("DONE \n");
        return 0;
    }
    else 
    {
        printf("FAIL \n");
        return 1;
    }
}

int TestCharFunction(char *expected, char *result)
{
    printf("Expected result is: %s, result we have is: %s \n", expected, result);
    
    if (NULL == expected && NULL == result)
    {
        printf("DONE \n");
        return 0;
    }
    else if (0 == StrCmp(expected, result))
    {
        printf("DONE \n");
        return 0;
    }
    else 
    {
        printf("FAIL \n");
        return 1;
    } 
}


int TestSize_tFunction(size_t n1, size_t n2)
{
    if (n1 == n2)
    {
        printf("DONE \n");
        return 0;
    }
    else 
    {
        printf("FAIL \n");
        return 1;
    }
}


