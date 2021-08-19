#ifndef __MEM_H__
#define __MEM_H__

#include <stddef.h>   /* size_t */

/* Function fills the first n bytes of the memory area pointed to by s 
                    with the constant byte c */
void *Memset(void *s, int c, size_t n);

/* Function copies n bytes from memory area src to memory area dest */
void *Memcpy(void *dest, const void *src, size_t n);

/* Function copies n bytes from memory area src to memory area dest.
                    The memory areas may overlap */
void *Memmove(void *dest, const void *src, size_t n);

#endif /* __MEM_H__ */
