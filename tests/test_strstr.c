#include "libasm.h"
#include <assert.h>
#include <string.h>

void test_strstr()
{
    // Test 1: Substring is found at the beginning
    assert(asm_strstr("hello world", "hello") == strstr("hello world", "hello"));

    // Test 2: Substring is found in the middle
    assert(asm_strstr("hello world", "world")
           == strstr("hello world", "world"));

    // Test 3: Substring is not found
    assert(asm_strstr("hello world", "test") == strstr("hello world", "test"));

    // Test 4: Substring is empty
    assert(asm_strstr("hello world", "") == strstr("hello world", ""));

    // Test 5: Both strings are empty
    assert(asm_strstr("", "") == strstr("", ""));

    // Test 6: Substring is longer than the string
    assert(asm_strstr("hello", "hello world")
           == strstr("hello", "hello world"));

    // Test 7: Substring is found at the end
    assert(asm_strstr("hello world", "world")
           == strstr("hello world", "world"));

    // Test 8: Substring is a single character
    assert(asm_strstr("hello world", "o") == strstr("hello world", "o"));

    // Test 9: Substring is not found in a single character string
    assert(asm_strstr("h", "o") == strstr("h", "o"));

    // Test 10: Substring is found in a single character string
    assert(asm_strstr("h", "h") == strstr("h", "h"));
    puts("Strstr tests passed!");
}
