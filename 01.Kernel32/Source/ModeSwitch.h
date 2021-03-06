/*
 * ModeSwitch.h
 *
 *  Created on: 2019. 12. 24.
 *      Author: kim
 */

#ifndef _MODESWITCH_H_
#define _MODESWITCH_H_

#include "Types.h"

void kReadCPUID(DWORD dwEAX, DWORD* pdwEAX, DWORD* pdwEBX, DWORD* pdwECX, DWORD* pdwEDX);
void kSwitchAndExecute64bitKernel( void );

#endif /* 01_KERNEL32_SOURCE_MODESWITCH_H_ */
