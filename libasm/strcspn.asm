[bits 64]

[global asm_strcspn]

asm_strcspn:
    ; rdi - str
    ; rsi - accept
    mov rcx, rsi ; save accept pointer
    xor rax, rax ; initialize counter to 0

find_char:
    mov dl, byte [rdi]
    test dl, dl ; is *str == '\0'
    jz return_count
    
scan_string:
    mov dh, byte [rsi] ; ah = *accept
    test dh, dh ; check if end of accept string
    jz end_loop
    cmp dh, dl ; compare accept character with str character
    je return_count
    inc rsi
    jmp scan_string

end_loop:
    mov rsi, rcx ; reset rsi
    inc rax ; increment counter
    inc rdi ; move to the next character in str
    jmp find_char ; repeat for next character in str

return_count:
    ret
