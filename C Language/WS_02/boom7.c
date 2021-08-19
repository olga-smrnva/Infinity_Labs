/*****************************************************************
*                                                                *
*File: boom7.c                                                   *
*Description: Function to print given numbers, but instead of    *
 numbers which include or can be devided by 7 we print BOOM      *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Check(int a, int b);
int Boom(int a, int b);


int main ()
{
    printf("Here are the numbers: \n");
    Boom(1, 199);
    printf("\n THE END \n");

    return 0;
}

int Boom(int a, int b)
{
    int i = 0;
    
    for (i=a; i<=b; i++)
    {
        if (i%7 == 0 || Check(i, 7) == 1)
        {
            printf("BOOM ");
        }
        else
        {
            printf("%d ", i);
        }
    }
    return 0;
}

int Check(int a, int b)
{
    while (a > 0)
    {
        if (a%10 == b)
        {
        return 1;
        }
        
        a = a/10;
    }
    return 0;
}

