/*****************************************************************
*                                                                *
*File: logger.c                                                  *
*Description: Program that asks the user to enter strings        *
*Author: Olga Smirnova                                           *
*Reviewer: Anna Savina                                           *
*                                                                *
*****************************************************************/

#include <stdio.h>    /* printf */
#include <stdlib.h>   
#include <string.h>   /* strcmp */

#define MAX 250

typedef enum status
{
	DONE,
	FAILED,
	QUIT
} status_t;  

typedef struct
{
	char *s;
	int (*compf_ptr)(char *user_input, char *src);
	status_t (*operf_ptr)(FILE *fp, char *user_input, char *filename);
} funcs_t;


static int Compare(char *user_input, char *src);
static int ComparePre(char *user_input, char *src);
static int Default(char *user_input, char *src);

static status_t Remove(FILE *fp, char *user_input, char *filename);
static status_t Count(FILE *fp, char *user_input, char *filename);
static status_t Exit(FILE *fp, char *user_input, char *filename);
static status_t ArrowMove(FILE *fp, char *user_input, char *filename);
static status_t AddString(FILE *fp, char *user_input, char *filename);

static status_t GetInput(char *argv[]);


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("To open the file enter its name after %s \n", argv[0]);
	}  
    
	GetInput(argv);
   
	return 0;
}


static int Compare(char *user_input, char *src)
{
	return (strcmp(user_input, src));
}


static int ComparePre(char *user_input, char *src)
{
	return *user_input - *src;
}


static status_t Remove(FILE *fp, char *user_input, char *filename)
{
	remove(filename);
	
	(void)user_input;
	(void)fp;	
	return DONE;
} 


static status_t Count(FILE *fp, char *user_input, char *filename)
{	
	int count = 0; 
	char c = '\0'; 
	
	(void)user_input;
   
	fp = fopen(filename, "r");
    
	if (NULL == fp) 
	{ 
		printf("Could not open the file\n"); 
		return FAILED; 
	}

	for (c = getc(fp); EOF != c; c = getc(fp))
	{
		if ('\n' == c)
		{
			count = count + 1;
		}
	}
	
	fclose(fp);
	printf("The file has %d lines\n ", count);
    
	return DONE;
}  


static status_t Exit(FILE *fp, char *user_input, char *filename)
{
	(void)fp;
	(void)user_input;
	(void)filename;
	
	return QUIT;
}  


static status_t ArrowMove(FILE *fp, char *user_input, char *filename)
{
	char c = '\0'; 
	int n = 0;
	
	FILE *fp1 = fopen("copy.txt", "w");
    
	if ( NULL == fp1) 
	{ 
		printf("Could not open the file\n"); 
		return 0; 
	}
        
	++user_input;
	fputs(user_input, fp1);
	
	fp = fopen(filename, "r");
    
	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	while (n--)
	{
		c = fgetc(fp);
		fputc(c, fp1);
	}

	fclose(fp1);
	fclose(fp);
	
	fp = fopen(filename, "w+");
	if (NULL == fp)
	{
		return FAILED;
	}
	fp1 = fopen("copy.txt", "r");
	if (NULL == fp1)
	{
		return FAILED;
	}



	fseek(fp1, 0, SEEK_END);
	n = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);

	while (n--)
	{
		c = fgetc(fp1);
		fputc(c, fp);
	}

	fclose(fp1);
	fclose(fp);
	remove("copy.txt");
	
	return DONE;
}


static status_t AddString(FILE *fp, char *user_input, char *filename)
{
	fp = fopen(filename, "a+");
    
	if (fp == NULL) 
	{ 
		printf("Could not open the file\n"); 
		return FAILED; 
	}
        
	fputs(user_input, fp);
        fclose(fp);
    
	return DONE;
}


static int Default(char *user_input, char *src)
{
	(void)user_input;
	(void)src;
	
	return 0;
}


static status_t GetInput(char*argv[])
{
	funcs_t arr[LEN] = 
	{
		{"-remove\n", Compare, Remove},
		{"-count\n", Compare, Count},
		{"-exit\n", Compare, Exit},
		{"<", ComparePre, ArrowMove},
		{"", Default, AddString}
	};

	status_t cs = DONE;
	int i = 0;
	FILE *fp = NULL;
	char user_input[MAX] = "abc";
	
	printf("Enter your message (no more than %d characters) : \n", MAX);
	
	while(QUIT != cs)
	{
		fgets(user_input, MAX, stdin);
		
		for (i = 0; (QUIT != cs); ++i)
		{
			if (0 == arr[i].compf_ptr(user_input, arr[i].s))
			{
				cs = arr[i].operf_ptr(fp, user_input, argv[1]);
				break;
			}
		}
		
	}
	return cs;
}


















