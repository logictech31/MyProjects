.section .data

.section .text
.globl _start
_start:
    push $8
    push $2
    call power
    add $8, %rsp
    push %rax
    push $3
    push $5
    call power
    add $8, %rsp
    pop %rbx
    add %rax, %rbx

    mov $1, %rax
    int $0x80

.type power, @function
power:
    push %rbp              # Save old base pointer
    mov %rsp, %rbp         # Make stack pointer the base pointer
    sub $4, %rsp           # get room for our local storage

    mov 8(%rsp), %rbx      # put the first argument in rbx
    mov 12(%rsp), %rcx     # put the second argument in rcx

    mov %rbx, -4(%rbp)     # store current result

    power_loop_start:
        cmp $1, %rcx       # if the power is 1, we are done
        je end_power
        mov -4(%rbp), %rax
        imul %rbx, %rax    # Multiply current result by base number

        mov %rax, -4(%rbp) # Store the current result

        dec %rcx
        jmp power_loop_start

    end_power:
        mov -4(%rbp), %rax # return value goes in %rax
        mov %rbp, %rsp     # restore the stack pointer
        pop %rbp           # restore the base pointer
        ret
