/*******************************************************************************
*                                                                              *
*Group: OL99                                                                   *
*File: cbuffer.c                                                               *
*Description: Functions to simulate the Circular Buffer                        *
*Author: Olga Smirnova                                                         *
*Reviewer: Pavel Voropaev                                                      *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>		/* ssize_t, size_t */
#include <stdlib.h>		/* mallocs */
#include <assert.h>		/* assert */
#include <string.h>		/* memcpy */
#include <errno.h>		/* errno */

#include "cbuffer.h"

#define OFFSET(s,b) ((size_t)&(((s*)0)->b))
#define MIN2(a,b) ((a) < (b) ? (a) : (b))
#define MIN_CAPACITY (1)

struct cbuffer
{
    size_t size;
    size_t read_index;
    size_t capacity;
    char buffer[1];
};

/*******************************************************************************
*
	Decription: Creates Circular Buffer and returns pointer to it. O(1)	
	Input: Capacity of buffer (number of bytes)
	Return Value: NULL if fails to allocate or pointer to cbuffer if succeeds.	
	
	Reviewer: Anna Savina                                                    
	Status: approved
*
*******************************************************************************/
cbuffer_t *CBufferCreate(size_t capacity)
{
	cbuffer_t *c_buffer = (cbuffer_t *)malloc(OFFSET(cbuffer_t, buffer) + 
										capacity * sizeof(c_buffer->buffer[0]));

	assert(MIN_CAPACITY < capacity);
	
	if(NULL == c_buffer)
	{
		return NULL;
	}
	
	c_buffer->size = 0;
	c_buffer->read_index = 0;
	c_buffer->capacity = capacity;
	
	return c_buffer;

}

/*******************************************************************************
*
	Decription: Frees allocated space for Circular Buffer. O(1)
	
	Reviewer: Anna Savina                                                    
	Status: approved
*
*******************************************************************************/
void CBufferDestroy(cbuffer_t *c_buffer)
{
	assert(c_buffer);
	
	c_buffer->size = 0;
	c_buffer->read_index = 0;
	c_buffer->capacity = 0;
	
	free(c_buffer);
	c_buffer = NULL;
}

/*******************************************************************************
*
	Decription: Writes data (bytes) up to size of 'count', 
												  from 'src' to 'c_buffer'. O(n)	

	Return Value: Quantity of bytes written. If 'count' is bigger then free space, 
	copy up until reaches free space. -1 if failed.		
	
	Reviewer: Pavel Voropaev                                                    
	Status: approved
*
*******************************************************************************/
ssize_t CBufferWrite(cbuffer_t *c_buffer, const void *src, size_t count)
{
	const char *temp_s = NULL;
	size_t write_index = 0; 
	ssize_t bytes_written = 0;
	
	if(NULL == c_buffer)
	{
		errno = EBADF;
		return -1;
	}	

	if(NULL == src)
	{
		errno = EFAULT;
		return -1;
	}
	
	temp_s = (const char *)src;
	
	bytes_written = MIN2(count, CBufferFreeSpace(c_buffer));

	write_index = (c_buffer->size + c_buffer->read_index) % c_buffer->capacity;
	
	if(bytes_written < (ssize_t)(c_buffer->capacity - write_index)) 
	{
		memcpy(&c_buffer->buffer[write_index], temp_s, count);
	}
	else 
	{
		memcpy(&c_buffer->buffer[write_index], temp_s, 
											(c_buffer->capacity - write_index));
		memcpy(&c_buffer->buffer[0], 
						&temp_s[(c_buffer->capacity - write_index)], 
						(bytes_written - (c_buffer->capacity - write_index)));
	}
	

	c_buffer->size = c_buffer->size + bytes_written;
	
	return bytes_written;
}

/*******************************************************************************
*
	Decription: Read data (bytes) up to size of 'count', from 'c_buffer' to 'dest'.
				O(n)	

	Return Value: Number of bytes read. If 'count' is bigger then size, 
												read up until size. -1 if Failed.
	
	Reviewer: Pavel Voropaev                                                    
	Status: approved
*
*******************************************************************************/
ssize_t CBufferRead(cbuffer_t *c_buffer, void *dest, size_t count)
{
	char *temp_d = NULL;
	ssize_t bytes_written = 0;
	
	if(NULL == c_buffer)
	{
		errno = EBADF;
		return -1;
	}	

	if(NULL == dest)
	{
		errno = EFAULT;
		return -1;
	}
	
	temp_d = (char *)dest;
	
	bytes_written = MIN2(count, CBufferSize(c_buffer));
	
	if(bytes_written < (ssize_t)(c_buffer->capacity - c_buffer->read_index)) 
	{
		memcpy(temp_d, &c_buffer->buffer[c_buffer->read_index], bytes_written);
		
		c_buffer->read_index += bytes_written;
	}
	else 
	{
		memcpy(temp_d, &c_buffer->buffer[c_buffer->read_index],
									(c_buffer->capacity - c_buffer->read_index));
		
		memcpy(&temp_d[(c_buffer->capacity - c_buffer->read_index)],
				&c_buffer->buffer[0], 
				(bytes_written - (c_buffer->capacity - c_buffer->read_index)));
		
		c_buffer->read_index = bytes_written - (c_buffer->capacity 
													- c_buffer->read_index);
	}
	
	
	c_buffer->size = c_buffer->size - bytes_written;
	
	return bytes_written;
}	

/*******************************************************************************
*
	Decription: Checks if 'c_buffer' is empty. O(1)
	Return Value: 1 if is empty, 0 if is not empty.
	
	Reviewer: Anna Savina                                                    
	Status: approved
*
*******************************************************************************/
int CBufferIsEmpty(const cbuffer_t *c_buffer)
{
	assert(c_buffer);
	
	return (0 == c_buffer->size);
}

/*******************************************************************************
*
	Decription: Checks size of c_buffer's buffer (array). O(1)		
	Return Value: Size of buffer, i.e how many bytes are already.		
	
	Reviewer: Anna Savina                                                    
	Status: approved
*
*******************************************************************************/
size_t CBufferSize(const cbuffer_t *c_buffer)
{
	assert(c_buffer);
	
	return c_buffer->size;
	
}

/*******************************************************************************
*
	Decription: Checks how much free space there is in the buffer. O(1)
	Return Value: 0 if no free space.	
	
	Reviewer: Anna Savina                                                    
	Status: approved
*
*******************************************************************************/
size_t CBufferFreeSpace(const cbuffer_t *c_buffer)
{
	assert(c_buffer);
	
	return (c_buffer->capacity - c_buffer->size);
}






