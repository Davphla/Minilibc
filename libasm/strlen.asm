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

asm_strlen1:
    xor rax, rax

count:
    mov cl, byte [rdi] ; Load the byte from memory into AL
    test cl, cl 
    jz done
    inc rax
    jmp count

done:
    ret