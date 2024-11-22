#include <stdio.h>
#include <string.h>
#include <assert.h>

extern size_t strlen1(const char *__s);

void test_strlen() {
    // Test empty string
    assert(strlen1("") == 0);

    // Test single character string
    assert(strlen1("a") == 1);

    // Test multiple character string
    assert(strlen1("hello") == 5);

    printf("All tests passed!\n");
}

int main() {
    test_strlen();
    return 0;
}