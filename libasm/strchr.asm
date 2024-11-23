[bits 64]

[global asm_strchr]

asm_strchr:
    ; Arguments:
    ; rdi - pointer to the string
    ; rsi - character to find
    xor rax, rax ; set to 0
    
find_char:
    mov bl, byte [rdi + rax] ; load next character

    cmp bl, sil 
    je found

    test bl, bl
    jz not_found

    inc rax
    jmp find_char

found:
    ; Return the pointer to the found character
    lea rax, [rdi + rax]
    ret

not_found:
    ; Return NULL (0) if the character is not found
    xor rax, rax
    ret

