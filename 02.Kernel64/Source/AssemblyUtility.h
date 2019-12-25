/*
 * AssemblyUtility.h
 *
 *  Created on: 2019. 12. 25.
 *      Author: kim
 */

#ifndef _ASSEMBLYUTILITY_H_
#define _ASSEMBLYUTILITY_H_

#include "Types.h"

BYTE kInPortByte(WORD wPort);
void kOutPortByte(WORD wPort, BYTE bData);

#endif /* 02_KERNEL64_SOURCE_ASSEMBLYUTILITY_H_ */
