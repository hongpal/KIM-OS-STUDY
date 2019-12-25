/*
 * Main.c
 *
 *  Created on: 2019. 12. 23.
 *      Author: kim
 */

#include "Types.h"
#include "KeyBoard.h"

void kPrintString(int x, int y, const char * pcString);

#define print kPrintString

void Main()
{
	char vcTemp[2] = { 0, };
	BYTE bFlags;
	BYTE bTemp;
	int i = 0;

	kPrintString(0, 10, "Switch To IA-32e Mode Success~!!");
	kPrintString(0, 11, "IA-32e C Language Kernel Start............[Pass]");
	print(0 , 12, "Keyboard Activate...........................[    ]");

	if(kActivateKeyboard() == TRUE)
	{
		print(45, 12, "Pass");
		kChangeKeyboardLED(FALSE, FALSE, FALSE);
	}
	else
	{
		print(45, 12, "Fail");
		while(1);
	}

	while(1)
	{
		if(kIsOutputBufferFull() == TRUE)
		{
			bTemp = kGetKeyboardScanCode();

			if(kConvertScanCodeToASCIICode(bTemp, &(vcTemp[0]), &bFlags) == TRUE)
			{
				if(bFlags & KEY_FLAGS_DOWN)
				{
					print(i++, 13, vcTemp);
				}
			}

		}
	}
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
