/*
 * Main.c
 *
 *  Created on: 2019. 12. 23.
 *      Author: kim
 */

#include "Types.h"

void kPrintString(int x, int y, const char * pcString);

#define print kPrintString

void Main()
{
	kPrintString(0, 10, "Switch To IA-32e Mode Success~!!");
	kPrintString(0, 11, "IA-32e C Language Kernel Start............[Pass]");
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
