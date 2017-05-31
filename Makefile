# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
CLIBS=-I ./ -I lib/ -I lib/kernel/ -I lib/libc/

# Compilador Assembler
AS=nasm
ASFLAGS=-f elf

# Enlazador
LD=ld
LDFLAGS=-T link.ld -melf_i386

# Dependencias
DEPENDENCIAS=loader.o kmain.o

# Inclusiones
INCLUSIONES=lib/kernel/*.o		\
	    lib/kernel/*/*.o		\
	    lib/libc/*.o

# Regla: all
all: kernel.elf

# Regla: kernel.elf
kernel.elf: $(DEPENDENCIAS) libkernel libc
	$(LD) $(LDFLAGS) $(DEPENDENCIAS) $(INCLUSIONES) -o kernel.elf

# Regla: libkernel
libkernel:
	$(MAKE) --directory=lib/kernel/

# Regla: libc
libc:
	$(MAKE) --directory=lib/libc/

# Regla: iso
iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o cafeOS.iso iso/

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) $< -o $@

# Regla: Archivos .s
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Regla: run
run: iso
	qemu-system-i386 cafeOS.iso

# Regla: clean
clean:
	rm -f kernel.elf cafeOS.iso
	find . -type f -name "*.o" -exec rm {} +
	find . -type f -name "*.a" -exec rm {} +
	find . -type f -name "*.elf" -exec rm {} +