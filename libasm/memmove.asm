[bits 64]

[global asm_memmove]

asm_memmove:
    mov rax, rdi
    mov ecx, edx ; Nb of iteration

    cmp rdi, rsi
    ja cpy_backward ; di > si

; In case it overlap
cpy_forward:
    cld
    rep movsb
    ret

cpy_backward:
    lea rdi, [rdi + rdx - 1]
    lea rsi, [rsi + rdx - 1]
    std 
    rep movsb
    cld 
    ret
