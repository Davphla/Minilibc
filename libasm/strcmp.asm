[bits 64]

[global asm_strcmp]

asm_strcmp:
    ; Compares two null-terminated strings.
    ; Parameters:
    ;   rsi - pointer to the first null-terminated string
    ;   rdi - pointer to the second null-terminated string
    ; Returns:
    ;   - A negative value if s1 is less than s2.
    ;   - Zero if s1 is equal to s2.
    ;   - A positive value if s1 is greater than s2.

char_cmp:
    mov al, [rsi]
    mov bl, [rdi]

    test al, bl 
    jz end_string

    inc rsi
    inc rdi

    jmp char_cmp

end_string:
    sub al, bl 
    movsx rax, al
    ret