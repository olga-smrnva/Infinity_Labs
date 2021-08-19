#ifndef __STR_H__
#define __STR_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int StrLen(const char *str);
int StrCmp(const char *str1, const char *str2);
char *StrCpy(char *dest, const char *src);
char *StrnCpy(char *dest, const char *src, size_t n);
int StrCaseCmp(const char *s1, const char *s2);
char *StrChr(const char *s, int c);
char *StrDup(const char *s);
char *StrCat(char *dest, const char *src);
char *StrnCat(char *dest, const char *src, size_t n);
char *StrStr (const char *haystack, const char *needle);
size_t StrSpn(const char *s, const char *accept);

#endif /* __STR_H__ */
