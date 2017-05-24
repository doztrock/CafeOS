# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
CLIBS=-I ../libc/

# Enlazador
AR=ar
ARFLAGS=cr

# Objeto
OBJETO=kernel.a

# Librerias Kernel
KERNEL=io.o


# Regla: all
all: $(KERNEL)
	$(AR) $(ARFLAGS) $(OBJETO) $(KERNEL)

# Regla: clean
clean:
	rm -f $(OBJETO)
	find . -type f -name "*.o" -exec rm {} +

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $(CLIBS) $< -o $@