[bits 64]

[global asm_strcasecmp]

asm_strcasecmp:
    ; Arguments:
    ; rdi - pointer to first string
    ; rsi - pointer to second string

; Compare char
cmp_char:
    ; set lowercase
    or sil, 0x20
    or dil, 0x20

    ; sil & dil == '\0'
    test sil, dil
    jz done

    ; cmp sil, dil
    cmpsb
    je cmp_char

done:
    ; add sil, dil
    movzx eax, dil
    movzx edi, sil

    ; return *s1 - *s2
    sub eax, edi
    ret
    

