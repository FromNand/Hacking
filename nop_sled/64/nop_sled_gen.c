#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEMENT_NUM (sizeof(code) / sizeof(code[0]))

// push命令はシェルコードを破壊する恐れがあるため、デフォルトでは使用しないようにする
char *code[] = {
    "	movq	%rax, %rbx", "	movq	%rbx, %rcx",  "	movq	%rcx, %rdx",  "	movq	%rdx, %rdi",  "	movq	%rdi, %rsi",  "	movq	%rsi, %rax",  \
    "	xorq	%rax, %rbx", "	xorq	%rbx, %rcx",  "	xorq	%rcx, %rdx",  "	xorq	%rdx, %rdi",  "	xorq	%rdi, %rsi",  "	xorq	%rsi, %rax",  \
    "	incq	%rax", "	incq	%rbx",  "	incq	%rcx",  "	incq	%rdx",  "	incq	%rdi",  "	incq	%rsi",  \
    "	decq	%rax", "	decq	%rbx",  "	decq	%rcx",  "	decq	%rdx",  "	decq	%rdi",  "	decq	%rsi",  \
    /*"	pushq	%rax", "	pushq	%rbx",  "	pushq	%rcx",  "	pushq	%rdx",  "	pushq	%rdi",  "	pushq	%rsi",  \*/
    "	popq	%rax", "	popq	%rbx",  "	popq	%rcx",  "	popq	%rdx",  "	popq	%rdi",  "	popq	%rsi",  \
};

int main(void){
    // 時間乱数で毎回異なるアセンブラコードが生成されるようにする
    srand((unsigned int) time(NULL));

    // アセンブラコードを標準出力する
    // ここはアセンブラへの設定
    printf(".code64\n");
    printf(".global _start\n");
    printf(".section .text\n\n");
    printf("_start:\n");

    // 実際のコード
    for(int i = 0; i < 15; i++){
        printf("%s\n", code[rand() % ELEMENT_NUM]);
    }

    return 0;
}
