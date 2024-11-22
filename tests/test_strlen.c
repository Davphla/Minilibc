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

    printf("All tests passed!\n");
}

int main() {
    test_strlen();
    return 0;
}