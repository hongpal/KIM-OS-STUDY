NASM64 = nasm -f elf64
GCC64 = gcc  -c -m64 -ffreestanding
LD64 = ld -mi386pep -T ../02Kernel.ld -nostdlib -e Main -Ttext 0x20000
OBJCOPY64 = objcopy -j .text -j .data -j .rdata -j .bss -S -O binary
# -masm=intel
OBJECTDIRECTORY = Temp
SOURCEDIRECTORY = Source

all: prepare Kernel64.bin

prepare:
	mkdir -p $(OBJECTDIRECTORY)
	
dep:
	@echo === Make Dependancy File ===
	make -C $(OBJECTDIRECTORY) -f ../makefile InternalDependency
	@echo === Dependancy Search Complete ===
	
ExecuteInternalBuild: dep
	make -C $(OBJECTDIRECTORY) -f ../makefile Kernel64.exe
		
Kernel64.bin: ExecuteInternalBuild
	$(OBJCOPY64) $(OBJECTDIRECTORY)/Kernel64.exe $@
			
clean:
	rm -f *.bin
	rm -f $(OBJECTDIRECTORY)/*.*
	
ENTRYPOINTSOURCEFILE = ../$(SOURCEDIRECTORY)/EntryPoint.s
ENTRYPOINTOBJECTFILE = EntryPoint.o

CSOURCEFILES = $(wildcard ../$(SOURCEDIRECTORY)/*.c)
ASSEMBLYSOURCEFILES = $(wildcard ../$(SOURCEDIRECTORY)/*.asm)
COBJECTFILES = $(notdir $(patsubst %.c,%.o,$(CSOURCEFILES)))
ASSEMBLYOBJECTFILES = $(notdir $(patsubst %.asm,%.o,$(ASSEMBLYSOURCEFILES)))
	
$(ENTRYPOINTOBJECTFILE): $(ENTRYPOINTSOURCEFILE)
	$(NASM64) -o $@ $<		
	
%.o: ../$(SOURCEDIRECTORY)/%.c
	$(GCC64) -c $<
	
%.o: ../$(SOURCEDIRECTORY)/%.asm
	$(NASM64) -o $@ $<
	
InternalDependency:
	$(GCC64) -MM $(CSOURCEFILES) > Dependency.dep

Kernel64.exe: $(ENTRYPOINTOBJECTFILE) $(COBJECTFILES) $(ASSEMBLYOBJECTFILES)
	$(LD64) -o $@ $^
		
ifeq (Dependency.dep, $(wildcard Dependency.dep))
include Dependency.dep
endif