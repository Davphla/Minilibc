#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strpbrk()
{
    // Test 1: Normal case
    char str1[] = "hello world";
    char accept1[] = "ow";
    assert(strpbrk(str1, accept1) == asm_strpbrk(str1, accept1));

    // Test 2: No match
    char str2[] = "hello world";
    char accept2[] = "xyz";
    assert(strpbrk(str2, accept2) == asm_strpbrk(str2, accept2));

    // Test 3: Empty string
    char str3[] = "";
    char accept3[] = "a";
    assert(strpbrk(str3, accept3) == asm_strpbrk(str3, accept3));

    // Test 4: Empty accept
    char str4[] = "hello world";
    char accept4[] = "";
    assert(strpbrk(str4, accept4) == asm_strpbrk(str4, accept4));

    // Test 5: Both strings empty
    char str5[] = "";
    char accept5[] = "";
    assert(strpbrk(str5, accept5) == asm_strpbrk(str5, accept5));

    // Test 6: Match at the beginning
    char str6[] = "hello world";
    char accept6[] = "h";
    assert(strpbrk(str6, accept6) == asm_strpbrk(str6, accept6));

    // Test 7: Match at the end
    char str7[] = "hello world";
    char accept7[] = "d";
    assert(strpbrk(str7, accept7) == asm_strpbrk(str7, accept7));

    // Test 8: Multiple matches
    char str8[] = "hello world";
    char accept8[] = "lo";
    assert(strpbrk(str8, accept8) == asm_strpbrk(str8, accept8));
    puts("Strpbrk test passed!");
}
