section .text
    global asmpow

; long asmpow(long x, long n)
; rdi = x
; rsi = n
asmpow:
    ; Inicjalizacja
    mov rax, 1          ; wynik = 1
    cmp rsi, 0
    je .done

.loop:
    test rsi, 1         ; testuj, czy n jest nieparzyste
    jz .skip

    imul rax, rdi       ; wynik *= x

.skip:
    imul rdi, rdi       
    shr rsi, 1          
    jnz .loop           ; jeśli n != 0, kontynuuj

.done:
    ret
