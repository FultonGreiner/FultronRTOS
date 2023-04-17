/* set entry point to beginning of the firmware */
ENTRY(_reset);

/* define the memory regions */
MEMORY {
	flash(rx) : ORIGIN = 0x08000000, LENGTH = 512k		
	sram(rwx) : ORIGIN = 0x20000000, LENGTH = 128k
}

/* set stack pointer to end of SRAM */
_estack = ORIGIN(sram) + LENGTH(sram);

SECTIONS {
	/* store vector table in the following order: */
	.vectors  : { KEEP(*(.vectors)) }   > flash		/* 1. flash memory */
	.text     : { *(.text*) }           > flash		/* 2. firmware section */
	.rodata   : { *(.rodata*) }         > flash		/* 3. read-only data section */

	.data : {
		_sdata = .;   								/* section start */
		*(.first_data)
		/* sort sections in ascending order in output file */
			*(.data SORT(.data.*))
			_edata = .;  								/* section end */
} > sram AT > flash
_sidata = LOADADDR(.data);

.bss : {
	_sbss = .;              					/* section start */
	/* sort sections in ascending order in output file */
	*(.bss SORT(.bss.*) COMMON)
	_ebss = .;              					/* section end */
} > sram

/* insert padding bytes to align on an 8-byte boundary */
. = ALIGN(8);

_end = .;
}

