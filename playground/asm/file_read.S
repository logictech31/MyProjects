# All asm directives
.equ SYS_OPEN, 5
.equ SYS_WRITE, 4
.equ SYS_READ, 3
.equ SYS_CLOSE, 6
.equ SYS_EXIT, 1
# opts for open
.equ O_RDONLY, 0
.equ 0_CREAT_WRONLY_TRUNC, 03101
# fd
.equ STDIN, 0
.equ STDOUT, 1
.equ STDERR, 2
.equ EOF, 0
.equ ARGS, 2
# stack pos
.equ ST_SIZE_RESERVE, 16
.equ ST_FD_IN, -8
.equ ST_FD_OUT, -16
.equ ST_ARGC, 0
.equ ST_ARGV_0, 8
.equ ST_ARGV_1, 16
.equ ST_ARGV_2, 24
# end asm directives

.section .data
reading:
    .ascii "Reading txt file"
    reading_len = . - reading

.section .bss
.equ BUFFER_SIZE, 512
.lcomm BUFFER_DATA, BUFFER_SIZE

.section .text
.global _start

_start:
    mov %rsp, %rbp
    sub $ST_SIZE_RESERVE, %rsp

open_files:
open_fd_in:
    # Open syscall
    mov $SYS_OPEN, %rax
    mov ST_ARGV_1(%rbp), %rbx
    # RDONLY flag
    mov $O_RDONLY, %rcx
    # Permissions
    mov $0666, %rdx
    # Call Linux
    syscall

store_fd_in:
    mov %rax, ST_FD_IN(%rbp)

open_fd_out:
    # Open file
    mov $SYS_OPEN, %rax
    # O/P filename into %rbx
    mov ST_ARGV_2(%rbp), %rbx
    # flags for writing to the file
    mov $O_CREAT_WRONLY_TRUNC, %rcx

    mov $0666, %rdx
    syscall

store_fd_out:
    mov %rax, ST_FD_OUT(%rbp)

read_loop_begin:
    mov $SYS_READ, %rax
    # Get inp fd
    mov ST_FD_IN(%rbp), %rbx
    # the loc to read into
    mov $BUFFER_DATA, %rcx
    # The size of the buffer
    mov $BUFFER_SIZE, %rdx
    syscall

    cmp $EOF, %rax
    jle end_loop

continue_read_loop:
    push $BUFFER_DATA
    push %rax

    call convert_to_upper
    pop %rax
    add $8, %rsp

    mov %rax, %rdx
    mov $SYS_WRITE, %rax
    # file to use
    mov ST_FD_OUT(%rbp), %rbx
    # loc of the buffer
    mov $BUFFER_DATA, %rcx
    syscall
    jmp read_loop_begin

end_loop:
    mov $SYS_CLOSE, %rax
    mov $ST_FD_OUT(%rbp), %rbx
    syscall
