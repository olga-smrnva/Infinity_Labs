/*****************************************************************
*                                                                *
*File: switch.c                                                  *
*Description: Function to print "A pressed" is 'A' was pressed   *
 and "T pressed" is 'T' was pressed using switch/case            *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
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
        printf("Press any button on your keybord\n");
        scanf("%c", &a);
        
        switch(a)
        {
            case ESC:
            system("stty icanon echo");
            return 0;
            break;
            
            case 'A':
            printf("A pressed\n");
            break;
            
            case 'T':
            printf("T pressed\n");
            break;
            
            default:
            printf("Try again\n");            
        }
    }       
    
    return 0;
}

