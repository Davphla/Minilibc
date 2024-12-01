[bits 64]

[global asm_strcmp]

asm_strcmp:
    ; Compares two null-terminated strings.
    ; Parameters:
    ;   pointer to the first null-terminated string
    ;   pointer to the second null-terminated string
    ; Returns:
    ;   - A negative value if s1 is less than s2.
    ;   - Zero if s1 is equal to s2.
    ;   - A positive value if s1 is greater than s2.

cmp_char:
    mov al, [rdi]
    mov cl, [rsi]

    test al, al ; al & cl == '\0'
    jz done
    test cl, cl
    jz done

    cmp al, cl
    jne done

    inc rdi
    inc rsi
    jmp cmp_char

done:
    movzx eax, al ; return *s1 - *s2
    movzx edx, cl
    sub eax, edx
    ret