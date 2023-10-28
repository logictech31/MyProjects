%macro printMsg 2
mov rax, 1
mov rdi, %1 ; variable
mov rsi, %2 ; length
mov rdx, 1
%endmacro
section .data
    num db "Hello World"
    numLen equ $-num

section .text
    global _start

_start:
    printMsg num, numLen
    mov rax, 60
    mov rdi, 0
    syscall