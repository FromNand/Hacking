#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//main関数には「lea 4(%esp), %ecx」といったコードが紛れ込み、バッファオーバーフローを邪魔するため、とりあえず脆弱性を持つ関数をmainから呼ぶことにした
//int func(int argc, char **argv);

//int main(int argc, char **argv){
//	return func(argc, argv);
//}

//32bit用の実行形式のmain関数には「lea 4(%esp), %ecx」といったコードが紛れ込み、バッファオーバーフローを邪魔するのだが、64bit版ではなぜかこれがない
//しかし、SSE命令のことを考えても16byteのアライメントが必要ないということはないだろうから、Cスタートアップ関数の方でアライメントが調節してあると思う
int main(int argc, char **argv){
	unsigned int i;
	unsigned char string[100];

	printf("##### ターゲットの情報 #####\n");
	printf("[実効権限修正前] uid = %u, euid = %u\n", getuid(), geteuid());
	printf("スタック領域の大まかなアドレスは %p です\n", &string);

	//実効権限を下げる
	seteuid(getuid());
	printf("[実効権限修正後] uid = %u, euid = %u\n", getuid(), geteuid());

	if(argc != 2){
		printf("文字列にコピーするための引数を一つ指定してください\n");
		exit(1);
	}

	printf("\nNop sled + Shellcode + Return Address (攻撃者から送り込まれたシェルコードの内容)");
	for(i = 0; i < 200; i++){
		if(i % 32 == 0) printf("\n%03d : ", i);
		printf("%02x ", ((unsigned char*) argv[1])[i]);
	}
	printf("\n\n");

	printf("シェルコードをコピーする前のstringの内容");
	for(i = 0; i < 200; i++){
		if(i % 32 == 0) printf("\n%03d : ", i);
		printf("%02x ", string[i]);
	}
	printf("\n\n");

	strcpy(string, argv[1]);

	printf("シェルコードをコピーした後のstringの内容");
	for(i = 0; i < 200; i++){
		if(i % 32 == 0) printf("\n%03d : ", i);
		printf("%02x ", string[i]);
	}
	printf("\n\n");

	return 0;
}
