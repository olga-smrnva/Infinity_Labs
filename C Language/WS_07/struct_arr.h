#ifndef __STRUCT_ARR_H__
#define __STRUCT_ARR_H__

#include <stddef.h>

typedef struct generic_type generic_type_t; 

struct generic_type {
	void *element;
	void (*Print)(generic_type_t *generic_struct);
	int (*Add)(generic_type_t *generic_struct, int to_add);
	void (*Clean)(generic_type_t *generic_struct);
};

/*****************Prints all the elements of the array*************/
void PrintArr(generic_type_t arr[], size_t size);


/**************Add to_add to all the element of the array**********/
int AddtoArr(generic_type_t arr[], int to_add, size_t size);

/****Function to add to_add in case the structs contains an int****/
int AddInt(generic_type_t *struct_int, int to_add);

/***Function to add to_add  in case the structs contains a float***/
int AddFloat(generic_type_t *struct_float, int to_add);

/****Function to add to_add  in case the structs contains a char***/
int AddChar(generic_type_t *struct_char, int to_add);


/*******Cleans the whole array (frees everything to be freed)******/
void CleanArr(generic_type_t arr[], size_t size);


/*********Initialises the first element of the struct with x*******/
int InitInt(generic_type_t *struct_int, int x);

/*********Initialises the first element of the struct with y*******/
int InitFloat(generic_type_t *struct_float, float y);

/********Initialises the first element of the struct with str******/
int InitChar(generic_type_t *struct_char, char *str);

#endif /* __STRUCT_ARR_H__ */
