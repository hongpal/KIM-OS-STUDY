/*
 * Assembly.c
 *
 *  Created on: 2019. 12. 25.
 *      Author: kim
 */

#include "Types.h"
#include "AssemblyUtility.h"

BYTE kInPortByte(WORD wPort)
{
    BYTE bData;

    __asm__ __volatile__ (
                            "mov    $0, %%rax\n"
                            "in %%dx, %%al\n"
                            :"=a"(bData)
                            :"d"(wPort)
    );

    return bData;

}

void kOutPortByte(WORD wPort, BYTE bData)
{
	   __asm__ __volatile__ (
	                            "out    %%al,   %%dx\n"
	                            :
	                            :"d"(wPort), "a"(bData)
	    );

}
