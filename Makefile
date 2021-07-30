CC=i686-elf-gcc
LD=i686-elf-ld

FILES=./src/kernel/kernel.o

all: ./src/boot/boot.bin ./src/kernel/kernel.bin
	rm os.bin
	dd if=./src/boot/boot.bin >> os.bin
	dd if=./src/kernel/kernel.bin >> os.bin
	dd if=/dev/zero bs=512 count=100 >> os.bin

./src/boot/boot.bin: ./src/boot/boot.asm
	nasm -f bin src/boot/boot.asm -o src/boot/boot.bin

./src/kernel/kernel.bin: $(FILES)
	$(LD) -g -relocatable $(FILES) -o ./src/kernel/kernel.full.o
	$(CC) -O0 -T ./src/linker.ld -ffreestanding -nostdlib ./src/kernel/kernel.full.o -o ./src/kernel/kernel.bin

./src/kernel/kernel.o: ./src/kernel/kernel.asm
	nasm -f elf -g ./src/kernel/kernel.asm -o ./src/kernel/kernel.o

clean:
	find . -type f -name "*.o" -delete
	find . -type f -name "*.bin" -delete