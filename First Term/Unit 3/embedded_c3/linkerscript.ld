/* LINKER SCRIPT */
/* CORTEX-M3 */

MEMORY
{
 flash (rx) : ORIGIN = 0x08000000, LENGTH = 128M
 sram (rwx) : ORIGIN = 0x20000000, LENGTH = 20M
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