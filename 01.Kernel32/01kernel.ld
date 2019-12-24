OUTPUT_FORMAT("pe-i386")
OUTPUT_ARCH(i386)
ENTRY(Main)

SECTIONS
{
  .text 0x10200 :
  {
    Main.o(.text)
    *(.text)
  } 
	
  .rdata :
  {
    *(.rdata)
  }
    . = ALIGN(512);
  .data :
  {
    *(.data)
  }

  .bss :
  {
    *(.bss)
  }
}