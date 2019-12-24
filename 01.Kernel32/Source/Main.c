/*
 * Main.c
 *
 *  Created on: 2019. 12. 23.
 *      Author: kim
 */

#include "Types.h"
#include "Page.h"
#include "ModeSwitch.h"

void kPrintString(int x, int y, const char * pcString);
BOOL KInitializeKernel64Area(void);
BOOL kIsMemoryEnough(void);

#define print kPrintString

void Main()
{
	DWORD i;
	DWORD dwEAX, dwEBX, dwECX, dwEDX;
	char vcVendorString[13] = { 0, };

	kPrintString(0, 3, "C Language Kernel Started~!!");

	kPrintString(0, 4, "Minimum Memory Size Check...................[    ]");

	KInitializeKernel64Area();

	if(kIsMemoryEnough() == FALSE)
	{
		print(45, 4, "Fail");
		print(0, 5, "Not Enough Memory~!! MINT64 OS Requires Over ""64MByte Memory~!!");
		while(1);
	}
	else
	{
		print(45, 4, "Pass");
	}

	print(0, 5, "IA-32 Kernel Area Initialize................[    ]");
	if(KInitializeKernel64Area() == FALSE)
	{
		print(45, 5, "Fail");
		print(0, 6, "Kernel Area Initialization Fail~!!");
		while(1);
	}

	print(45, 5, "Pass");

	print(0, 6, "IA-32e Page Tables Initialize...............[    ]");
	kInitializePageTables();
	print(45, 6, "Pass");

	kReadCPUID(0x00, &dwEAX, &dwEBX, &dwECX, &dwEDX);
	*(DWORD*)vcVendorString = dwEBX;
	*((DWORD*)vcVendorString + 1) = dwEDX;
	*((DWORD*)vcVendorString + 2) = dwECX;

	print(0, 7, "Processor Vendor String.....................[            ]");
	print(45, 7, vcVendorString);

	kReadCPUID(0x80000001, &dwEAX, &dwEBX, &dwECX, &dwEDX);
	print(0, 8, "64bit Mode Support check....................[    ]");

	if(dwEDX & (1 << 29))
	{
		print(45, 8, "Pass");
	}
	else
	{
		print(45, 8, "Fail");
		print(0, 9, "This processor does not support 64bit mode~!!");
		while(1);
	}

	print(0, 9, "Switch To IA-32e Mode");


	while(1);
}

void kPrintString(int x, int y, const char * pcString)
{
	CHARACTER* pstScreen = (CHARACTER*) 0xB8000;
	int i;

	pstScreen += (y * 80) + x;

	for(i = 0; pcString[i] != 0; i++)
	{
		pstScreen[i].bCharactor = pcString[i];
	}
}

BOOL KInitializeKernel64Area(void)
{
	DWORD* pdwCurrentAddress;

	pdwCurrentAddress = (DWORD*)0x100000;

	while((DWORD) pdwCurrentAddress < 0x600000)
	{
		*pdwCurrentAddress = 0x00;

		if(*pdwCurrentAddress != 0x00)
		{
			return FALSE;
		}

		pdwCurrentAddress++;
	}

	return TRUE;
}

BOOL kIsMemoryEnough()
{
	DWORD* pdwCurrentAddress;

	pdwCurrentAddress = (DWORD*)0x100000;

	while((DWORD)pdwCurrentAddress < 0x4000000)
	{
		*pdwCurrentAddress = 0x12345678;

		if(*pdwCurrentAddress != 0x12345678)
		{
			return FALSE;
		}

		pdwCurrentAddress += (0x100000 / 4);
	}

	return TRUE;
}
