;assembly part using x86-64
;section .data
;a times 2 dd 0.5, 0.25
;b times 2 dd 0.265, 0.1234

section .text
bits 64
default rel
global dot_product_asm
dot_product_asm:
    xor rax, rax
    pxor xmm0, xmm0
    ;mov r8, 2
    ;mov rcx, a
    ;mov rdx, b

    loop_start:
        cmp rax, r8
        jge loop_end
        
        movss xmm1, [rcx + rax * 4]
        movss xmm2, [rdx + rax * 4]
        
        vmulss xmm3, xmm1, xmm2
        addss xmm0, xmm3
        
        inc rax
        jmp loop_start
    
    loop_end:
        
    ret