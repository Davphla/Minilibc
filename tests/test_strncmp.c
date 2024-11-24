#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strncmp()
{
    int result_asm, result_libc;

    result_asm = asm_strncmp("Hello", "Hello", 5);
    result_libc = strncmp("Hello", "Hello", 5);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("Hello", "Hell", 4);
    result_libc = strncmp("Hello", "Hell", 4);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("Hello", "hello", 5);
    result_libc = strncmp("Hello", "hello", 5);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("hello", "Hello", 5);
    result_libc = strncmp("hello", "Hello", 5);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("Hell", "Hello", 4);
    result_libc = strncmp("Hell", "Hello", 4);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("HelloWorld", "HelloWorld", 10);
    result_libc = strncmp("HelloWorld", "HelloWorld", 10);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("HelloWorld", "Hello", 5);
    result_libc = strncmp("HelloWorld", "Hello", 5);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("HelloWorld", "Hello", 10);
    result_libc = strncmp("HelloWorld", "Hello", 10);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("Hello", "HelloWorld", 10);
    result_libc = strncmp("Hello", "HelloWorld", 10);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);

    result_asm = asm_strncmp("HelloWorld", "HelloWorld", 0);
    result_libc = strncmp("HelloWorld", "HelloWorld", 0);
    printf("asm_strncmp: %d, strncmp: %d\n", result_asm, result_libc);
    assert(result_asm == result_libc);
    printf("Strncmp test passed!\n");
}
