all: BootLoader Kernel32 Kernel64 Disk.img Utility

BootLoader:
	@echo === Build Boot Loader ===
	
	make -C 00.BootLoader
	
	@echo === Build Complete ===
	
Kernel32:
	@echo === Build 32bit Kernel ===
	
	make -C 01.Kernel32
	
	@echo === Build Complete ===

Kernel64:
	@echo === Build 64bit Kernel ===
	
	make -C 02.Kernel64
	
	@echo === Build Complete ===
	
Disk.img: 00.BootLoader/BootLoader.bin 01.Kernel32/Kernel32.bin 02.Kernel64/Kernel64.bin
	@echo === Disk Image Build Start ===
	
	04.Utility/00.ImageMaker/ImageMaker.exe $^
	
	@echo === All Build Complete ===

Utility:
	@echo === Utility Build Start ===
	
#	make -C 04.Utility
	
	@echo === Utility Build Complete ===
	
Clean:
	make -C 00.BootLoader clean
	make -C 01.Kernel32 clean
	make -C 02.Kernel64 clean
	#make -C 04.Utility clean
	rm -f Disk.img	