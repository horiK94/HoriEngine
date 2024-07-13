#pragma once
#include <cstdint>

namespace HoriEngine::Math
{
	static bool InRange(size_t val, size_t min , size_t max)
	{
		return min <= val && val < max;
	}
}