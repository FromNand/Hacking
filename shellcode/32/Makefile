all: shellcode32.S
	as --32 shellcode32.S -o shellcode32.o
	ld -m elf_i386 shellcode32.o -o shellcode32
	sudo chown root:root shellcode32
	sudo chmod u+s shellcode32

clean:
	rm -f shellcode32.o shellcode32
