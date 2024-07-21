.section .data
a:
    .ascii "A"
b:
    .ascii "B"

endl:
    .ascii "\n"

.section .text

.macro copy src, dest
    mov $0x00, \dest
    or \src, \dest
.endm

.macro print val, len
    mov $1, %rax
    mov $1, %rdi
    mov \val, %rsi
    mov \len, %rdx
    syscall
.endm

.macro end_prog
    mov $60, %rax
    mov $0, %rdi
    syscall
.endm

.globl _start
_start:
    print $a, 1
    print $b, 1
    print $endl, 1

    copy $a, $b
    print $a, 1
    print $b, 1

    end_prog
