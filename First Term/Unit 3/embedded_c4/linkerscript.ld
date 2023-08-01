/* LINKER SCRIPT */
/* CORTEX-M4 */

MEMORY
{
 flash (rx) : ORIGIN = 0x00000000, LENGTH = 512M
 sram (rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}
SECTIONS
{
  
  .text :
      {
      *(.vectors*)
      *(.text)
      *(.rodata)
	_E_text = .;
      } > flash
  .data :
      {
	_S_data = .;
      *(.data)
	. = ALIGN(4);
	_E_data = .;
      } > sram AT> flash
  .bss :
      {
	_S_bss = .;
      *(.bss) *(.common)
	_E_bss = .;
	. = ALIGN(4);
	. = . + 0x1000; 
        stack_top = . ;
      } > sram
  
}