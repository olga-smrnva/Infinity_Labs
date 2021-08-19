/*****************************************************************
*                                                                *
*File: printme.c                                                 *
*Description: Create a strucuture and work with it               *
*Author: Olga Smirnova                                           *
*Reviewer: Moshé Frydmann                                        *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
  
void Print(int a);

int main()
{ 
    struct print_me
    {
        int a;
        void (*print_ptr)(int);
    };
    
    struct print_me pm[10];
    
    int i = 0;
    int j = 1;
    
    for(i = 0; i < 10; ++i)
    {
      pm[i].a = j;
        j*=2;
        
      pm[i].print_ptr = Print;
      
      pm[i].print_ptr (pm[i].a); /* To call Print() */
    }
    
    return 0;
}

void Print(int a)
{
    printf("Here is the int value: %d \n", a);
}
