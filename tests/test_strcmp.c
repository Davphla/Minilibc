#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strcmp()
{
    assert(asm_strcmp("abc", "abc") == 0);
    assert(asm_strcmp("abc", "abd") < 0);
    assert(asm_strcmp("abd", "abc") > 0);
    assert(asm_strcmp("abc", "ab") > 0);
    assert(asm_strcmp("ab", "abc") < 0);
    assert(asm_strcmp("abc", "abcd") < 0);
    assert(asm_strcmp("abcd", "abc") > 0);
    assert(asm_strcmp("", "") == 0);
    assert(asm_strcmp("a", "") > 0);
    assert(asm_strcmp("", "a") < 0);
    printf("Strcmp test passed!\n");

    printf("Strcmp test passed!\n");
}
