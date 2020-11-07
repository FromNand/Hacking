#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int func(int argc, char **argv){
	char str[8];

	if(argc != 2){
		printf("引数に文字列を指定してください\n");
		exit(1);
	}
	strcpy(str, argv[1]);

	printf("##### ターゲットの情報 #####\n");
	printf("バッファの先頭アドレスは %p で、nopスレッドの先頭アドレスは %p です\n\n", str, str + 40);

	return 0;
}

int main(int argc, char **argv){
	return func(argc, argv);
}
