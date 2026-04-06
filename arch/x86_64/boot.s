.global _start

_start:
    mov $stack_top, %rsp     # Set up stack pointer
    call kmain               # Jump into C kernel code

halt:
    hlt                      # Halt CPU
    jmp halt                 # Infinite loop

# Reserve a simple stack
.section .bss
    .align 16
stack_bottom:
    .skip 4096               # 4 KB stack
stack_top:
