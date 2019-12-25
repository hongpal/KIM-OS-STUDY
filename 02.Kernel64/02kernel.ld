
OUTPUT_ARCH(i386:x86-64)
ENTRY(Main)

SECTIONS
{
  .text 0x20000 :
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