#include "libasm.h"
#include <assert.h>

void test_memset()
{
    char buffer[50] = {};

    // Test 1: Basic test
    asm_memset(buffer, 'A', 10);
    for (int i = 0; i < 10; i++) {
        assert(buffer[i] == 'A');
    }

    // Test 2: Zero length
    asm_memset(buffer, 'B', 0);
    // No change expected, so no need to check

    // Test 3: Full buffer
    asm_memset(buffer, 'C', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        assert(buffer[i] == 'C');
    }

    // Test 4: Partial buffer
    asm_memset(buffer, 'D', 25);
    for (int i = 0; i < 25; i++) {
        assert(buffer[i] == 'D');
    }

    printf("Memset tests passed!\n");
    
}
