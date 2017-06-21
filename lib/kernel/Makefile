# Compilador C
CC=i686-elf-gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra
CLIBS=-I ./ -I ../ -I ../libc/

# Librerias Kernel
KERNEL=io.o			    \
       gdt.o			    \
       idt.o			    \
       isr.o			    \
       irq.o			    \
       panico/panico.o		    \
       pantalla.o		    \
       teclado.o		    \
       temporizador.o		    \
       dispositivo/dispositivo.o


# Regla: all
all: $(KERNEL)	

# Regla: clean
clean:
	find . -type f -name "*.o" -exec rm {} +

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) -c $< -o $@