#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEMENT_NUM (sizeof(code) / sizeof(code[0]))

// push命令はシェルコードを破壊する恐れがあるため、デフォルトでは使用しないようにする
char *code[] = {
    "	movl	%eax, %ebx", "	movl	%ebx, %ecx",  "	movl	%ecx, %edx",  "	movl	%edx, %edi",  "	movl	%edi, %esi",  "	movl	%esi, %eax",  \
    "	xorl	%eax, %ebx", "	xorl	%ebx, %ecx",  "	xorl	%ecx, %edx",  "	xorl	%edx, %edi",  "	xorl	%edi, %esi",  "	xorl	%esi, %eax",  \
    "	incl	%eax", "	incl	%ebx",  "	incl	%ecx",  "	incl	%edx",  "	incl	%edi",  "	incl	%esi",  \
    "	decl	%eax", "	decl	%ebx",  "	decl	%ecx",  "	decl	%edx",  "	decl	%edi",  "	decl	%esi",  \
    /*"	pushl	%eax", "	pushl	%ebx",  "	pushl	%ecx",  "	pushl	%edx",  "	pushl	%edi",  "	pushl	%esi",  \*/
    "	popl	%eax", "	popl	%ebx",  "	popl	%ecx",  "	popl	%edx",  "	popl	%edi",  "	popl	%esi",  \
};

int main(void){
    // 時間乱数で毎回異なるアセンブラコードが生成されるようにする
    srand((unsigned int) time(NULL));

    // アセンブラコードを標準出力する
    // ここはアセンブラへの設定
    printf(".code32\n");
    printf(".global _start\n");
    printf(".section .text\n\n");
    printf("_start:\n");

    // 実際のコード
    for(int i = 0; i < 30; i++){
        printf("%s\n", code[rand() % ELEMENT_NUM]);
    }

    return 0;
}
