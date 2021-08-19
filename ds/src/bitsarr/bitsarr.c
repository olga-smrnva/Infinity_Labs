/*******************************************************************************
*                                                                              *
*File: bitsarr.c                                                               *
*Description: Functions to work with the 64bits array                          *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna, Jania, Tsivia, Pavel                                          *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/

#include <stddef.h>  /* size_t */
#include <limits.h>  /* CHAR_BIT */
#include <assert.h>

#include "../include/bitsarr.h"

#define UINT64_BITS (sizeof(uint64_t) * CHAR_BIT) 
#define MASK_ALL_ONES 0xffffffffffffffff
#define MASK_1 1lu
#define MASK_0 0
#define MASK_15 15lu


/* Set all the bits of bit_array to 1 */

bitsarr_t BitsArrSetAll(bitsarr_t bit_array)
{
	return bit_array | MASK_ALL_ONES;
}


/* Set all the bits of bit_array to 0 */

bitsarr_t BitsArrResetAll(bitsarr_t bit_array)
{
	return bit_array & MASK_0;
}


/* Set the bit number 'index' of the bit_array to 1
   index should be contain between 1 and 64 */

bitsarr_t BitsArrSetOn(bitsarr_t bit_array, size_t index)
{
	assert(UINT64_BITS > index);
	
	return bit_array | (MASK_1<<index);
}


/* Set the bit number 'index' of the bit_array to 0 
   index should be contain between 1 and 64 */

bitsarr_t BitsArrSetOff(bitsarr_t bit_array, size_t index)
{
	assert(UINT64_BITS > index);
	
	return bit_array & ~(MASK_1 << index);
}


/* Set the specific 'index' of the bit_array to set_value 
   index should be contain between 1 and 64; boolean_value should be 0 or 1, 
   else the behaviour of the function is undefined */
   
bitsarr_t BitsArrSetBit(bitsarr_t bit_array, size_t index, int boolean_value)
{
	assert(UINT64_BITS > index);
	assert(0 == boolean_value || 1 == boolean_value );
	
	return ((1 == boolean_value) ? (BitsArrSetOn(bit_array, index)) : 
					      (BitsArrSetOff(bit_array, index)));
}


/* Get the value of a specific index in the bit_array, 
   returns 1 if it is on, 0 if it is set off 
   index should be contain between 1 and 64 */

int BitsArrGetVal( bitsarr_t bit_array, size_t index)
{
	assert(UINT64_BITS > index);
	
	return (0 != (bit_array & (MASK_1 <<(index))));
}


/* Flip the values of the 'index' bit of the bit_array */

bitsarr_t BitsArrFlip(bitsarr_t bit_array, size_t index)
{
	assert(UINT64_BITS > index);
	
	bit_array ^= MASK_1 << index;
	
	return bit_array;
}


/* Rotate bit_array to the right num_rotation time */

bitsarr_t BitsArrRotationRight(bitsarr_t bit_array, size_t num_rotation)
{
	return ((bit_array>>num_rotation)|
				      (bit_array<<(UINT64_BITS - num_rotation)));
}


/* Rotate bit_array to the left num_rotation time */

bitsarr_t BitsArrRotationLeft(bitsarr_t bit_array, size_t num_rotation)
{
	return ((bit_array<<num_rotation)|
				      (bit_array>>(UINT64_BITS - num_rotation)));
}


/* Returns the number of bits 'set on' on bit_array */

size_t BitsArrCountBitsOn(bitsarr_t bit_array)
{
	size_t count = 0;
	
	while (bit_array)
	{
		bit_array = bit_array & (bit_array - MASK_1);
		++count;
	}
	
	return count;
}


/* Returns the number of bits 'set off' on bit_array */

size_t BitsArrCountBitsOff(bitsarr_t bit_array)
{
	return UINT64_BITS - BitsArrCountBitsOn(bit_array);
}


/* Write the bits of bit_array as characters inside of dest array  
   dest should be able to contain 65 character (64 bits + '\0'), */

char *BitsArrToString(bitsarr_t bit_array, char *dest)
{
	size_t i = 0;

	assert(dest);

	for (i = 0; UINT64_BITS > i;  ++i)
	{
	     dest[UINT64_BITS - i - MASK_1] = BitsArrGetVal(bit_array, i) + '0';
	}
	dest[i] = '\0';

	return dest;
}


/* Mirror the bit_array */

bitsarr_t BitsArrMirror(bitsarr_t bit_array)
{
	bitsarr_t result = 0;
	bitsarr_t i = 0;
	
	for (i = 0; i < UINT64_BITS; ++i)
	{
	  result |= ((bit_array >> i) & MASK_1) << ((UINT64_BITS - MASK_1) - i);
	}
		
	return result;
}

/************************* Functions with LUT *********************************/

/************************* BitsArrMirrorLUT ***********************************/

bitsarr_t BitsArrMirrorLUT(bitsarr_t bit_array)
{
	bitsarr_t lut_mirr[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	bitsarr_t result = 0;
	bitsarr_t n = bit_array;
	
	result |= lut_mirr[n&15lu]<<60 | (lut_mirr[(n>>4)&15lu]<<56) | 
	(lut_mirr[(n>>8)&15lu]<<52) | (lut_mirr[(n>>12)&15lu]<<48) |
	(lut_mirr[(n>>16)&15lu]<<44) | (lut_mirr[(n>>20)&15lu]<<40) |
	(lut_mirr[(n>>24)&15lu]<<36) | (lut_mirr[(n>>28)&15lu]<<32) |
	(lut_mirr[(n>>32)&15lu]<<28) | (lut_mirr[(n>>36)&15lu]<<24) |
	(lut_mirr[(n>>40)&15lu]<<20) | (lut_mirr[(n>>44)&15lu]<<16) |
	(lut_mirr[(n>>48)&15lu]<<12) | (lut_mirr[(n>>52)&15lu]<<8) |
	(lut_mirr[(n>>56)&15lu]<<4) | lut_mirr[(n>>60)&15lu];
	
	return result;
}


/************************* BitsArrCountBitsOnLUT ******************************/

size_t BitsArrCountBitsOnLUT(bitsarr_t bit_array)
{
	char lut_num_bits_1[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	size_t count = 0;
	bitsarr_t n = bit_array;
	
	if (0 >= n)
	{
		return 0;
	}

	count = lut_num_bits_1[n & 15] + lut_num_bits_1[(n >> 4) & 15] +
		lut_num_bits_1[(n >> 8) & MASK_15] + 
		lut_num_bits_1[(n >> 12) & MASK_15] + 
		lut_num_bits_1[(n >> 16) & MASK_15] + 
		lut_num_bits_1[(n >> 20) & MASK_15] + 
		lut_num_bits_1[(n >> 24) & MASK_15] + 
		lut_num_bits_1[(n >> 28) & MASK_15] +
		lut_num_bits_1[(n >> 32) & MASK_15] + 
		lut_num_bits_1[(n >> 36) & MASK_15] +
		lut_num_bits_1[(n >> 40) & MASK_15] + 
		lut_num_bits_1[(n >> 44) & MASK_15] +
		lut_num_bits_1[(n >> 48) & MASK_15] + 
		lut_num_bits_1[(n >> 52) & MASK_15] +
		lut_num_bits_1[(n >> 56) & MASK_15] + 
		lut_num_bits_1[(n >> 60) & MASK_15];

	return count;
}
