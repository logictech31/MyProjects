.section .data
a:
    .ascii "A"
b:
    .ascii "B"
c:
    .ascii "C"
.section .text

.macro print val, len
    mov $1, %rax
    mov $1, %rdi    # destination is stdout
    mov \val, %rsi
    mov \len, %rdx
    syscall
.endm

.globl _start

_start:
    call func_two
    print $c, $1

    # Ending program with return value 0
    mov $0, %rbx
    mov $1, %rax
    int $0x80

.type func_one, @function
func_one:
    push %rbx
    mov %rsp, %rbp
    print $a, $1
    pop %rbp
    ret

.type func_two, @function
func_two:
    push %rbp
    mov %rsp, %rbp
    call func_one
    print $b, $1
    pop %rbp
    ret
