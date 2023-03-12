extern kmain
global loader       

bits 32

KERNEL_STACK_SIZE   equ 4096               
MAGIC               equ 0x1BADB002      
FLAGS               equ 0x0            
CHECKSUM            equ -(MAGIC + FLAGS)   
                                             
section .data:

section .text:                      

    align 4                        
        dd  MAGIC             
        dd  FLAGS                    
        dd  CHECKSUM                 

    loader:                                                 
        mov     eax, 0xCAFEBABE                                 
        mov     esp, kernel_stack + KERNEL_STACK_SIZE           
        push    ebx 


    ;call setGdt:
    call kmain ; kamin means kernel main

    .loop:
        hlt
        jmp .loop     
    
section .bss:
    align 4                                 
    kernel_stack:
        resb KERNEL_STACK_SIZE
