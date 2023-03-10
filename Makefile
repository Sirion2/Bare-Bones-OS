OBJECTS = loader.o kmain.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
			-nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -m elf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel/kernel.elf
	genisoimage -R                              		\
				-b boot/grub/stage2_eltorito		\
				-no-emul-boot                   		\
				-boot-load-size 4               		\
				-A os                           		\
				-input-charset utf8             		\
				-quiet                          		\
				-boot-info-table                		\
				-o os.iso                       		\
				iso

run: os.iso
	qemu-system-i386 		\
		-cdrom os.iso
		-boot d 			\
		-m 10				\
		-d int -D ./log.txt	\

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso