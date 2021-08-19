/*****************************************************************
*                                                                *
*File: ifelse.c                                                  *
*Description: Function to print "A pressed" is 'A' was pressed   *
 and "T pressed" is 'T' was pressed using if/else                *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                        *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* system */
#define ESC (27)

int main()
{
    char a = 'b';
    system("stty -icanon -echo");
    
    while(ESC != a)
    {
        printf("Press any key on your keybord\n");
        scanf("%c", &a);
    
        if (ESC == a)
        {
            system("stty icanon echo");
            return 0;
        }
        else if('A' == a)
        {
            printf("A pressed\n");
        } 
        else if('T' == a)
        {
            printf("T pressed\n");
        }
        else
        {
            printf("Try again\n");
        } 
    }       
    
    return 0;
}

