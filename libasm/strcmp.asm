[bits 64]

[global asm_strcmp]

asm_strcmp:
    ; Compares two null-terminated strings.
    ; Parameters:
    ;   rdi - pointer to the first null-terminated string
    ;   rsi - pointer to the second null-terminated string
    ; Returns:
    ;   - A negative value if s1 is less than s2.
    ;   - Zero if s1 is equal to s2.
    ;   - A positive value if s1 is greater than s2.

char_cmp:
    mov al, [rdi] ; Get byte to compare
    mov cl, [rsi]
    
    test al, cl ; Test if string ended
    jz end_string

    cmp al, cl ; Check if different character
    jne end_string

    inc rdi ; Move pointer and repeat
    inc rsi
    jmp char_cmp

end_string:
    cmp al, cl
    jl less_than
    jg greater_than
    mov rax, 0
    ret 

greater_than:
    mov rax, 1
    ret

less_than:
    mov rax, -1
    ret
