#pragma once

#include <stdio.h>

extern size_t asm_strlen(const char *__s);
extern char *asm_strchr(const char *s, int c);
extern void *asm_memset(void *s, int c, size_t n);
extern int asm_strcmp(const char *s1, const char *s2);
extern int asm_strncmp(const char *s1, const char *s2, size_t n);


