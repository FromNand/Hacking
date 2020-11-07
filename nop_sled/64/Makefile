all: nop_sled.txt

nop_sled_gen: nop_sled_gen.c
	gcc nop_sled_gen.c -o nop_sled_gen

nop_sled.bin: nop_sled_gen
	./nop_sled_gen > nop_sled.s
	as nop_sled.s -o nop_sled.bin

nop_sled.txt: nop_sled.bin
	objdump -M intel -d nop_sled.bin | grep '^ ' | cut -f2 | perl -pe 's/(\w{2})\s+/\\x\1/g' > nop_sled.txt

clean:
	rm -f nop_sled_gen nop_sled.s nop_sled.bin nop_sled.txt
