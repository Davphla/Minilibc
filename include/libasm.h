#pragma once

#include <stdio.h>

extern size_t asm_strlen(const char *__s);
extern char *asm_strchr(const char *s, int c);
extern void *asm_memset(void *s, int c, size_t n);
extern int asm_strcmp(const char *s1, const char *s2);
extern int asm_strncmp(const char *s1, const char *s2, size_t n);
extern void *asm_memmove(void *dest, const void *src, size_t n);
extern int asm_strcasecmp(const char *s1, const char *s2);
extern char *asm_strstr(const char *haystack, const char *needle);
extern char *asm_strpbrk(const char *s, const char *accept);
extern size_t asm_strcspn(const char *s, const char *reject);