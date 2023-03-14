OBJECTS = ./arch/i386/loader.o \
			./kernel/kmain.o \
			./arch/i386/io.o \
			./arch/i386/bstdio.o  
CC = gcc

CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		-nostartfiles -nodefaultlibs -Wall -Wextra -Werror -ffreestanding -c

LDFLAGS = -T ./arch/i386/link.ld -m elf_i386

AS = nasm

ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	mkdir ../iso/boot/kernel
	mv kernel.elf ../iso/boot/kernel/kernel.elf
	
	grub2-mkrescue -o os.iso ../iso/

	mkdir ../built
	mv os.iso ../built

run: os.iso
	qemu-system-i386			\
		-cdrom ../built/os.iso	\
		-boot d 				\
		-m 10					\
		-d int -D ./log.txt		\

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.elf 
	rm -rf *.txt 
	rm -rf kernel/*.o
	rm -rf arch/i386/*.o
	rm -rf ../iso/boot/kernel
	rm -rf ../built