#include <stdio.h>
#include <string.h>
#include <assert.h>

extern size_t strlen(const char *__s);

void test_strlen() {
    // Test empty string
    assert(strlen("") == 0);

    // Test single character string
    assert(strlen("a") == 1);

    // Test multiple character string
    assert(strlen("hello") == 5);

    // Test string with spaces
    assert(strlen("hello world") == 11);

    // Test string with special characters
    assert(strlen("!@#$%^&*()") == 10);

    // Test string with numbers
    assert(strlen("1234567890") == 10);

    // Test string with mixed characters
    assert(strlen("abc123!@#") == 9);

    // Test string with newline character
    assert(strlen("hello\nworld") == 11);

    // Test string with tab character
    assert(strlen("hello\tworld") == 11);

    // Test string with null character in the middle
    assert(strlen("hello\0world") == 5);

    printf("All tests passed!\n");
}

int main() {
    test_strlen();
    return 0;
}