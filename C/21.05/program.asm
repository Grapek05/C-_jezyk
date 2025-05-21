section .rodata
    fmt_input db "%d", 0
    fmt_lt    db "Liczba x=%d jest mniejsza niż y=%d", 0xa, 0
    fmt_eq    db "Liczby są równe", 0xa, 0
    fmt_gt    db "Liczba x=%d jest większa niż y=%d", 0xa, 0

section .bss
    x resd 1
    y resd 1

section .text
    global main
    extern printf
    extern scanf

main:
    sub rsp, 8

    lea rdi, [rel fmt_input]
    lea rsi, [rel x]
    call scanf

    lea rdi, [rel fmt_input]
    lea rsi, [rel y]
    call scanf

    mov eax, [x]
    mov ebx, [y]

    cmp eax, ebx
    jl .mniejsze
    je .rowne
    jg .wieksze

.mniejsze:
    lea rdi, [rel fmt_lt]
    mov esi, eax
    mov edx, ebx
    xor eax, eax
    call printf
    mov eax, -1
    jmp .koniec

.rowne:
    lea rdi, [rel fmt_eq]
    xor eax, eax
    call printf
    mov eax, 0
    jmp .koniec

.wieksze:
    lea rdi, [rel fmt_gt]
    mov esi, eax
    mov edx, ebx
    xor eax, eax
    call printf
    mov eax, 1

.koniec:
    add rsp, 8
    ret
