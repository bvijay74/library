// templates.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "templates.h"

bool isLittleEndian()
{
	const uint32_t x = 0x1;
	const uint8_t* bp = (uint8_t*)&x;

	if (bp[0] == 0x1)
	{
		return true;
	}

	return false;
}
