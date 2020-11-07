#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
	if(argc != 3){
		printf("引数に実行ファイル名と環境変数名を指定してください\n");
		exit(1);
	}
	printf("%s を実行する際の %s という環境変数のアドレスは %p です\n", argv[1], argv[2], getenv(argv[2]) + (strlen(argv[0]) - strlen(argv[1])) * 2);
	return 0;
}
