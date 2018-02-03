#!/bin/bash
rm -rf *.o
rm -f kernel
for i in *.asm
do
    asm=$(echo $i | sed "s/.asm$//")
    nasm -f elf32 $i -o  ${asm}.o
done
for i in *.c
do
    c=$(echo $i | sed "s/.c$//")
    gcc -m32 -c  $i -o  ${c}.o
done
obj=$(ls *.o)
ld -m elf_i386 -T link.ld -o kernel $obj

#qemu-system-i386 -kernel kernel



