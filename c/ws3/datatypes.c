/*****************************************************************
*                                                                *
*File: datatypes.c                                               *
*Description: Function to list all the data types and print      *
 the size of each type to stdout                                 *
*Author: Olga Smirnova                                           *
*Reviewer: Pavel Voropaev                                        *
*                                                                *
*****************************************************************/

#include <stdio.h>	/* fprintf */

int main(void)
{
    char type_name[15][27] = 
    {"char",
     "signed char",
     "unsigned char",
     "int",
     "short int",
     "signed short int",
     "unsigned short int",
     "unsigned int",
     "signed int",
     "long int",
     "signed long int",
     "unsigned long int",
     "float",
     "double",
     "long double"};
     
    size_t type_size[15] = 
    {sizeof(char), 
     sizeof(signed char),
     sizeof(unsigned char), 
     sizeof(int), 
     sizeof(short int), 
     sizeof(signed short int),
     sizeof(unsigned short int),  
     sizeof(signed int),  
     sizeof(long int), 
     sizeof(signed long int), 
     sizeof(unsigned long int), 
     sizeof(float), 
     sizeof(double),
     sizeof(long double)};

    size_t i = 0;

    for(i=0; i<= 14; i++)
    {
        fprintf(stdout, "the size of %s is  %lu.\n",type_name[i],type_size[i]);
    }

    return 0;
}

