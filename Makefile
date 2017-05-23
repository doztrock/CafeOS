# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

# Compilador Assembler
AS=nasm
ASFLAGS=-f elf

# Enlazador
LD=ld
LDFLAGS=-T link.ld -melf_i386

# Dependencias
DEPENDENCIAS=loader.o kmain.o		\
	     lib/libreria.o				\
	     lib/libc/libc.a 			\
	     lib/kernel/framebuffer.o


# Regla: all
all: kernel.elf libc

# Regla: kernel.elf
kernel.elf: $(DEPENDENCIAS)
	$(LD) $(LDFLAGS) $(DEPENDENCIAS) -o kernel.elf

# Regla: libc
libc:
	$(MAKE) --directory=lib/libc/

# Regla: iso
iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
                -b boot/grub/stage		    	\
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o cafeOS.iso		    		\
                iso

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Regla: Archivos .s
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Regla: clean
clean:
	rm -f kernel.elf cafeOS.iso
	find . -type f -name "*.o" -exec rm {} +