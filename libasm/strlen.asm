[bits 64]

[global strlen1]

strlen1:
    xor rax, rax

count:
    cmp byte [rdi + rax], 0
    je quit
    inc rax
    jmp count

quit:
    ret
