.section .data
num:
    .byte 0x1, 0x1, 0x2, 0xE, 0xD, 0xE, 0x1, 0xD, 0xE, 0x0

.section .text
.global _start

_start:
    mov $0x0, %edi
    #mov BEGINNINGADDRESS(,%INDEXREGISTER,WORDSIZE)
    mov num(, %edi, 4), %eax # Load the first byte of data
    mov %eax, %ebx

    start_loop:
        cmpl $0, %eax # To check if we've hit the bottom
        je end_loop
        incl %edi
        movl num(, %edi, 4), %eax
        cmpl %ebx, %eax
        jle start_loop
        movl %eax, %ebx
        jmp start_loop
end_loop:
    mov $1, %rax
    int $0x80
