.section .text

.extern square_func
.globl _start

_start:
    push $4
    call square_func
    mov %rax, %rbx
    mov $1, %rax
    int $128
