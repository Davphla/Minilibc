#include <assert.h>
#include "libasm.h"

void test_strlen() {
    // Test empty string
    assert(asm_strlen("") == 0);

    // Test single character string
    assert(asm_strlen("a") == 1);

    // Test multiple character string
    assert(asm_strlen("hello") == 5);

    printf("All tests passed!\n");
}

