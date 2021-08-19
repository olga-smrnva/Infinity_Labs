/*****************************************************************
*                                                                *
*File: mem.c                                                     *
*Description: Functions that act like the library functions      *
              memset(), memcpy(), memmove()                      *
*Author: Olga Smirnova                                           *
*Reviewer: Jania Peimer                                          *
*                                                                *
*****************************************************************/

#include <string.h>   /* memset, memcpy, memmove */
#include <stddef.h>   /* size_t */
#include "mem.h"

#define WORD_SIZE sizeof(size_t)

/* Function fills the first n bytes of the memory area pointed to by s 
                    with the constant byte c */
                    
void *Memset(void *s, int c, size_t n)
{
	unsigned char *p_s = (unsigned char *) s;
	
	size_t i = 0;
	size_t words = 0;
	size_t bytes_left = 0;
	
	size_t *p_sizet_s = (size_t *)s; 
	size_t val_to_set = 0;
	
	unsigned char *p_val = (unsigned char *)&val_to_set;
	
	words = n/WORD_SIZE; /* Amount of words to copy */
	bytes_left = n % WORD_SIZE; /* Amount of bytes left */
	
	/* Set byte-to-byte if n < WORD_SIZE */
	if (WORD_SIZE > n)
	{
		while (n) 
		{
			*p_s = (unsigned char) c;
			p_s++;
			n--;
		}
	}
	/* Set by WORD */
	else 
	{
		/* Create a block of "c" size of WORD*/
		for (i=0; i < WORD_SIZE; ++i)
		{
			p_val[i] = (unsigned char) c;
		}
		
		for(i = 0; i < words; ++i)
		{
			*p_sizet_s = val_to_set;
			p_sizet_s++;
		}
		
		/* Copy byte-to-byte the rest amount of bytes */
		p_s = (unsigned char *)p_sizet_s;
	
		for (i=0; i < bytes_left; ++i)
		{
			*p_s = (unsigned char) c;
			p_s++;
		}
	}
	
	return s;
}


/* Function copies n bytes from memory area src to memory area dest */

void *Memcpy(void *dest, const void *src, size_t n)
{
	char *p_dest = (char *)dest;
	const char *p_src = (const char *)src;
	
	size_t i = 0;
	size_t words = 0;
	size_t bytes_left = 0;
	
	size_t *p_sizet_dest = (size_t *)dest; 
	size_t *p_sizet_src = (size_t *)src;
	
	words = n/WORD_SIZE; /* Amount of words to copy */
	bytes_left = n % WORD_SIZE; /* Amount of bytes left */ 
	
	/* Copy byte-to-byte if n < WORD_SIZE */
	if (WORD_SIZE > n)
	{
		while (n)
		{
			*(p_dest++) = *(p_src++);
			--n;
		}
	}
	/* Copy by WORD */
	else
	{
        	for(i = 0; i < words; ++i)
		{
			*p_sizet_dest = *p_sizet_src;
			p_sizet_dest++;
			p_sizet_src++;
		}
		
		/* Copy byte-to-byte the rest amount of bytes */
		p_dest = (char *)p_sizet_dest;
		p_src = (char *)p_sizet_src;
	
		for (i=0; i < bytes_left; ++i)
		{
			*(p_dest++) = *(p_src++);
		}
	}

	return dest;
}


/* Function copies n bytes from memory area src to memory area dest.
                    The memory areas may overlap */

void *Memmove(void *dest, const void *src, size_t n)
{
	char *p_dest = (char *)dest;
	char *p_src = (char *)src;
	
	char *p_src_end = p_src + n;
	char *p_dest_end = p_dest + n;
	
	size_t i = 0;
	
	/* If there is an overlap, copy from the end to the beginning */
	if ((p_src < p_dest) && (p_src_end > p_dest))
	{
		for (i=0; i < n + 1; ++i)
		{
			*p_dest_end = *p_src_end;
			p_dest_end--;
			p_src_end--;
		}
	}
	/* If there is no overlap, copy as usual */
	else
	{
		Memcpy(dest, src, n);
	}
  	
  	return dest;
}











