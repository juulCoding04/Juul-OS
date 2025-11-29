ENTRY(_start) // _start from boot.s as entry point for the bootloader

SECTIONS {
	. = 2M // use 2M as start offset (used to be 1M need to read why this has changed?)
	.text BLOCK(4K) : ALIGN(4K) { // load multiboot header?
		*(.multiboot)
		*(.text)
	}
	
	.rodata BLOCK(4K) : ALIGN(4K) { // read only data
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K) { // read write data initialized
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K) { // read write data uninitialized and stack
		*(COMMON)
		*(.bss)
	}
}
