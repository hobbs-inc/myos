# === MyOS Build System ===

# Cross compiler prefix (we will install this later)
CC = x86_64-elf-gcc
LD = x86_64-elf-ld

# Directories
KERNEL_DIR = kernel
ARCH_DIR = arch/x86_64
BUILD_DIR = build

# Output files
KERNEL_ELF = $(BUILD_DIR)/kernel.elf

# Default target
all: $(KERNEL_ELF)

# Compile kernel C files
$(KERNEL_ELF): $(KERNEL_DIR)/kmain.o $(ARCH_DIR)/boot.o
    $(LD) -n -o $(KERNEL_ELF) $(ARCH_DIR)/boot.o $(KERNEL_DIR)/kmain.o

# Compile C source
$(KERNEL_DIR)/kmain.o: $(KERNEL_DIR)/kmain.c
    $(CC) -c $(KERNEL_DIR)/kmain.c -o $(KERNEL_DIR)/kmain.o -ffreestanding -O2 -Wall -Wextra

# Compile assembly source
$(ARCH_DIR)/boot.o: $(ARCH_DIR)/boot.s
    $(CC) -c $(ARCH_DIR)/boot.s -o $(ARCH_DIR)/boot.o -ffreestanding

# Clean build files
clean:
    rm -f $(KERNEL_DIR)/*.o
    rm -f $(ARCH_DIR)/*.o
    rm -f $(KERNEL_ELF)

