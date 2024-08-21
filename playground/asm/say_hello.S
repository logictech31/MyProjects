.section .data
msg:
    .ascii "Hello, World!\n"
    len = . - msg

.section .text

.globl _start

_start:
    mov $1, %rax
    mov $1, %rdi
    mov $msg, %rsi
    mov $len ,%rdx
    syscall

    mov $60, %rax       # exit syscall
    xor %rdi, %rdi      # new way of returning error code
    syscall             # x86_64 way of int $0x80
