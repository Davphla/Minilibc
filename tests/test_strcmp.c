#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strcmp()
{
    int result_asm, result_libc;

    result_asm = asm_strcmp("Hello", "Hello");
    result_libc = strcmp("Hello", "Hello");
    printf("asm_strcmp: %d, strcmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strcmp("Hello", "Hell");
    result_libc = strcmp("Hello", "Hell");
    printf("asm_strcmp: %d, strcmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strcmp("Hello", "hello");
    result_libc = strcmp("Hello", "hello");
    printf("asm_strcmp: %d, strcmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strcmp("hello", "Hello");
    result_libc = strcmp("hello", "Hello");
    printf("asm_strcmp: %d, strcmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strcmp("Hell", "Hello");
    result_libc = strcmp("Hell", "Hello");
    printf("asm_strcmp: %d, strcmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    printf("Strcmp test passed!\n");
}
