#include "libasm.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_strcasecmp()
{
    // Test case 1: Identical strings
    assert(asm_strcasecmp("hello", "hello") == 0);

    // Test case 2: Case insensitive comparison
    assert(asm_strcasecmp("hello", "HELLO") == 0);

    // Test case 3: Different strings
    assert(asm_strcasecmp("hello", "world") != 0);

    // Test case 4: Strings with different lengths
    assert(asm_strcasecmp("hello", "helloo") != 0);

    // Test case 5: Empty strings
    assert(asm_strcasecmp("", "") == 0);

    // Test case 6: One empty string
    assert(asm_strcasecmp("hello", "") != 0);
    assert(asm_strcasecmp("", "hello") != 0);

    // Test case 7: Strings with special characters
    assert(asm_strcasecmp("hello!", "HELLO!") == 0);
    assert(asm_strcasecmp("hello!", "HELLO?") != 0);

    // Test case 8: Strings with numbers
    assert(asm_strcasecmp("hello123", "HELLO123") == 0);
    assert(asm_strcasecmp("hello123", "HELLO124") != 0);

    printf("Strcasecmp tests passed!\n");
}
