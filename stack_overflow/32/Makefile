###########################
########## Macro ##########
###########################

# File name
SRC1=attack.c
EXE1=attack
SRC2=target.c
EXE2=target

# Compiler option
OP1=-m32
OP2=-m32 -fno-stack-protector -z execstack

###########################
##### Generation Rule #####
###########################

# Make quietly
.SILENT:

# Default
all: $(EXE1) $(EXE2)

# Generate code
$(EXE1): $(SRC1)
	gcc $(OP1) $(SRC1) -o $(EXE1)

# Generate code
$(EXE2): $(SRC2)
	gcc $(OP2) $(SRC2) -o $(EXE2)
	sudo chown root:root $(EXE2)
	sudo chmod u+s $(EXE2)

###########################
######### Command #########
###########################

# Execute
execute: $(EXE1) $(EXE2)
	./$(EXE1) $(ARG)

# Search offset for nop sled
search: $(EXE1) $(EXE2)
	for i in $$(seq 100 10 300); do \
		printf "\n現在の引数は %u です\n\n" $$i; \
		make execute ARG=$$i; \
	done

# Disassemble
disassemble: $(EXE1)
	objdump -d $(EXE1) | grep -A 1000 \<main\>: | less

# Debug
debug: $(EXE1) $(EXE2)
	gdb -q $(EXE1) \
	-ex 'break main' \
	-ex 'run' \
	-ex 'layout asm'

# Enable ASLR
enable:
	sudo sysctl -w kernel.randomize_va_space=2

# Disable ASLR
disable:
	sudo sysctl -w kernel.randomize_va_space=0

# Confirm ASLR setting
confirm:
	sysctl -a 2>&1 | grep randomize

# File check
check: $(EXE1) $(EXE2)
	file $(EXE1) $(EXE2)

# Clean
clean:
	rm -f $(EXE1) $(EXE2)
