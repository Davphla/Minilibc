#include "libasm.h"
#include <assert.h>

void test_strcmp()
{
    int result;

    result = asm_strcmp("Hello", "Hello");
    assert(result == 0);

    result = asm_strcmp("Hello", "Hell");
    assert(result > 0);

    result = asm_strcmp("Hell", "Hello");
    assert(result < 0);

    result = asm_strcmp("Hello", "hello");
    assert(result < 0);

    result = asm_strcmp("hello", "Hello");
    assert(result > 0);

    printf("Strcmp test passed!\n");
}
