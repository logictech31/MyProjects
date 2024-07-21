.section .data

.section .text
# Macros go here
.macro print val, len
    mov $1, %rax
    mov $1, %rdi
    add $64, \val
    mov \val, %rsi
    mov \len, %rdx
    syscall
.endm

# Macros end here
.globl _start
.type power, @function
_start:
    push $3
    push $3
    call power
    mov %rax, %rbx
    mov $1, %rax
    int $0x80

power:
    push %rbp
    mov %rsp, %rbp
    sub $8, %rsp
    # Getting arguments
    mov 24(%rsp), %rax
    mov 32(%rsp), %rcx
    mov %rax, %rsp

    start_power:
        cmp $1, %rcx
        je end_power
        imul %rax, %rsp
        dec %rcx
        jmp start_power

    end_power:
        mov %rsp, %rax
        mov %rbp, %rsp
        pop %rbp
        ret
