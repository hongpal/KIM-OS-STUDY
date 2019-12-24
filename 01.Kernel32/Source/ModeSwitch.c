/*
 * ModeSwitch.c
 *
 *  Created on: 2019. 12. 24.
 *      Author: kim
 */

#include "ModeSwitch.h"

void kReadCPUID(DWORD dwEAX, DWORD* pdwEAX, DWORD* pdwEBX, DWORD* pdwECX, DWORD* pdwEDX)
{
//	asm volatile("push ebx");
//	asm volatile("push esi");
//
//	asm volatile("mov eax, dword [ ebp + 8 ]");
//	asm volatile("cpuid");
//
//	asm volatile("mov esi, eax");
//	asm volatile("mov eax, dword [ ebp + 12 ]");
//	asm volatile("mov dword [ eax ], esi");
//
//	asm volatile("mov eax, dword [ ebp + 16 ]");
//	asm volatile("mov dword [ eax ], ebx");
//
//	asm volatile("mov eax, dword [ ebp + 20 ]");
//	asm volatile("mov dword [ eax ], ecx");
//
//	asm volatile("mov eax, dword [ ebp + 24 ]");
//	asm volatile("mov dword [ eax ], edx");
//
//	asm volatile("pop esi");
//	asm volatile("pop ebx");

    __asm__ __volatile__ ("cpuid"
            :"=a"(*pdwEAX), "=b"(*pdwEBX), "=c"(*pdwECX), "=d"(*pdwEDX)
            :"a"(dwEAX) );
}

void kSwitchAndExecute64bitKernel( void )
{

}
