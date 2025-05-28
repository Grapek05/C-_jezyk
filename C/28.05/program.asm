section .text
    global asm_min
    global asm_max

asm_min:
    test    esi, esi
    jle     .empty
    mov     eax, [rdi]
    xor     ecx, ecx

.loop_min:
    inc     ecx
    cmp     ecx, esi
    jge     .end_min
    mov     edx, [rdi + rcx*4]
    cmp     edx, eax
    jge     .loop_min
    mov     eax, edx
    jmp     .loop_min

.end_min:
    ret

.empty:
    xor     eax, eax
    ret


asm_max:
    test    esi, esi
    jle     .empty_max
    mov     eax, [rdi]
    xor     ecx, ecx

.loop_max:
    inc     ecx
    cmp     ecx, esi
    jge     .end_max
    mov     edx, [rdi + rcx*4]
    cmp     edx, eax
    jle     .loop_max
    mov     eax, edx
    jmp     .loop_max

.end_max:
    ret

.empty_max:
    xor     eax, eax
    ret
