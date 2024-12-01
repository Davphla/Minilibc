[bits 64]

[global asm_strlen]

asm_strlen:
    ; find '\0'
    xor al, al
    mov rcx, -1
    repnz scasb

    ; get lenght and return
    not rcx
    dec rcx
    mov rax, rcx

    ret


