# Project name
PROJ=privilege_shellcode_for_sh

# File name
SRC=$(PROJ).s
OBJ=$(PROJ).o
EXE=$(PROJ)
TXT=$(PROJ).txt

# Compile option
ASMOP=
LDOP=

# Don't display commands
.SILENT:

# Default
all: $(EXE) $(TXT)

# Create object files
$(OBJ): $(SRC)
	as $(ASMOP) $(SRC) -o $(OBJ)

# Create executable files
$(EXE): $(OBJ)
	ld $(LDOP) $(OBJ) -o $(EXE)
	sudo chown root:root $(EXE)
	sudo chmod u+s $(EXE)

# Text of this shellcode to embed in C language
$(TXT): $(OBJ)
	objdump -M intel -d $(OBJ) | grep '^ ' | cut -f2 | perl -pe 's/(\w{2})\s+/\\x\1/g' > $(TXT)

# Remove all executable files
clean:
	rm -f $(OBJ) $(EXE) $(TXT)
