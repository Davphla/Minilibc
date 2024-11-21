[bits 64]

[global strlen]

strlen:
    xor rax, rax

count:
    cmp byte [rdi + rax], 0
    je quit
    inc rax
    jmp count

quit:
    ret
