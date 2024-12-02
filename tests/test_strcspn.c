#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strcspn()
{
    const char *s1 = "abcdef";
    const char *s2 = "xyz";
    const char *s3 = "cde";
    const char *s4 = "";
    const char *s5 = "a";
    const char *s6 = "f";

    // Test 1
    assert(asm_strcspn(s1, s2) == strcspn(s1, s2));
    // Test 2
    assert(asm_strcspn(s1, s3) == strcspn(s1, s3));
    // Test 3
    assert(asm_strcspn(s1, s4) == strcspn(s1, s4));
    // Test 4
    assert(asm_strcspn(s1, s5) == strcspn(s1, s5));
    // Test 5
    assert(asm_strcspn(s1, s6) == strcspn(s1, s6));
    // Test 6
    assert(asm_strcspn(s4, s1) == strcspn(s4, s1));
    // Test 7
    assert(asm_strcspn(s4, s4) == strcspn(s4, s4));
    // Test 8
    assert(asm_strcspn(s1, "gh") == strcspn(s1, "gh"));
    // Test 9
    assert(asm_strcspn("1234567890", "0987") == strcspn("1234567890", "0987"));
    // Test 10
    assert(asm_strcspn("hello world", " ") == strcspn("hello world", " "));
    puts("Strcspn tests passed!");
}
