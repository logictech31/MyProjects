.section .data

.section .text
.global _start

_start:
    # Push argument in stack
    push $5
    # Call the function
    call factorial
    # Since the returned value is stored in rax we move it to rbx
    # run echo $? [for bash/zsh] or echo $status [for fish] to see the result
    mov %rax, %rbx
    # To end the program
    mov $1, %rax
    # Call interrupt 128
    int $0x80

.type factorial, @function
# factorial(value)
factorial:
    # Push the base pointer of the previous function
    push %rbp
    # Load the current stack pointer
    mov %rsp, %rbp

    # Load the argument passed i.e. 5
    mov 16(%rsp), %rax
    # If (arg == 1) then
    cmp $1, %rax
    je end_factorial
    # Else
    # --value
    dec %rax
    # Push 4 in stack
    push %rax
    # Call function again
    call factorial
    # After the value is reduced to 1
    # We load 2 into base register
    mov 16(%rbp), %rbx
    # Now we multiply 2 and 1
    # This goes on as 1*2 then 2*3 then 6*4 then 24*5
    imul %rbx, %rax
    # After the result is obtained we then get the old rbp to return to previous memory address
    # to execute necessary functions
    end_factorial:
    mov %rbp, %rsp
    pop %rbp
    ret
