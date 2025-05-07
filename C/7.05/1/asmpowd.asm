section .text
    global asmpowd
asmpowd:
    test rdi, rdi
    jz .zero_case
    cmp rdi, 1
    je .one_case
    
    mov rcx, rdi
    xor r8, r8
    test rdi, rdi
    jns .positive_n
    neg rcx
    mov r8, 1
.positive_n:
    movsd xmm1, xmm0
    mov rax, 1
.loop_start:
    cmp rax, rcx
    jge .loop_end
    mulsd xmm1, xmm0
    inc rax
    jmp .loop_start
.loop_end:
    test r8, r8
    jz .not_negative
    movsd xmm0, [rel .one]
    divsd xmm0, xmm1
    ret
.not_negative:
    movsd xmm0, xmm1
    ret
.zero_case:
    movsd xmm0, [rel .one] ; Zwróć 1.0 dla n=0
    ret
.one_case:
    ret
section .rodata align=8
.one: dq 1.0