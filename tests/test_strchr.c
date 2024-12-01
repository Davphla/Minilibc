#include <assert.h>
#include "libasm.h"

void test_strchr() {
    char *s = "Hello, world!";
    char *result;

    result = asm_strchr(s, 'H');
    assert(result == s);

    result = asm_strchr(s, 'o');
    assert(result == s + 4);

    result = asm_strchr(s, ',');
    assert(result == s + 5);

    result = asm_strchr(s, 'z');
    assert(result == NULL);

    result = asm_strchr(s, '\0');
    assert(result == s + 13);
   
    printf("Strchr tests passed!\n");
}

