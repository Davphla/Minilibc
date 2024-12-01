[bits 64]

[global asm_strncmp]

asm_strncmp:
    ; Compares two null-terminated strings.
    ; Parameters:
    ;   pointer to the first null-terminated string
    ;   pointer to the second null-terminated string
    ;   size to be compared
    ; Returns:
    ;   - A negative value if s1 is less than s2.
    ;   - Zero if s1 is equal to s2.
    ;   - A positive value if s1 is greater than s2.

char_cmp:
    ; test if size == 0
    test rdx, rdx
    jz end_string
    dec rdx 

    mov al, [rdi] ; Get byte to compare
    mov cl, [rsi]
    
    test al, cl ; Test if string ended
    jz end_string

    cmp al, cl ; Check if different character
    jne end_string

    inc rdi ; Move pointer and repeat
    inc rsi
    jmp char_cmp

end_string:
    movzx eax, al ; return *s1 - *s2
    movzx edx, cl
    sub eax, edx
    ret
    
