[bits 64]

[global asm_strpbrk]

asm_strpbrk:
    ; rdi - str
    ; rsi - accept
    mov rcx, rsi ; save

find_char:
    mov al, byte [rdi]
    test al, al ; is *str == '\0'
    jz return_null 
    
scan_string:
    mov ah, byte [rsi] ; dl=*accept
    inc rsi
    test ah, ah ;==0
    jz end_loop
    cmp ah, al
    je return_data
    jmp scan_string

end_loop:
    mov rsi, rcx ; put rsi to normal state
    inc rdi ; rdi++
    jmp find_char ; repeat

return_data:
    mov rax, rdi 
    ret

return_null:
    xor rax, rax
    ret
