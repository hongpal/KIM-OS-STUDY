all: BootLoader Kernel32 Disk.img

BootLoader:
	@echo === Build Boot Loader ===
	
	make -C 00.BootLoader
	
	@echo === Build Complete ===
	
Kernel32:
	@echo === Build 32bit Kernel ===
	
	make -C 01.Kernel32
	
	@echo === Build Complete ===
	
Disk.img: 00.BootLoader/BootLoader.bin 01.Kernel32/Kernel32.bin
	@echo === Disk Image Build Start ===
	
	04.Utility/00.ImageMaker/ImageMaker.exe $^
	
	@echo === All Build Complete ===
	
Clean:
	make -C 00.BootLoader clean
	make -C 01.Kernel32 clean
	rm -f Disk.img	