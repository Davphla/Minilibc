[bits 64]

[global asm_strstr]

asm_strstr:
    ; pointer to main string (haystack)
    ; pointer to substring (needle)
    
    ;mov eax 

cmp_substr:
    ;call asm_strncmp
    jz done 

    inc rdi
    jmp cmp_substr

done:
    mov rax, rdi
    ret

