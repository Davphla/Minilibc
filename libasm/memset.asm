[bits 64]

[global asm_memset]

asm_memset:
    ; Fills the first n bytes of the memory area pointed to by rdi with the constant byte value in al.
    ; Parameters:
    ;   rdi - Pointer to the memory area to be filled
    ;   rsi  - Constant byte value to fill the memory with
    ;   rdx - Number of bytes to be set to the value
    ; Return: pointer to the memory area
    mov al, sil
    mov ecx, edx

fill_memory:
    rep stosb
    ret