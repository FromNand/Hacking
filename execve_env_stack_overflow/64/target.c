#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define TARGET_RETURN_ADDRESS_OFFSET 36

int main(int argc, char **argv, unsigned char **envp){
	char str[8];
	printf("##### ターゲットの情報 #####\n");
	printf("[実効権限修正前] uid = %u, euid = %u\n", getuid(), geteuid());
	seteuid(getuid());
	printf("[実効権限修正後] uid = %u, euid = %u\n", getuid(), geteuid());
	printf("シェルコードが配置されているアドレス(envp[0])は %p です\n", envp[0]);
	printf("シェルコードの内容は以下のようになります\n");
	for(int i = 0; i < 43; i++) printf("%02x ", envp[0][i]);
	strcpy(str, argv[1]);
	printf("\nリターンアドレスは %lx に書き換えられます\n", *((unsigned long*) (str + TARGET_RETURN_ADDRESS_OFFSET)));
	return 0;
}
