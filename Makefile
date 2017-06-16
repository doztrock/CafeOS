# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra
CLIBS=-I ./ -I lib/ -I lib/kernel/ -I lib/libc/

# Compilador Assembler
AS=as
ASFLAGS=-c

# Dependencias
DEPENDENCIAS=loader.o kmain.o

# Inclusiones
INCLUSIONES=lib/kernel/*.o		\
	    lib/kernel/*/*.o		\
	    lib/libc/*.o

# Dispositivos
DISPOSITIVOS=dispositivos/serial.o


# Regla: all
all: kernel.elf

# Regla: kernel.elf
kernel.elf: $(DEPENDENCIAS) $(DISPOSITIVOS)  libkernel libc
	$(CC) $(CFLAGS) -o kernel.elf -T link.ld $(DEPENDENCIAS) $(INCLUSIONES) $(DISPOSITIVOS)

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
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@

# Regla: Archivos .s
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Regla: run
run:
	qemu-system-i386 -cdrom cafeOS.iso

# Regla: clean
clean:
	rm -f kernel.elf cafeOS.iso
	find . -type f -name "*.o" -exec rm {} +
	find . -type f -name "*.elf" -exec rm {} +