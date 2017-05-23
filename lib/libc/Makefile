# Compilador C
CC=gcc
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

# Enlazador
AR=ar
ARFLAGS=cr

# Objeto
OBJETO=libc.a

# Librerias LIBC
LIBC=stdio.o 	\
     stdlib.o 	\
     string.o 	\
     unistd.o


# Regla: all
all: $(LIBC)
	$(AR) $(ARFLAGS) $(OBJETO) $(LIBC)

# Regla: clean
clean:
	rm -f $(OBJETO)
	find . -type f -name "*.o" -exec rm {} +

# Regla: Archivos .c
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@