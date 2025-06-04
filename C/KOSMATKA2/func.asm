global func

section .text
func:
    ; long a (rdi), long b (rsi), long c (rdx)
    ; if any < 0 -> return 0
    cmp rdi, 0
    jl .zero
    cmp rsi, 0
    jl .zero
    cmp rdx, 0
    jl .zero

    mov rax, rdi
    add rax, rsi
    add rax, rdx
    ret

.zero:
    xor rax, rax
    ret
