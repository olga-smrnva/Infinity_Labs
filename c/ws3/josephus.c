/*****************************************************************
*                                                                *
*File: josephus.c                                                *
*Description: Function to solve Josephus problem                 *
*Author: Olga Smirnova                                           *
*Reviewer: Pavel Voropaev                                        *
*                                                                *
*****************************************************************/

#include <stdio.h>	/* printf */

void Josephus(size_t *num, size_t men);

int main () 
{

    size_t num[100];
    size_t men = sizeof(num)/sizeof(num[0]);
    
    Josephus(num, men);

    return 0;

}


void Josephus(size_t *num, size_t men)
{

    size_t count = 0; 
    size_t out = 0;
    size_t i = 0, j = 0;

    for (j = 0; j < men; ++j)
        num[j] = 1;

    while (out < (men - 1))
    {
        if ((count + num[i]) == 2)
        {
            ++out;
            count = 0;
            num[i] = 0;
        }

        else
        {
            count += num[i];
        }
        
    i = (i + 1) % men;
    }

    for (i = 0; i < men; ++i)
        {
            if (num[i] == 1)
            {
                printf("The lucky one is solder number %ld \n", i + 1);
                return;
            }
        }
}
