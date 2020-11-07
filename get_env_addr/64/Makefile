all: get_env_addr.c target.c shellcode.bin
	gcc get_env_addr.c -o get_env_addr
	gcc -g -fno-stack-protector -z execstack target.c -o target && sudo chown root:root target && sudo chmod u+s target

clean:
	rm -f get_env_addr target
