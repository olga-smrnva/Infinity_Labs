#ifndef BITWISE_H
#define BITWISE_H
#include <stdio.h>
#include <stdlib.h>

long Pow2(unsigned int x, unsigned int y);
int IsPow2(unsigned int x);
int IsPow2Loop(unsigned int x);
int AddOne(int x);
int Count3Bits(unsigned int *arr, size_t len);
unsigned int ByteMirror(unsigned int x);
unsigned int ByteMirrorLoop(unsigned int x);
int Check1(unsigned char c);
int Check2(unsigned char c);
unsigned char SwappBits(unsigned char c);
unsigned int Divisible16(unsigned int n);
void Swapp(unsigned int *a, unsigned int *b);
int CountBits(int n);
int CountBitsLoop(int n);
void FloatBits(float x);

#endif
