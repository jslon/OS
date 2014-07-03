nasm -f bin bootsect.asm -o bootsect.bin
gcc -m32 -std=c99 -ffreestanding -c main.c -o main.o
gcc -m32 -std=c99 -c video.c -o video.o
gcc -m32 -std=c99 -c ports.c -o ports.o
gcc -m32 -std=c99 -masm=intel -c Interrupts.c -o interrupts.o
gcc -m32 -std=c99 -c Memoria.c -o Memoria.o
nasm -felf Interrupts.asm -o interrupts_asm.o
gcc -m32 -std=c99 -c keyboard.c -o keyboard.o
ld -m elf_i386 -e principal -Ttext 0x1000 -o kernel.o main.o ports.o video.o interrupts.o keyboard.o Memoria.o  interrupts_asm.o
objcopy -R .note -R .comment -S -O binary kernel.o kernel.bin
./makeboot.out a.img bootsect.bin kernel.bin
