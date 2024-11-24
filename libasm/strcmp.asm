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
    ; Get byte to compare
    mov al, [rdi]
    mov cl, [rsi]
    
    ; Test if string ended
    test al, cl 
    jz end_string

    ; Check if different character
    cmp al, cl
    jne end_string

    ; Move pointer and repeat
    inc rdi
    inc rsi
    jmp char_cmp

; TODO Optimize this part
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
