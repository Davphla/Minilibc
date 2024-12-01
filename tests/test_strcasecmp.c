#include "libasm.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_strcasecmp()
{
    // Test case 1: Identical strings
    assert(strcasecmp("hello", "hello") == 0);

    // Test case 2: Case insensitive comparison
    assert(strcasecmp("hello", "HELLO") == 0);

    // Test case 3: Different strings
    assert(strcasecmp("hello", "world") != 0);

    // Test case 4: Strings with different lengths
    assert(strcasecmp("hello", "helloo") != 0);

    // Test case 5: Empty strings
    assert(strcasecmp("", "") == 0);

    // Test case 6: One empty string
    assert(strcasecmp("hello", "") != 0);
    assert(strcasecmp("", "hello") != 0);

    // Test case 7: Strings with special characters
    assert(strcasecmp("hello!", "HELLO!") == 0);
    assert(strcasecmp("hello!", "HELLO?") != 0);

    // Test case 8: Strings with numbers
    assert(strcasecmp("hello123", "HELLO123") == 0);
    assert(strcasecmp("hello123", "HELLO124") != 0);

    printf("strcasecmp passed!\n");
}
