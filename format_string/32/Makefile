#.fini_arrayといった関数ポインタを格納したセクションはRELROによって書き込み不可に設定してあるので、普通は.fini_arrayを書き換えることができない。
#しかし、依然としてリターンアドレスは書き換え可能であるし、オプションに「-Wl,-z,norelro」を指定することでRELROを一部無効にすることができる。
#(ただし、静的リンクした場合はなぜかオプションなしで.fini_arrayが書き換えられる。むしろ、 -Wl,-z,relro,-z,now でRELROを有効化しようとしてもできない。)
#(はっきりとした理由はわからないが、 https://www.leviathansecurity.com/blog/aslr-protection-for-statically-linked-executables によると、静的リンクした実行ファイルではASLRもRELROも有効にできないようである。)
#実際のプログラムをハックする際にはRELROを無効にすることは難しいので、汎用性の高いリターンアドレスの書き換えを行うのが無難か。


SRC=target.c
EXE_PIE=target_pie
EXE_NOT_PIE=target_not_pie
EXE_STATIC=target_static

OP_PIE=    -m32         -Wno-format-security -z execstack -Wl,-z,norelro
OP_NOT_PIE=-m32 -no-pie -Wno-format-security -z execstack -Wl,-z,norelro
OP_STATIC= -m32 -static -Wno-format-security -z execstack -Wl,-z,relro,-z,now

all: $(EXE_PIE) $(EXE_NOT_PIE) $(EXE_STATIC)

$(EXE_PIE): $(SRC)
	gcc $(OP_PIE) $(SRC) -o $(EXE_PIE)
	sudo chown root:root $(EXE_PIE)
	sudo chmod u+s $(EXE_PIE)

$(EXE_NOT_PIE): $(SRC)
	gcc $(OP_NOT_PIE) $(SRC) -o $(EXE_NOT_PIE)
	sudo chown root:root $(EXE_NOT_PIE)
	sudo chmod u+s $(EXE_NOT_PIE)

$(EXE_STATIC): $(SRC)
	gcc $(OP_STATIC) $(SRC) -o $(EXE_STATIC)
	sudo chown root:root $(EXE_STATIC)
	sudo chmod u+s $(EXE_STATIC)

clean:
	rm -f $(EXE_PIE) $(EXE_NOT_PIE) $(EXE_STATIC)

