.section .data
numbers:
    .byte 0x10, 0x13, 0x01, 0x02, 0x01

say_hello:
    .ascii "Hello, World!"
    len_hello = . - say_hello

.section .text
.globl qsort
.globl partition

.macro print msg len
    mov $1, %rax
    mov $1, %rdi
    mov $say_hello, %rsi
    mov $len_hello, %rdx
    syscall
.endm

.macro loading_stack_pointer
    # Push the base pointer of the previous function
    push %rbp
    # Load the current stack pointer
    mov %rsp, %rbp
.endm

.macro returning_to_prev_fn
    mov %rbp, %rsp
    pop %rbp
.endm

.type qsort, @function
qsort:
    print
    mov %rbp, %rsi
    pop %rbp
    ret
.type partion, @function
partition:
