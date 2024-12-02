[bits 64]

[global asm_strstr]
[extern asm_strncmp]
[extern asm_strlen]

asm_strstr:
    ; rdi : pointer to main string (haystack) rdi, rsi, rdx, rcx, r8, r9, stack // 
    ; rsi : pointer to substring (needle)
    enter 48, 0
    
    mov qword [rbp - 16], rdi ; haystack
    mov qword [rbp - 24], rsi ; needle

    mov rdi, rsi
    call asm_strlen ; get lenght of needle for future strncmp

    test rax, rax
    jz done

    mov rsi, qword [rbp - 24]; put state back like before
    mov qword [rbp - 32], rax ; lenght of string

cmp_substr:
    mov rdi, qword [rbp - 16]
    
    mov cl, byte [rdi]
    test cl, cl
    jz done_zero

    mov rsi, qword [rbp - 24]
    mov rdx, qword [rbp - 32]
    call asm_strncmp
    test rax, rax
    jz done

    inc qword [rbp - 16]
    jmp cmp_substr

done:
    mov rax, qword [rbp - 16]
    leave
    ret

done_zero:
    xor rax, rax
    leave
    ret

