NASM32 = nasm
GCC32 = gcc  -c -m32 -ffreestanding
LD32 = ld -mi386pe -T ../01Kernel.ld -nostdlib -e Main -Ttext 0x10200
OBJCOPY32 = objcopy -j .text -j .data -j .rdata -j .bss -S -O binary
# -masm=intel
OBJECTDIRECTORY = Temp
SOURCEDIRECTORY = Source

all: prepare Kernel32.bin

prepare:
	mkdir -p $(OBJECTDIRECTORY)
	
$(OBJECTDIRECTORY)/EntryPoint.bin: $(SOURCEDIRECTORY)/EntryPoint.s
	$(NASM32) -o $@ $<
	
dep:
	@echo === Make Dependancy File ===
	make -C $(OBJECTDIRECTORY) -f ../makefile InternalDependency
	@echo === Dependancy Search Complete ===
	
ExecuteInternalBuild: dep
	make -C $(OBJECTDIRECTORY) -f ../makefile Kernel32.exe
	
$(OBJECTDIRECTORY)/Kernel32.exe.bin: ExecuteInternalBuild
	$(OBJCOPY32) $(OBJECTDIRECTORY)/Kernel32.exe $@
	
Kernel32.bin: $(OBJECTDIRECTORY)/EntryPoint.bin $(OBJECTDIRECTORY)/Kernel32.exe.bin
	cat $^ > $@
		
clean:
	rm -f *.bin
	rm -f $(OBJECTDIRECTORY)/*.*
	
CENTRYPOINTOBJECTFILE = Main.o
CSOURCEFILES = $(wildcard ../$(SOURCEDIRECTORY)/*.c)
ASSEMBLYSOURCEFILES = $(wildcard ../$(SOURCEDIRECTORY)/*.asm)
COBJECTFILES = $(subst Main.o, , $(notdir $(patsubst %.c, %.o, $(CSOURCEFILES))))
ASSEMBLEYOBJECTFILES = $(notdir $(patsubst %.asm,%.o,$(ASSEMBLYSOURCEFILES)))

%.o: ../$(SOURCEDIRECTORY)/%.c
	$(GCC32) -c $<
	
%.o: ../$(SOURCEDIRECTORY)/%.asm
	$(NASM32) -f win -o $@ $<
	
InternalDependency:
	$(GCC32) -MM $(CSOURCEFILES) > Dependency.dep

Kernel32.exe: $(CENTRYPOINTOBJECTFILE) $(COBJECTFILES) $(ASSEMBLEYOBJECTFILES)
	$(LD32) -o $@ $^
		
ifeq (Dependency.dep, $(wildcard Dependency.dep))
include Dependency.dep
endif