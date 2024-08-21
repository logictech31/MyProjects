.section .data

.section .text

.globl _start
.global square_func
_start:
    push $9
    call square_func

    mov %rax, %rbx
    mov $1, %rax
    int $128

.type square_func, @function
square_func:
    push %rbp
    mov %rsp, %rbp
    mov 16(%rsp), %rax
    mov %rax, %rbx
    # Standard for returning to caller
    imul %rbx, %rax
    mov %rbp, %rsp
    pop %rbp
    ret
