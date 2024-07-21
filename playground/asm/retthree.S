.section .data
nums:
    .long 5, 2, 2, 99, 33, 44, 4, 0
.section .text
.globl _start
_start:
    movl $0x0, %edi
    movl nums(, %edi, 4), %eax
    movl %eax, %ebx # base register gets the first number

    start_loop:
        incl %edi
        movl nums(, %edi, 4), %eax
        cmpl $0, %eax # Have we reached the end?
        je end_loop
        cmpl %ebx, %eax
        jge start_loop # Jump if value is greater
        movl %eax, %ebx # If value in ax <= bx
        jmp start_loop

end_loop:
    mov $1, %rax
    int $0x80
