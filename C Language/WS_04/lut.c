/*****************************************************************
*                                                                *
*File: switch.c                                                  *
*Description: Function to print "A pressed" is 'A' was pressed   *
 and "T pressed" is 'T' was pressed using LUT                    *
*Author: Olga Smirnova                                           *
*Reviewer: Benjamin Bitton                                       *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* system */
#define ESC (27)

static void PressA()
{
    printf("A pressed\n");
}

static void PressT()
{
    printf("T pressed\n");
}

static void Empty()
{
}

int main()
{
    unsigned char a = 'b';
    int i = 0;
    
    void (*pf[256])() = {NULL};
    
    for(i = 0; i < 256; ++i)
    {
        pf[i] = Empty;
    }

    pf['A'] = PressA;
    pf['T'] = PressT;    
  
    system("stty -icanon -echo");
       
    while(ESC != a)
    {
        printf("Press any button on your keybord\n");
        scanf("%c", &a);
        
        pf[a]();
    }       
    system("stty icanon echo");      
    
    return 0;
}
