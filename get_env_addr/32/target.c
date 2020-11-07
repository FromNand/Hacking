#include<string.h>

int func(int argc, char **argv){
	char str[8];
	strcpy(str, argv[1]);
	return 0;
}

int main(int argc, char **argv){
	return func(argc, argv);
}
