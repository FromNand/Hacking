all: shellcode64.S
	as shellcode64.S -o shellcode64.o
	ld shellcode64.o -o shellcode64
	sudo chown root:root shellcode64
	sudo chmod u+s shellcode64

clean:
	rm -f shellcode64.o shellcode64
