#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "./memo"

int main(int argc, char **argv){
	char *buffer, *filename;
	FILE *fp;

	if(argc != 2){
		printf("引数には./memoに入力する文字列を指定してください\n");
		exit(1);
	}

	if(!(buffer = malloc(100))){
		printf("bufferの分のメモリがmalloc出来ませんでした\n");
		exit(2);
	}
	if(!(filename = malloc(100))){
		printf("filenameの分のメモリがmalloc出来ませんでした\n");
		exit(3);
	}
	printf("buffer = %p, filename = %p\n", buffer, filename);

	strcpy(filename, FILENAME);
	strcpy(buffer, argv[1]);
	if(!(fp = fopen(filename, "a"))){
		printf("%sが開けませんでした\n", FILENAME);
		exit(4);
	}

	fwrite(buffer, strlen(buffer), 1, fp);
	printf("%s に %s という文字列を書き込みました\n", filename, buffer);

	fclose(fp);
	free(buffer);
	free(filename);

	return 0;
}
