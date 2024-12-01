#include "libasm.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_memmove()
{
    char src1[] = "Hello, World!";
    char dest1[20] = {};
    asm_memmove(dest1, src1, 13);
    assert(strcmp(dest1, "Hello, World!") == 0);

    char src2[] = "Overlap test";
    asm_memmove(src2 + 3, src2, 6);
    assert(strcmp(src2, "OveOverlaest") == 0);

    char src3[] = "Another test";
    asm_memmove(src3, src3 + 8, 4);
    assert(strcmp(src3, "testher test") == 0);

    char src4[] = "1234567890";
    asm_memmove(src4 + 2, src4, 5);
    assert(strcmp(src4, "1212345890") == 0);

    char src5[] = "Short";
    asm_memmove(src5, src5, 5);
    assert(strcmp(src5, "Short") == 0);

    printf("Memmove tests passed!\n");
}
