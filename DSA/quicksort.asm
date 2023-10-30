section .text
    default rel
    extern printf
    global for
    global main

for:
    mov rbx, iarrSz
    add rax, [i]

    call printf wrt ..plt
    add rax, [i]

main:
    ; Create a stack-frame, re-aligning the stack to 16-byte alignment before calls
    push rbp

    call for
    
    pop	rbp		; Pop stack

    mov	rax,0	; Exit code 0
    ret			; Return

section .data
    iarr: db 4, 2, 1, 5, 6 ; contents of array
    iarrSz: db 5 ; size of array
    ifmt: db "%d "
    i: db 0