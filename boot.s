/* Constants for multiboot header */
.set ALIGN,	1<<0			/* align loaded modules on page boundaries */
.set MEMINFO,	1<<1			/* provide memory map */
.set FLAGS,	ALIGN | MEMINFO		/* multiboot "flag" field */
.set MAGIC, 	0x1BADB002		/* magic number found in multiboot standard */
.set CHECKSUM,	-(MAGIC + FLAGS)	/* checksum of the above constants (also from the multiboot standard) */

/* multiboot header that marks the program as a kernel */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* 16-byte aligned stack */
.section .bss
.align 16
stack_bottom:
.skip 16384	# 16KiB
stack_top:

/* _start is the entry point of the kernel, bootloader will jump here once the kernel is loaded */
.section .text
.global _start
.type _start, @function
_start:
	/* set esp register to the top of the stack (on x86 the stack grows downwards) */
	mov $stack_top, %esp

	call kernel_main

	/* 
	put the computer in an infinite loop:
	1) disable interrupts with cli
	2) wait for the next interrupt with hlt (interrupts enabled so this will lock up the computer)
	3) jump back to hlt if for some reason it ever wakes
	*/
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
