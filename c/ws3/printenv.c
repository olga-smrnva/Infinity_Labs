/*****************************************************************
*                                                                *
*File: printenv.c                                                *
*Description: Function to cope all the environment variables in  *
 a buffer and print them in lower case                           *
*Author: Olga Smirnova                                           *
*Reviewer: Pavel Voropaev                                        *
*                                                                *
*****************************************************************/


#include <stdio.h>    /* printf */
#include <stdlib.h>   /* malloc, free */
#include <ctype.h>    /* tolower */


int RowCount(char **envp);
int RowSize(char *envp);
int PrintEnv(char **envp);


int main(int argc, char **argv, char **envp)
{
    PrintEnv(envp);
    
    (void)argc;
    (void)**argv;
    
    return 0;
}

int PrintEnv(char **envp)
{
    char **buffer = NULL;
    int i = 0, j = 0;
    
    buffer = (char **)malloc(RowCount(envp)*sizeof(char*));
    
    for (i=0; envp[i] != NULL; ++i)
    {
       
        buffer[i] = (char *)malloc(RowSize(envp[i])*sizeof(char));
        
        for (j=0; envp[i][j] != '\0'; ++j)
        {
            buffer[i][j] = tolower(envp[i][j]);
        }
        
        buffer[i][j+1] = '\0';
        
        printf("%s\n", buffer[i]);
        
        free(buffer[i]);
        buffer[i] = NULL;
    }
    
    free(buffer);
    buffer = NULL;
    
    return 0;
}

int RowCount(char **envp)
{
    int i = 0;
    int count = 0;
    
    for (i = 0; envp[i] != NULL; ++i)
    {
        ++count;
    }
    return count;
}

int RowSize(char *envp)
{
    int i = 0;
        
    for(i = 0; envp[i] != '\0'; ++i)
    {
        ++i;
    }
    ++i;
    
    return i;
}
