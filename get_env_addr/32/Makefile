all: get_env_addr.c target.c
	gcc -m32 get_env_addr.c -o get_env_addr
	gcc -m32 -fno-stack-protector -z execstack target.c -o target && sudo chown root:root target && sudo chmod u+s target

clean:
	rm -f get_env_addr target
