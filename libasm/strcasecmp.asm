[bits 64]

[global asm_strcasecmp]

asm_strcasecmp:
    ; pointer to first string
    ; pointer to second string

cmp_char:
    mov al, [rdi]
    mov cl, [rsi]

    test al, al ; al & cl == '\0'
    jz end_string
    test cl, cl
    jz end_string

    or al, 0x20 ; Convert to lowercase
    or cl, 0x20

    cmp al, cl
    jne end_string

    inc rdi
    inc rsi
    jmp cmp_char


end_string:
    movzx eax, al ; return *s1 - *s2
    movzx ecx, cl
    sub eax, ecx
    ret
    

