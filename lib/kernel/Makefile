# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
CLIBS=-I ./ -I ../ -I ../libc/

# Librerias Kernel
KERNEL=io.o	    \
       pantalla.o


# Regla: all
all: $(KERNEL)	

# Regla: clean
clean:
	find . -type f -name "*.o" -exec rm {} +

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) $< -o $@