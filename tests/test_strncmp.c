#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strncmp()
{
    assert(asm_strncmp("abc", "abc", 3) == 0);
    assert(asm_strncmp("abc", "abd", 3) < 0);
    assert(asm_strncmp("abd", "abc", 3) > 0);
    assert(asm_strncmp("abc", "abc", 2) == 0);
    assert(asm_strncmp("abc", "abd", 2) == 0);
    assert(asm_strncmp("abc", "ab", 3) > 0);
    assert(asm_strncmp("ab", "abc", 3) < 0);
    assert(asm_strncmp("abc", "abcd", 4) < 0);
    assert(asm_strncmp("abcd", "abc", 4) > 0);
    assert(asm_strncmp("", "", 1) == 0);
    assert(asm_strncmp("a", "", 1) > 0);
    assert(asm_strncmp("", "a", 1) < 0);
    printf("Strncmp passed!");
}
