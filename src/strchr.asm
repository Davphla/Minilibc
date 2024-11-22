[bits 64]

[global strchr]

strchr:
    xor rax, rax
    
count:
    cmp byte [rdi + rax], sil
    je quit
    inc rax
    jmp count

quit:
    ret
