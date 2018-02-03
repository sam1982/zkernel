#!/bin/bash
rm -rf *.o
rm -f kernel
nasm -f elf32 kernel.asm -o kasm.o
nasm -f elf32 base.asm -o base.o
gcc -m32 -c memory.c -o memory.o
gcc -m32 -c gdt.c -o gdt.o
gcc -m32 -c display.c -o display.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o memory.o base.o display.o gdt.o
#qemu-system-i386 -kernel kernel



