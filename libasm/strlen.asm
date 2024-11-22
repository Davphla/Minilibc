[bits 64]

[global asm_strlen]

asm_strlen:
    xor rax, rax

count:
    cmp byte [rdi + rax], 0
    je quit
    inc rax
    jmp count

quit:
    ret
