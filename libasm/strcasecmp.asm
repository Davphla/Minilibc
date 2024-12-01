[bits 64]

[global asm_strcasecmp]

asm_strcasecmp:
    ; pointer to first string
    ; pointer to second string
    cld

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
    movzx eax, sil
    movzx esi, dil

    ; return *s1 - *s2
    sub eax, esi
    ret
    

