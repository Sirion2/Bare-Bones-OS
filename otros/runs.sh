#!/bin/bash 

    nasm -f elf32 loader.s
     ld -T link.ld -melf_i386 loader.o -o kernel.elf

     cp kernel.elf iso/boot/  

     genisoimage -R                              \
                -b boot/grub/grub-file    \
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o os.iso                       \
                iso

qemu-system-i386 \
    -boot d -cdrom os.iso -m 20 \
    -d int -D log.txt  \