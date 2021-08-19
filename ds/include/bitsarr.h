/*******************************************************************************
*                                                                              *
*File: bitsarr.c                                                               *
*Description: Functions to work with the 64bits array                          *
*Author: Olga Smirnova                                                         *
*Reviewer: Anna, Jania, Tsivia, Pavel                                          *
*Status: approved                                                              *
*                                                                              *
*******************************************************************************/
#ifndef __BITS_ARRAY_H__
#define __BITS_ARRAY_H__

#include <stddef.h>	/*size_t*/
#include <stdint.h>    /*unint64_t*/

typedef uint64_t bitsarr_t;

/******************************** Functions ***********************************/

/* Set all the bits of bit_array to 1 */
bitsarr_t BitsArrSetAll(bitsarr_t bit_array);

/* Set all the bits of bit_array to 0 */
bitsarr_t BitsArrResetAll(bitsarr_t bit_array);

/* Set the bit number 'index' of the bit_array to 1
   index should be contain between 1 and 64 */
bitsarr_t BitsArrSetOn(bitsarr_t bit_array, size_t index);

/* Set the bit number 'index' of the bit_array to 0 
   index should be contain between 1 and 64 */
bitsarr_t BitsArrSetOff(bitsarr_t bit_array, size_t index);

/* Set the specific 'index' of the bit_array to set_value 
   index should be contain between 1 and 64; boolean_value should be 0 or 1, 
   else the behaviour of the function is undefined */
bitsarr_t BitsArrSetBit(bitsarr_t bit_array, size_t index, int boolean_value);

/* Get the value of a specific index in the bit_array, 
   returns 1 if it is on, 0 if it is set off 
   index should be contain between 1 and 64 */
int BitsArrGetVal( bitsarr_t bit_array, size_t index);

/* Flip the values of the 'index' bit of the bit_array */
bitsarr_t BitsArrFlip(bitsarr_t bit_array, size_t index);

/* Rotate bit_array to the right num_rotation time */
bitsarr_t BitsArrRotationRight(bitsarr_t bit_array, size_t num_rotation);

/* Rotate bit_array to the left num_rotation time */
bitsarr_t BitsArrRotationLeft(bitsarr_t bit_array, size_t num_rotation);

/* Returns the number of bits 'set on' on bit_array */
size_t BitsArrCountBitsOn(bitsarr_t bit_array);

/* Returns the number of bits 'set off' on bit_array */
size_t BitsArrCountBitsOff(bitsarr_t bit_array);

/* Write the bits of bit_array as characters inside of dest array  
   dest should be able to contain 65 character (64 bits + '\0'), */
char *BitsArrToString(bitsarr_t bit_array, char *dest);

/* Mirror the bit_array */
bitsarr_t BitsArrMirror(bitsarr_t bit_array);

/************************* Functions with LUT *********************************/
bitsarr_t BitsArrMirrorLUT(bitsarr_t bit_array);

size_t BitsArrCountBitsOnLUT(bitsarr_t bit_array);


#endif /* __BITS_ARRAY_H__ */
